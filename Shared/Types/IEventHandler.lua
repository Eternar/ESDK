---@interface IEventHandler
IEventHandler = interface "IEventHandler";

-- Collection that holds the event handlers
IEventHandler.Handlers = Map:New();

function IEventHandler:OnEvent(eventName, callback)
    local eventHandler <const> = AddEventHandler(eventName, callback);
    return self.Handlers:Set(eventHandler.key, eventHandler);
end

function IEventHandler:OnNetEvent(eventName, callback)
    local eventHandler <const> = RegisterNetEvent(eventName, callback);

    ---@diagnostic disable-next-line: need-check-nil
    return self.Handlers:Set(eventHandler.key, eventHandler);
end

function IEventHandler:TriggerEvent(eventName, ...)
    TriggerEvent(eventName, ...);
end

if not (IS_SERVER) then
    if (TriggerServerEvent) then
        function IEventHandler:TriggerServerEvent(eventName, ...)
            TriggerServerEvent(eventName, ...);
        end
    end
else
    if (TriggerClientEvent) then
        function IEventHandler:TriggerClientEvent(eventName, playerId, ...)
            TriggerClientEvent(eventName, playerId, ...);
        end

        function IEventHandler:TriggerGlobalEvent(eventName, ...)
            TriggerEvent(eventName, ...);
            TriggerClientEvent(eventName, -1, ...);
        end
    end
end

function IEventHandler:OffEvent(eventHandler)
    RemoveEventHandler(self.Handlers[eventHandler.key]);
    self.Handlers:Remove(eventHandler.key);
end
