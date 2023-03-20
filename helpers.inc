/* This file is a part of the Eternar SDK. */

stock bool IsValidClient(int client)
{
	if(client <= 0 || client > MaxClients) return false;
	if(!IsClientConnected(client) || IsFakeClient(client) || IsClientSourceTV(client)) return false;
  	return IsClientInGame(client);
}

stock int GetRealClientCount()
{
    int count = 0;
    for (int i = 1; i < MaxClients; i++)
    {
        if (!IsValidClient(i))
            continue;

        count++;
    }

    return count;
}

stock int GetClientFromSteamID(const char[] id)
{
	char steamid[20];

	for (int i = 1; i <= MaxClients; i++)
	{
		if(!IsValidClient(i))
			continue;

		GetClientAuthId(i, AuthId_Steam2, steamid, sizeof(steamid));

		if(strcmp(steamid, id) == 0)
			return i;
	}

	return -1;
}

stock int GetAliveClientCount()
{
    int count = 0;

    for (int i = 1; i <= MaxClients; i++)
    {
        if (IsValidClient(i) && IsPlayerAlive(i))
            count++;
    }

    return count;
}

stock int GetAliveClientCountTeam(int team)
{
    int count = 0;

    for (int i = 1; i <= MaxClients; i++)
    {
        if (IsValidClient(i) && IsPlayerAlive(i) && GetClientTeam(i) == team)
            count++;
    }

    return count;
}

stock int GetClientCountTeam(int team)
{
    int count = 0;

    for (int i = 1; i <= MaxClients; i++)
    {
        if (IsValidClient(i) && GetClientTeam(i) == team)
            count++;
    }

    return count;
}