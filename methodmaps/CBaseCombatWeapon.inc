/* This file is a part of the Eternar SDK. */

#if defined _ESDK_CBaseCombatWeapon_included_
	#endinput
#endif
#define _ESDK_CBaseCombatWeapon_included_

methodmap CBaseCombatWeapon __nullable__ < CBaseAttributableItem
{
	public CBaseCombatWeapon(int entIndex)
	{
		return view_as<CBaseCombatWeapon>(new CBaseAnimating(entIndex));	
	}

	property CBaseEntity Base
	{
		public get()
		{
			return view_as<CBaseEntity>(this);
		}
	}

	property CBaseWeaponWorldModel WorldModel
	{
		public get()
		{
			return view_as<CBaseWeaponWorldModel>(this.GetPropEnt(Prop_Send, "m_hWeaponWorldModel"));
		}
	}

	property int nViewModelIndex
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_nViewModelIndex");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_nViewModelIndex", value);
		}
	}

	property int ViewModelIndex
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_iViewModelIndex");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_iViewModelIndex", value);
		}
	}

	property int WorldModelIndex
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_iWorldModelIndex");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_iWorldModelIndex", value);
		}
	}

	property int WorldDroppedModelIndex
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_iWorldDroppedModelIndex");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_iWorldDroppedModelIndex", value);
		}
	}

	property float NextPrimaryAttack
	{
		public get()
		{
			return this.GetPropFloat(Prop_Send, "m_flNextPrimaryAttack");
		}

		public set(float value)
		{
			this.SetPropFloat(Prop_Send, "m_flNextPrimaryAttack", value);
		}
	}

	property float NextSecondaryAttack
	{
		public get()
		{
			return this.GetPropFloat(Prop_Send, "m_flNextSecondaryAttack");
		}

		public set(float value)
		{
			this.SetPropFloat(Prop_Send, "m_flNextSecondaryAttack", value);
		}
	}

	property int PrimaryAmmoType
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_iPrimaryAmmoType");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_iPrimaryAmmoType", value);
		}
	}

	property int SecondaryAmmoType
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_iSecondaryAmmoType");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_iSecondaryAmmoType", value);
		}
	}

	property int Clip1
	{
		public get()
		{
			return this.GetProp(Prop_Data, "m_iClip1");
		}

		public set(int value)
		{
			this.SetProp(Prop_Data, "m_iClip1", value);
		}
	}

	property int Clip2
	{
		public get()
		{
			return this.GetProp(Prop_Data, "m_iClip2");
		}

		public set(int value)
		{
			this.SetProp(Prop_Data, "m_iClip2", value);
		}
	}

	property int PrimaryReserveAmmoCount
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_iPrimaryReserveAmmoCount");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_iPrimaryReserveAmmoCount", value);
		}
	}

	property int SecondaryReserveAmmoCount
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_iSecondaryReserveAmmoCount");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_iSecondaryReserveAmmoCount", value);
		}
	}

	property float TimeWeaponIdle
	{
		public get()
		{
			return this.GetPropFloat(Prop_Send, "m_flTimeWeaponIdle");
		}

		public set(float value)
		{
			this.SetPropFloat(Prop_Send, "m_flTimeWeaponIdle", value);
		}
	}

	property float NextEmptySoundTime
	{
		public get()
		{
			return this.GetPropFloat(Prop_Send, "m_flNextEmptySoundTime");
		}

		public set(float value)
		{
			this.SetPropFloat(Prop_Send, "m_flNextEmptySoundTime", value);
		}
	}

	property float MinRange1
	{
		public get()
		{
			return this.GetPropFloat(Prop_Send, "m_fMinRange1");
		}

		public set(float value)
		{
			this.SetPropFloat(Prop_Send, "m_fMinRange1", value);
		}
	}

	property float MinRange2
	{
		public get()
		{
			return this.GetPropFloat(Prop_Send, "m_fMinRange2");
		}

		public set(float value)
		{
			this.SetPropFloat(Prop_Send, "m_fMinRange2", value);
		}
	}

	property float MaxRange1
	{
		public get()
		{
			return this.GetPropFloat(Prop_Send, "m_fMaxRange1");
		}

		public set(float value)
		{
			this.SetPropFloat(Prop_Send, "m_fMaxRange1", value);
		}
	}

	property float MaxRange2
	{
		public get()
		{
			return this.GetPropFloat(Prop_Send, "m_fMaxRange2");
		}

		public set(float value)
		{
			this.SetPropFloat(Prop_Send, "m_fMaxRange2", value);
		}
	}

	property float FireDuration
	{
		public get()
		{
			return this.GetPropFloat(Prop_Send, "m_fFireDuration");
		}

		public set(float value)
		{
			this.SetPropFloat(Prop_Send, "m_fFireDuration", value);
		}
	}

	/*
	property int PrimaryAmmoCount
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_iPrimaryAmmoCount");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_iPrimaryAmmoCount", value);
		}
	}

	property int SecondaryAmmoCount
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_iSecondaryAmmoCount");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_iSecondaryAmmoCount", value);
		}
	}
	*/

	property bool InReload
	{
		public get()
		{
			return view_as<bool>(this.GetProp(Prop_Send, "m_bInReload"));
		}

		public set(bool value)
		{
			this.SetProp(Prop_Send, "m_bInReload", value);
		}
	}

	property bool FireOnEmpty
	{
		public get()
		{
			return view_as<bool>(this.GetProp(Prop_Send, "m_bFireOnEmpty"));
		}

		public set(bool value)
		{
			this.SetProp(Prop_Send, "m_bFireOnEmpty", value);
		}
	}

	property bool FiresUnderwater
	{
		public get()
		{
			return view_as<bool>(this.GetProp(Prop_Send, "m_bFiresUnderwater"));
		}

		public set(bool value)
		{
			this.SetProp(Prop_Send, "m_bFiresUnderwater", value);
		}
	}

	property bool AltFiresUnderwater
	{
		public get()
		{
			return view_as<bool>(this.GetProp(Prop_Send, "m_bAltFiresUnderwater"));
		}

		public set(bool value)
		{
			this.SetProp(Prop_Send, "m_bAltFiresUnderwater", value);
		}
	}

	property bool ReloadsSingly
	{
		public get()
		{
			return view_as<bool>(this.GetProp(Prop_Send, "m_bReloadsSingly"));
		}

		public set(bool value)
		{
			this.SetProp(Prop_Send, "m_bReloadsSingly", value);
		}
	}
}