/* This file is a part of the Eternar SDK. */

#if defined _ESDK_CBasePlayer_included_
  #endinput
#endif
#define _ESDK_CBasePlayer_included_

#include <cstrike>

const CBasePlayer INVALID_PLAYER = view_as<CBasePlayer>(-1);

methodmap CBasePlayer __nullable__ < CBaseCombatCharacter
{
	public CBasePlayer(const int index)
	{
		return view_as<CBasePlayer>(index);
	}

	property CBaseEntity Base
	{
		public get()
		{
			return view_as<CBaseEntity>(this);
		}
	}

	property CBaseViewModel ViewModel
	{
		public get()
		{
			return view_as<CBaseViewModel>(this.GetPropEnt(Prop_Send, "m_hViewModel"));
		}
	}

	property int UserId
	{
		public get()
		{
			return GetClientUserId(this.Index);
		}
	}

	property int Serial
	{
		public get()
		{
			return GetClientSerial(this.Index);
		}
	}

	property bool IsConnected
	{
		public get()
		{
			return IsClientConnected(this.Index);
		}
	}

	property bool IsBot
	{
		public get()
		{
			return IsFakeClient(this.Index);
		}
	}

	property bool InGame
	{
		public get()
		{
			return IsClientInGame(this.Index);
		}
	}

	property bool IsTimingOut
	{
		public get()
		{
			return IsClientTimingOut(this.Index);
		}
	}

	property bool InKickQueue
	{
		public get()
		{
			return IsClientInKickQueue(this.Index);
		}
	}

	property bool IsAuthorized
	{
		public get()
		{
			return IsClientAuthorized(this.Index);
		}
	}

	property bool IsSourceTV
	{
		public get()
		{
			return IsClientSourceTV(this.Index);
		}
	}

	property bool IsReplay
	{
		public get()
		{
			return IsClientReplay(this.Index);
		}
	}

	property bool IsObserver
	{
		public get()
		{
			return IsClientObserver(this.Index);
		}
	}

	property bool IsValid
	{
		public get()
		{
			if (this.Index <= 0 || this.Index > MaxClients) return false;
			if (!this.IsConnected || this.IsBot || this.IsSourceTV) return false;
			return this.InGame;
		}
	}

	property int Flags
	{
		public get()
		{
			return GetEntityFlags(this.Index);
		}
	}

	property bool IsAlive
	{
		public get()
		{
			return IsPlayerAlive(this.Index);
		}
	}

	property int FlagBits
	{
		public get()
		{
			return GetUserFlagBits(this.Index);
		}
	}

	property int Team
	{
		public get()
		{
			return GetClientTeam(this.Index);
		}
		public set(int team)
		{
			ChangeClientTeam(this.Index, team);
		}
	}

	property int Health
	{
		public get()
		{
			return GetClientHealth(this.Index);
		}
		public set(int hp)
		{
			SetEntityHealth(this.Index, hp);
		}
	}

	property int Deaths
	{
		public get()
		{
			return GetClientDeaths(this.Index);
		}
	}

	property int Frags
	{
		public get()
		{
			return GetClientFrags(this.Index);
		}
	}

	property int Armor
	{
		public get()
		{
			return GetClientArmor(this.Index);
		}

		public set(int armor)
		{
			SetEntProp(this.Index, Prop_Send, "m_ArmorValue", armor);
		}
	}

	property int Helmet
	{
		public get()
		{
			return GetEntProp(this.Index, Prop_Send, "m_bHasHelmet");
		}

		public set(int helmet)
		{
			SetEntProp(this.Index, Prop_Send, "m_bHasHelmet", helmet);
		}
	}

	property int DataRate
	{
		public get()
		{
			return GetClientDataRate(this.Index);
		}
	}

	property float ConnectionTime
	{
		public get()
		{
			return GetClientTime(this.Index);
		}
	}

	property float MovementValue
	{
		public get()
		{
			return GetEntPropFloat(this.Index, Prop_Data, "m_flLaggedMovementValue");
		}

		public set(float value)
		{
			SetEntPropFloat(this.Index, Prop_Data, "m_flLaggedMovementValue", value);
		}
	}

	property int Buttons
	{
		public get()
		{
			return GetClientButtons(this.Index);
		}
	}

	property int Money
	{
		public get()
		{
			return GetEntProp(this.Index, Prop_Send, "m_iAccount");
		}

		public set(int value)
		{
			SetEntProp(this.Index, Prop_Send, "m_iAccount", value);
		}
	}

	public bool GetName(char[] name, int maxlen)
	{
		return GetClientName(this.Index, name, maxlen);
	}

	public bool GetIP(char[] ip, int maxlen, bool remport=true)
	{
		return GetClientIP(this.Index, ip, maxlen, remport);
	}

	public bool GetAuthId(AuthIdType authType, char[] auth, int maxlen, bool validate=true)
	{
		return GetClientAuthId(this.Index, authType, auth, maxlen, validate);
	}

	public char GetClanTag(char[] buffer, int maxlength)
	{
		return CS_GetClientClanTag(this.Index, buffer, maxlength);
	}

	public int GrabSteamAccountID(bool validate=true)
	{
		return GetSteamAccountID(this.Index, validate);
	}

	public bool GetInfo(const char[] key, char[] value, int maxlen)
	{
		return GetClientInfo(this.Index, key, value, maxlen);
	}

	public void SetFlagBits(int flags)
	{
	   SetUserFlagBits(this.Index, flags);
	}

	public bool CanTarget(int target)
	{
		return CanUserTarget(this.Index, target);
	}

	public bool AdminCacheCheck()
	{
		return RunAdminCacheChecks(this.Index);
	}

	public void PostAdminCheck()
	{
		NotifyPostAdminCheck(this.Index);
	}

	public void GetModel(char[] model, int maxlen)
	{
		GetClientModel(this.Index, model, maxlen);
	}

	public int GetModelSkin()
	{
		return GetEntProp(this.Index, Prop_Send, "m_nSkin");
	}

	public void GetArms(char[] output, int maxsize)
	{
		GetEntPropString(this.Index, Prop_Send, "m_szArmsModel", output, maxsize);
	}

	public void GetWeapon(char[] weapon, int maxlen)
	{
		GetClientWeapon(this.Index, weapon, maxlen);
	}

	public int GetButtons()
	{
		return GetClientButtons(this.Index);
	}

	public void GetMaxs(float vec[3])
	{
		GetClientMaxs(this.Index, vec);
	}

	public void GetMins(float vec[3])
	{
		GetClientMins(this.Index, vec);
	}

	public void GetAbsAngles(float ang[3])
	{
	   GetClientAbsAngles(this.Index, ang);
	}

	public void SetClanTag(char[] tag)
	{
		CS_SetClientClanTag(this.Index, tag);
	}

	public void GetAbsOrigin(float vec[3])
	{
		GetClientAbsOrigin(this.Index, vec);
	}

	public void GetEyeAngle(float eang[3])
	{
		GetClientEyeAngles(this.Index, eang);
	}

	public void GetEyePosition(float pos[3])
	{
		GetClientEyePosition(this.Index, pos);
	}

	public float GetLatency(NetFlow flow)
	{
		return GetClientLatency(this.Index, flow);
	}

	public float GetAvgLatency(NetFlow flow)
	{
		return GetClientAvgLatency(this.Index, flow);
	}

	public float GetAvgLoss(NetFlow flow)
	{
		return GetClientAvgLoss(this.Index, flow);
	}

	public float GetAvgChoke(NetFlow flow)
	{
		return GetClientAvgChoke(this.Index, flow);
	}

	public float GetAvgData(NetFlow flow)
	{
		return GetClientAvgData(this.Index, flow);
	}

	public float GetAvgPackets(NetFlow flow)
	{
		return GetClientAvgPackets(this.Index, flow);
	}

	public void ChangeTeam(int team)
	{
		ChangeClientTeam(this.Index, team);
	}

	public void SetModel(const char[] model)
	{
		if (!IsModelPrecached(model))
			PrecacheModel(model, true);

		SetEntityModel(this.Index, model);
	}

	public void SetModelSkin(int skin)
	{
		SetEntProp(this.Index, Prop_Send, "m_nSkin", skin);
	}

	public void SetArms(const char[] arms)
	{
		if (!IsModelPrecached(arms))
			PrecacheModel(arms, true);

		SetEntPropString(this.Index, Prop_Send, "m_szArmsModel", arms);
	}

	public void Kill()
	{
		ForcePlayerSuicide(this.Index);
	}

	public void Respawn()
	{
		CS_RespawnPlayer(this.Index);
	}

	public void SetName(char[] newname)
	{
		SetClientName(this.Index, newname);
	}

	public void Boost(float amount)
	{
		float direction[3], vel[3];
		GetEntPropVector(this.Index, Prop_Data, "m_vecVelocity", vel);
		NormalizeVector(vel, direction);
		ScaleVector(direction, amount);
		AddVectors(vel, direction, vel);
		TeleportEntity(this.Index, NULL_VECTOR, NULL_VECTOR, vel);
	}

	public void SetColor(int colors[3])
	{
		SetEntityRenderColor(this.Index, colors[0], colors[1], colors[2], 255);
	}

	public void RemoveItem(int item)
	{
		RemovePlayerItem(this.Index, item);
	}

	public int GiveItem(const char[] item)
	{
		return GivePlayerItem(this.Index, item);
	}

	public void Teleport(const float origin[3], const float angles[3], const float velocity[3])
	{
		TeleportEntity(this.Index, origin, angles, velocity);
	}

	public void SetMoveType(MoveType type)
	{
		SetEntityMoveType(this.Index, type);
	}

	public void Kick(const char[] format = "", any ...)
	{
		if (IsNullString(format))
		{
			KickClient(this.Index, "No reason given");
		} else
		{
			char message[256];
			VFormat(message, sizeof(message), format, 3);
			KickClient(this.Index, message);
		}
	}

	public bool HasPermission(const char[] cmd, int flags, bool override_only = false)
	{
		return CheckCommandAccess(this.Index, cmd, flags, override_only);
	}

	public void PrintToChat(const char[] format, any ...)
	{
		char message[526];
		VFormat(message, sizeof(message), format, 3);
		PrintToChat(this.Index, message);
	}

	public bool IsOnGround()
	{
		if (this.Flags & FL_ONGROUND)
			return true;

		return false;
	}

	public bool IsCrouching()
	{
		if (this.Flags & FL_DUCKING)
			return true;

		return false;
	}

	public void SendCommand(const char[] format, any ...)
	{
		char szBuffer[512];
		VFormat(szBuffer, sizeof(szBuffer), format, 3);

		ClientCommand(this.Index, szBuffer);
	}

	public void PlaySound(const char[] sound)
	{
		this.SendCommand("play %s", sound);
	}
};

stock bool operator<(CBasePlayer player, int integer)
{
	return player.Index < integer;
}

stock bool operator>(CBasePlayer player, int integer)
{
	return player.Index > integer;
}

stock bool operator<=(CBasePlayer player, int integer)
{
	return player.Index <= integer;
}

stock bool operator>=(CBasePlayer player, int integer)
{
	return player.Index >= integer;
}

stock bool operator==(CBasePlayer player, int integer)
{
	return player.Index == integer;
}

stock bool operator!=(CBasePlayer player, int integer)
{
	return player.Index != integer;
}

stock CBasePlayer operator+(CBasePlayer player, int integer)
{
	return new CBasePlayer(player.Index + integer);
}

stock CBasePlayer operator=(int integer)
{
	return new CBasePlayer(integer);
}

stock bool operator<(CBasePlayer p1, CBasePlayer p2)
{
	return p1.Index < p2.Index;
}

stock bool operator>(CBasePlayer p1, CBasePlayer p2)
{
	return p1.Index > p2.Index;
}

stock bool operator<=(CBasePlayer p1, CBasePlayer p2)
{
	return p1.Index <= p2.Index;
}

stock bool operator>=(CBasePlayer p1, CBasePlayer p2)
{
	return p1.Index >= p2.Index;
}

stock bool operator==(CBasePlayer p1, CBasePlayer p2)
{
	return p1.Index == p2.Index;
}

stock bool operator!=(CBasePlayer p1, CBasePlayer p2)
{
	return p1.Index != p2.Index;
}