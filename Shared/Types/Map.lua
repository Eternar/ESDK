---@class Map
Map = class "Map";

function Map:Constructor(map)
    self.Data = map or {};
end

function Map:Set(key, value)
    self.Data[key] = value;
    return value;
end

function Map:Get(key)
    return self.Data[key];
end

function Map:Remove(key)
    self.Data[key] = nil;
end

function Map:ForEach(func)
    for k, v in pairs(self.Data) do
        func(k, v);
    end
end

function Map:Contains(key)
    return self.Data[key] ~= nil;
end

function Map:Keys()
    local keys = {};
    
    for k, _ in pairs(self.Data) do
        table.insert(keys, k);
    end

    return keys;
end

function Map:Values()
    local values = {};

    for _, v in pairs(self.Data) do
        table.insert(values, v);
    end

    return values;
end

function Map:Merge(otherMap)
    for k, v in pairs(otherMap:GetRaw()) do
        self.Data[k] = v;
    end
end

function Map:Filter(func)
    local filtered = {};

    for k, v in pairs(self.Data) do
        if func(k, v) then
            filtered[k] = v;
        end
    end

    return filtered;
end

function Map:MapValues(func)
    local mapped = {};

    for k, v in pairs(self.Data) do
        mapped[k] = func(v);
    end

    return mapped;
end

function Map:Reduce(func, initial)
    local acc = initial;

    for k, v in pairs(self.Data) do
        acc = func(acc, v, k);
    end

    return acc;
end


function Map:Count()
    return #self.Data;
end

function Map:IsEmpty()
    return #self.Data == 0;
end

function Map:Clear()
    self.Data = {};
end

function Map:GetRaw()
    return self.Data;
end

--[[ cfx.re only ]]
if (IS_SERVER) then
    if (TriggerClientEvent) then
        function Map:SendToClient(eventName, playerId)
            TriggerClientEvent(eventName, playerId, self:GetRaw());
        end
    end
else
    if (TriggerServerEvent) then
        function Map:SendToServer(eventName)
            TriggerServerEvent(eventName, self:GetRaw());
        end
    end
end
