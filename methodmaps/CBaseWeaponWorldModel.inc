/* This file is a part of the Eternar SDK. */

#if defined _ESDK_CBaseWeaponWorldModel_included_
	#endinput
#endif
#define _ESDK_CBaseWeaponWorldModel_included_

methodmap CBaseWeaponWorldModel __nullable__ < CBaseAnimating
{
	public CBaseWeaponWorldModel(int entIndex)
	{
		return view_as<CBaseWeaponWorldModel>(new CBaseAnimating(entIndex));	
	}

	property CBaseEntity Base
	{
		public get()
		{
			return view_as<CBaseEntity>(this);
		}
	}

	property CBaseCombatWeapon ParentWeapon
	{
		public get()
		{
			return view_as<CBaseCombatWeapon>(this.GetPropEnt(Prop_Send, "m_hCombatWeaponParent"));
		}
	}
}