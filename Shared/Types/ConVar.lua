---@class ConVar
ConVar = class "ConVar";

ConVar.GetString = (function(varName, defaultValue)
    return GetConvar(varName, defaultValue);
end);

ConVar.GetInt = (function(varName, defaultValue)
    return GetConvarInt(varName, defaultValue);
end);
