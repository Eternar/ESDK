/* This file is a part of the Eternar SDK. */

#if defined _ESDK_CBaseCombatCharacter_included_
  #endinput
#endif
#define _ESDK_CBaseCombatCharacter_included_

methodmap CBaseCombatCharacter __nullable__ < CBaseAnimating
{
	/**
	 * Create a CBaseCombatCharacter instance from the given entity index.
	 *
	 * @param entIndex		The entity index to bind this methodmap to. Can be an invalid entity index.
	 *						You can use the CBaseEntity.IsValid property to check if the given entity is valid or not.
	*/
	public CBaseCombatCharacter(int entIndex)
	{
		return view_as<CBaseCombatCharacter>(new CBaseAnimating(entIndex));
	}

	/**
	 * Gets the active weapon of this entity instance.
	*/
	property CBaseCombatWeapon ActiveWeapon
	{
		public get()
		{
			return view_as<CBaseCombatWeapon>(this.GetPropEnt(Prop_Send, "m_hActiveWeapon"));
		}
	}

	property float NextAttack
	{
		public get()
		{
			return this.GetPropFloat(Prop_Send, "m_flNextAttack");
		}

		public set(float value)
		{
			this.SetPropFloat(Prop_Send, "m_flNextAttack", value);
		}
	}

	property int LastHitGroup
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_LastHitGroup");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_LastHitGroup", value);
		}
	}

	property int Ammo
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_iAmmo");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_iAmmo", value);
		}
	}

	property float TimeOfLastInjury
	{
		public get()
		{
			return this.GetPropFloat(Prop_Send, "m_flTimeOfLastInjury");
		}

		public set(float value)
		{
			this.SetPropFloat(Prop_Send, "m_flTimeOfLastInjury", value);
		}
	}

	property int RelativeDirectionOfLastInjury
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_nRelativeDirectionOfLastInjury");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_nRelativeDirectionOfLastInjury", value);
		}
	}

	public CBaseCombatWeapon GetWeapon(int index)
	{
		return view_as<CBaseCombatWeapon>(this.GetPropEnt(Prop_Send, "m_hMyWeapons", index));
	}
};