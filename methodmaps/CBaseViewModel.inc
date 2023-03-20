/* This file is a part of the Eternar SDK. */

#if defined _ESDK_CBaseViewModel_included_
	#endinput
#endif
#define _ESDK_CBaseViewModel_included_

methodmap CBaseViewModel __nullable__ < CBaseAnimating
{
	public CBaseViewModel(int entIndex)
	{
		return view_as<CBaseViewModel>(new CBaseAnimating(entIndex));	
	}

	property CBaseEntity Base
	{
		public get()
		{
			return view_as<CBaseEntity>(this);
		}
	}

	property CBaseCombatWeapon Weapon
	{
		public get()
		{
			return view_as<CBaseCombatWeapon>(this.GetPropEnt(Prop_Send, "m_hWeapon"));
		}
	}

	property float Cycle
	{
		public get()
		{
			return this.GetPropFloat(Prop_Data, "m_flCycle");
		}

		public set(float value)
		{
			this.SetPropFloat(Prop_Data, "m_flCycle", value);
		}
	}

	property int Sequence
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_nSequence");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_nSequence", value);
		}
	}
}