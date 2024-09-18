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
