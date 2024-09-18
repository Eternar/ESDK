---@class Server
Server = class "Server";

Server.GetHostname = (function()
    return ConVar.GetString("sv_hostname", "<unknown>");
end);

Server.GetName = (function()
    return ConVar.GetString("sv_projectName", "<unknown>");
end);

Server.GetDescription = (function()
    return ConVar.GetString("sv_projectDesc", "<unknown>");
end);

Server.GetTags = (function()
    return ConVar.GetString("tags", "default");
end);

Server.GetLocale = (function()
    return ConVar.GetString("locale", "root-AQ");
end);

Server.GetGameBuild = (function()
    return ConVar.GetInt("sv_enforceGameBuild", GAME_BUILD);
end);

Server.GetMaxPlayers = (function()
    return ConVar.GetInt("sv_maxclients", 48);
end);

Server.GetSteamAPIKey = (function()
    return ConVar.GetInt("steam_webApiKey", nil);
end);

Server.IsScriptHookAllowed = (function()
    return ConVar.GetInt("sv_scriptHookAllowed", 0) == 1;
end);

Server.IsPrivate = (function()
    return ConVar.GetString("sv_master1", "https://servers-ingress-live.fivem.net/ingress") ~= "";
end);

Server.IsLAN = (function()
    return ConVar.GetInt("sv_lan", 0) == 1;
end);

Server.IsOneSync = (function()
    return ConVar.GetString("onesync", "on") == "on";
end);

Server.GetGameName = (function()
    return GetGameNameFromBuildNumber(Server.GetGameBuild());
end);
