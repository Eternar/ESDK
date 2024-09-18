LUA_VERSION = _VERSION;

if not (LUA_VERSION:find("5.4")) then
    error("Lua 5.4 must be enabled in the resource manifest!", 2);
end

LIB_NAME = "ESDK";
IS_SERVER = IsDuplicityVersion();

local LoadFile <const> = (function(environment, fileName)
    fileName = ("%s.lua"):format(fileName);

    local chunk <const> = LoadResourceFile(LIB_NAME, ("%s/%s"):format(environment, fileName));

    if (chunk) then
        local fn <const>, err <const> = load(chunk, ("@@%s/%s/%s"):format(LIB_NAME, environment, fileName));

        if not (fn) or (err) then
            error(("Failed to import file: '@%s/%s/%s'"):format(LIB_NAME, environment, fileName));
        end

        fn();
    end
end);

local GetFiles <const> = (function(resourceName, metadata)
    local files = {};
    local libraryCount <const> = GetNumResourceMetadata(resourceName, metadata);

    for i = 1, libraryCount do
        local fileName <const> = GetResourceMetadata(resourceName, metadata, i - 1);
        table.insert(files, fileName);
    end

    return files;
end);

local Preload <const> = (function()
    -- these are loaded by default
    local init <const> = { "Enums/Game", "Enums/OperatingSystem", "Common", "Runtime", "Functions", "Console" };

    for _, file in ipairs(init) do
        LoadFile("Shared", file);
    end
end);

local LoadEnvironment <const> = (function(resourceName, environment, metadata)
    local files <const> = GetFiles(resourceName, metadata);

    for _, file in ipairs(files) do
        LoadFile(environment, file);
    end
end);

local InitializeLibrary <const> = (function()
    local environments <const> = { ["Client"] = "esdk_client", ["Server"] = "esdk_server" };
    local currentResource <const> = GetCurrentResourceName();

    -- preload lib requirements
    Preload();

    -- preload shared requirements
    LoadEnvironment(currentResource, "Shared", "esdk_shared");

    for environment, metadata in pairs(environments) do
        if not (IS_SERVER) and (environment == "Server") then
            goto CONTINUE;
        end

        LoadEnvironment(currentResource, environment, metadata);

        ::CONTINUE::
    end
end);

InitializeLibrary();
