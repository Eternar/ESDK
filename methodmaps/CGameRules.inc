/* This file is a part of the Eternar SDK. */

#if defined _ESDK_GameRules_included_
  #endinput
#endif
#define _ESDK_GameRules_included_

methodmap CGameRules < CBaseEntity
{
	/**
	 * Returns the gamerules proxy entity for this game, or INVALID_ENTITY if the entity has not been created yet.
	*/
	public static CGameRules GetEntity()
	{
		CBaseEntity gameRulesEnt = INVALID_ENTITY;

#if defined GAME_TF2
		gameRulesEnt = CEntity.FindByClassname(null, "tf_gamerules");
#elseif defined GAME_CSS || defined GAME_CSGO
		gameRulesEnt = CEntity.FindByClassname(null, "cs_gamerules");
#elseif defined GAME_DODS
		gameRulesEnt = CEntity.FindByClassname(null, "dod_gamerules");
#elseif defined GAME_HL2MP
		gameRulesEnt = CEntity.FindByClassname(null, "hl2mp_gamerules");
#elseif defined GAME_L4D || defined GAME_L4D2
		gameRulesEnt = CEntity.FindByClassname(null, "terror_gamerules");
#elseif defined GAME_DOTA
		gameRulesEnt = CEntity.FindByClassname(null, "dota_gamerules");
#else
		ThrowError("GameRules.GetEntity is not supported for this game!");
#endif

		return view_as<CGameRules>(gameRulesEnt);
	}

	/**
	 * Gets the current round state of the game.
	*/
	public static int RoundState()
	{
		return GameRules_GetProp("m_iRoundState");
	}

	/**
	 * Is the game currently in overtime?
	*/
	public static bool IsInOvertime()
	{
		return GameRules_GetProp("m_bInOvertime") == 1;
	}
	
	/**
	 * Is the game in setup?
	*/
	public static bool IsInSetup()
	{
		return GameRules_GetProp("m_bInSetup") == 1;
	}

	/**
	 * Is the game currently waiting for players to connect?
	*/
	public static bool IsInWaitingForPlayers()
	{
		return GameRules_GetProp("m_bInWaitingForPlayers") == 1;
	}

	public static bool IsWarmup()
	{
		return GameRules_GetProp("m_bWarmupPeriod") == 1;
	}
};