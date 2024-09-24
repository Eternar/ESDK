---@class Client
Client = class "Client";

Client.GetUpdateChannel = (function()
    return ConVar.GetString("ui_updateChannel", "<unknown>");
end);

Client.TogglePvP = (function(state, ped)
    NetworkSetFriendlyFireOption(state);
    SetRelationshipBetweenGroups(state and GroupRelationship.Hate or GroupRelationship.Companion, "PLAYER", "PLAYER");

    if (IS_FIVEM) and (ped) then
        SetCanAttackFriendly(ped, state, false);
    end

    Console.Log(("PvP has been %s") : format(state and "^2enabled^0" or "^1disabled^0"));
end);