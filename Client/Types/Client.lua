---@class Client
Client = class "Client";

Client.GetUpdateChannel = (function()
    return ConVar.GetString("ui_updateChannel", "<unknown>");
end);