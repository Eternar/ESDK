/* This file is a part of the Eternar SDK. */

#if defined _ESDK_CBaseAttributableItem_included_
  #endinput
#endif
#define _ESDK_CBaseAttributableItem_included_

#define WEAPON_CUSTON_NAME_LENGTH 161

methodmap CBaseAttributableItem __nullable__ < CBaseEntity
{
	/**
	 * Create a CBaseAttributableItem instance from the given entity index.
	 *
	 * @param entIndex		The entity index to bind this methodmap to. Can be an invalid entity index.
	 *						You can use the Entity.IsValid property to check if the given entity is valid or not.
	*/
	public CBaseAttributableItem(int entIndex)
	{
		return view_as<CBaseAttributableItem>(new CBaseAnimating(entIndex));
	}

	property CBaseEntity Base
	{
		public get()
		{
			return view_as<CBaseEntity>(this);
		}
	}

	/**
	 * Gets the item definition index of this econ entity.
	*/
	property int ItemIndex
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_iItemDefinitionIndex");
		}
	}

	/**
	 * Gets the item level of this econ entity.
	*/
	property int ItemLevel
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_iEntityLevel");
		}
	}

	/**
	 * Gets the item quality of this econ entity.
	*/
	property int ItemQuality
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_iEntityQuality");
		}
	}

	/**
	 * Gets the Steam Account ID of the owner of this econ entity.
	*/
	property int AccountID
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_iAccountID");
		}
	}

	property int Outer
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_hOuter");
		}
	}

	property int ProviderType
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_ProviderType");
		}
	}

	property int ReapplyProvisionParity
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_iReapplyProvisionParity");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_iReapplyProvisionParity", value);
		}
	}

	property int ItemIDHigh
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_iItemIDHigh");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_iItemIDHigh", value);
		}
	}

	property int ItemIDLow
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_iItemIDLow");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_iItemIDLow", value);
		}
	}

	property bool Initialized
	{
		public get()
		{
			return view_as<bool>(this.GetProp(Prop_Send, "m_bInitialized"));
		}
	}

	property int OriginalOwnerXuidLow
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_OriginalOwnerXuidLow");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_OriginalOwnerXuidLow", value);
		}
	}

	property int OriginalOwnerXuidHigh
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_OriginalOwnerXuidHigh");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_OriginalOwnerXuidHigh", value);
		}
	}

	property int FallbackPaintKit
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_nFallbackPaintKit");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_nFallbackPaintKit", value);
		}
	}

	property int FallbackSeed
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_nFallbackSeed");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_nFallbackSeed", value);
		}
	}

	property int FallbackStatTrak
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_nFallbackStatTrak");
		}

		public set(int value)
		{
			this.SetProp(Prop_Send, "m_nFallbackStatTrak", value);
		}
	}

	property float FallbackWear
	{
		public get()
		{
			return this.GetPropFloat(Prop_Send, "m_flFallbackWear");
		}

		public set(float value)
		{
			this.SetPropFloat(Prop_Send, "m_flFallbackWear", value);
		}
	}

	public int GetCustomName(char[] output, int maxlength)
	{
		return this.GetPropString(Prop_Send, "m_szCustomName", output, maxlength);
	}

	public int SetCustomName(const char[] output)
	{
		return this.SetPropString(Prop_Send, "m_szCustomName", output);
	}
};

methodmap CEconEntity __nullable__ < CBaseAttributableItem {};