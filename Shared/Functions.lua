---@diagnostic disable-next-line: lowercase-global
class = (function(className, ...)
    local newClass = {};
    newClass.__index = newClass;

    local baseClasses = { ... };

    setmetatable(newClass, {
        __index = function(_, key)
            for _, parent in ipairs(baseClasses) do
                if type(parent) == "string" then
                    parent = _G[parent];
                end

                if (parent) then
                    if parent[key] then
                        return parent[key];
                    end
                end
            end
        end
    });

    -- Copy methods from parents to the class directly
    for _, parent in ipairs(baseClasses) do
        if type(parent) == "string" then
            parent = _G[parent];
        end

        if parent then
            for key, value in pairs(parent) do
                if key ~= "__index" then -- Avoid copying the metatable
                    newClass[key] = value;
                end
            end
        end
    end

    -- Default constructor
    function newClass:New(...)
        local obj = {};
        setmetatable(obj, newClass);

        if (obj.Constructor) then
            obj:Constructor(...);
        end

        return obj;
    end

    -- Default destructor
    function newClass:__gc(obj)
        if (obj) and (obj.Destructor) then
            obj.Destructor();
        end
    end

    if (className) then
        _G[className] = newClass;
    end

    return newClass;
end);

---@diagnostic disable-next-line: lowercase-global
interface = (function(interfaceName, ...)
    return class(interfaceName, ...);
end);

---@diagnostic disable-next-line: lowercase-global
extends = (function(className, ...)
    return class(className, ...);
end);

---@diagnostic disable-next-line: lowercase-global
implements = (function(className, ...)
    return extends(className, ...);
end);

DefineInterfaceMethod = (function(interface, method, ...)
    if not (_G[interface]) then
        error(("Exception: interface %s does not exists."):format(interface));
    end

    _G[interface][method] = function(...)
        error(("Exception: %s::%s method is not implemented."):format(interface, method));
    end
end);
