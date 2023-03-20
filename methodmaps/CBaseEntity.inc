/* This file is a part of the Eternar SDK. */

#if defined _ESDK_CBaseEntity_included_
  #endinput
#endif
#define _ESDK_CBaseEntity_included_

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/const.h#L235-L245
enum SolidType_t
{
	SOLID_NONE = 0,	// no solid model
	SOLID_BSP = 1,	// a BSP tree
	SOLID_BBOX = 2,	// an AABB
	SOLID_OBB = 3,	// an OBB (not implemented yet)
	SOLID_OBB_YAW = 4,	// an OBB, constrained so that it can only yaw
	SOLID_CUSTOM = 5,	// Always call into the entity for tests
	SOLID_VPHYSICS = 6,	// solid vphysics object, get vcollide from the model and collide with that
	SOLID_LAST,
};

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/const.h#L247-L262
enum SolidFlags_t
{
	FSOLID_CUSTOMRAYTEST		= 0x0001,	// Ignore solid type + always call into the entity for ray tests
	FSOLID_CUSTOMBOXTEST		= 0x0002,	// Ignore solid type + always call into the entity for swept box tests
	FSOLID_NOT_SOLID			= 0x0004,	// Are we currently not solid?
	FSOLID_TRIGGER				= 0x0008,	// This is something may be collideable but fires touch functions
											// even when it's not collideable (when the FSOLID_NOT_SOLID flag is set)
	FSOLID_NOT_STANDABLE		= 0x0010,	// You can't stand on this
	FSOLID_VOLUME_CONTENTS		= 0x0020,	// Contains volumetric contents (like water)
	FSOLID_FORCE_WORLD_ALIGNED	= 0x0040,	// Forces the collision rep to be world-aligned even if it's SOLID_BSP or SOLID_VPHYSICS
	FSOLID_USE_TRIGGER_BOUNDS	= 0x0080,	// Uses a special trigger bounds separate from the normal OBB
	FSOLID_ROOT_PARENT_ALIGNED	= 0x0100,	// Collisions are defined in root parent's local coordinate space
	FSOLID_TRIGGER_TOUCH_DEBRIS	= 0x0200,	// This trigger will touch debris objects

	FSOLID_MAX_BITS	= 10
};

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/const.h#L213-L226
enum MoveCollide_t
{
	MOVECOLLIDE_DEFAULT = 0,

	// These ones only work for MOVETYPE_FLY + MOVETYPE_FLYGRAVITY
	MOVECOLLIDE_FLY_BOUNCE,	// bounces, reflects, based on elasticity of surface and object - applies friction (adjust velocity)
	MOVECOLLIDE_FLY_CUSTOM,	// Touch() will modify the velocity however it likes
	MOVECOLLIDE_FLY_SLIDE,  // slides along surfaces (no bounce) - applies friciton (adjusts velocity)

	MOVECOLLIDE_COUNT,		// Number of different movecollides

	// When adding new movecollide types, make sure this is correct
	MOVECOLLIDE_MAX_BITS = 3
};

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/const.h#L397-L423
enum Collision_Group_t
{
	COLLISION_GROUP_NONE  = 0,
	COLLISION_GROUP_DEBRIS,			// Collides with nothing but world and static stuff
	COLLISION_GROUP_DEBRIS_TRIGGER, // Same as debris, but hits triggers
	COLLISION_GROUP_INTERACTIVE_DEBRIS,	// Collides with everything except other interactive debris or debris
	COLLISION_GROUP_INTERACTIVE,	// Collides with everything except interactive debris or debris
	COLLISION_GROUP_PLAYER,
	COLLISION_GROUP_BREAKABLE_GLASS,
	COLLISION_GROUP_VEHICLE,
	COLLISION_GROUP_PLAYER_MOVEMENT,  // For HL2, same as Collision_Group_Player, for
										// TF2, this filters out other players and CBaseObjects
	COLLISION_GROUP_NPC,			// Generic NPC group
	COLLISION_GROUP_IN_VEHICLE,		// for any entity inside a vehicle
	COLLISION_GROUP_WEAPON,			// for any weapons that need collision detection
	COLLISION_GROUP_VEHICLE_CLIP,	// vehicle clip brush to restrict vehicle movement
	COLLISION_GROUP_PROJECTILE,		// Projectiles!
	COLLISION_GROUP_DOOR_BLOCKER,	// Blocks entities not permitted to get near moving doors
	COLLISION_GROUP_PASSABLE_DOOR,	// Doors that the player shouldn't collide with
	COLLISION_GROUP_DISSOLVING,		// Things that are dissolving are in this group
	COLLISION_GROUP_PUSHAWAY,		// Nonsolid on client and server, pushaway in player code

	COLLISION_GROUP_NPC_ACTOR,		// Used so NPCs in scripts ignore the player.
	COLLISION_GROUP_NPC_SCRIPTED,	// USed for NPCs in scripts that should not collide with each other

	LAST_SHARED_COLLISION_GROUP
};

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/const.h#L281-L298
enum Entity_Effects_t
{
	EF_BONEMERGE			= 0x001,	// Performs bone merge on client side
	EF_BRIGHTLIGHT 			= 0x002,	// DLIGHT centered at entity origin
	EF_DIMLIGHT 			= 0x004,	// player flashlight
	EF_NOINTERP				= 0x008,	// don't interpolate the next frame
	EF_NOSHADOW				= 0x010,	// Don't cast no shadow
	EF_NODRAW				= 0x020,	// don't draw entity
	EF_NORECEIVESHADOW		= 0x040,	// Don't receive no shadow
	EF_BONEMERGE_FASTCULL	= 0x080,	// For use with EF_BONEMERGE. If this is set, then it places this ent's origin at its
										// parent and uses the parent's bbox + the max extents of the aiment.
										// Otherwise, it sets up the parent's bones every frame to figure out where to place
										// the aiment, which is inefficient because it'll setup the parent's bones even if
										// the parent is not in the PVS.
	EF_ITEM_BLINK			= 0x100,	// blink an item so that the user notices it.
	EF_PARENT_ANIMATES		= 0x200,	// always assume that the parent entity is animating
	EF_MAX_BITS = 10
};

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/const.h#L350-L365
enum RenderMode_t
{	
	kRenderNormal = 0,		// src
	kRenderTransColor,		// c*a+dest*(1-a)
	kRenderTransTexture,	// src*a+dest*(1-a)
	kRenderGlow,			// src*a+dest -- No Z buffer checks -- Fixed size in screen space
	kRenderTransAlpha,		// src*srca+dest*(1-srca)
	kRenderTransAdd,		// src*a+dest
	kRenderEnvironmental,	// not drawn, used for environmental effects
	kRenderTransAddFrameBlend, // use a fractional frame value to blend between animation frames
	kRenderTransAlphaAdd,	// src + dest*(1-a)
	kRenderWorldGlow,		// Same as kRenderGlow but not fixed size in screen space
	kRenderNone,			// Don't render.

	kRenderModeCount,		// must be last
};

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/const.h#L367-L395
enum RenderFx_t
{	
	kRenderFxNone = 0, 
	kRenderFxPulseSlow, 
	kRenderFxPulseFast, 
	kRenderFxPulseSlowWide, 
	kRenderFxPulseFastWide, 
	kRenderFxFadeSlow, 
	kRenderFxFadeFast, 
	kRenderFxSolidSlow, 
	kRenderFxSolidFast, 	   
	kRenderFxStrobeSlow, 
	kRenderFxStrobeFast, 
	kRenderFxStrobeFaster, 
	kRenderFxFlickerSlow, 
	kRenderFxFlickerFast,
	kRenderFxNoDissipation,
	kRenderFxDistort,			// Distort/scale/translate flicker
	kRenderFxHologram,			// kRenderFxDistort + distance fade
	kRenderFxExplode,			// Scale up really big!
	kRenderFxGlowShell,			// Glowing Shell
	kRenderFxClampMinScale,		// Keep this sprite from getting very small (SPRITES only!)
	kRenderFxEnvRain,			// for environmental rendermode, make rain
	kRenderFxEnvSnow,			//  "        "            "    , make snow
	kRenderFxSpotlight,			// TEST CODE for experimental spotlight
	kRenderFxRagdoll,			// HACKHACK: TEST CODE for signalling death of a ragdoll character
	kRenderFxPulseFastWider,
	kRenderFxMax
};

const CBaseEntity INVALID_ENTITY = view_as<CBaseEntity>(INVALID_ENT_REFERENCE);

/* Entity wrapper */
methodmap CBaseEntity __nullable__
{
	/*
	 *	Initialize a new entity
	 */
	public CBaseEntity(const char[] classname)
	{
		return view_as<CBaseEntity>(CreateEntityByName(classname));
	}

	/*
	 * Get entity index
	 */
	property int Index
	{
		public get()
		{
			return view_as<int>(this);
		}
	}

	/*
	 * Get entity reference
	 */
	property int Reference
	{
		public get()
		{
			return EntIndexToEntRef(this.Index);
		}
	}

	/*
	* Checks whether this entity is valid or not.
	*/
	property bool IsValid
	{
		public get()
		{
			return this != INVALID_ENTITY && IsValidEntity(this.Index) && IsValidEdict(this.Index);
		}
	}

	/**
	 * Returns an integer sendprop or datamap value.
	 *
	 * @param propType		The property type.
	 * @param propName		The name of the property to get.
	 * @param size			The size of the integer property. This parameter is only used if size detection fails.
	 * @param element		The element into the array to get, if this property is an array.
	*/
	public int GetProp(PropType propType, const char[] propName, int size = 4, int element = 0)
	{
		return GetEntProp(this.Index, propType, propName, size, element);
	}

	/**
	 * Returns a floating point sendprop or datamap value.
	 *
	 * @param propType		The property type.
	 * @param propName		The name of the property to get.
	 * @param element		The element into the array to get, if this property is an array.
	*/
	public float GetPropFloat(PropType propType, const char[] propName, int element = 0)
	{
		return GetEntPropFloat(this.Index, propType, propName, element);
	}

	/**
	 * Returns an entity sendprop or datamap value.
	 *
	 * @param propType		The property type.
	 * @param propName		The name of the property to get.
	 * @param element		The element into the array to get, if this property is an array.
	*/
	public CBaseEntity GetPropEnt(PropType propType, const char[] propName, int element = 0)
	{
		int entIndex = GetEntPropEnt(this.Index, propType, propName, element);
		return view_as<CBaseEntity>(entIndex);
	}

	/**
	 * Returns a float vector sendprop or datamap value.
	 *
	 * @param propType		The property type.
	 * @param propName		The name of the property to get.
	 * @param vec			The vector buffer to store the value in.
	 * @param element		The element into the array to get, if this property is an array.
	*/
	public void GetPropVector(PropType propType, const char[] propName, float vec[3], int element = 0)
	{
		GetEntPropVector(this.Index, propType, propName, vec, element);
	}

	/**
	 * Returns a string sendprop or datamap value.
	 *
	 * @param propType		The property type.
	 * @param propName		The name of the property to get.
	 * @param buffer		The character buffer to store the value in.
	 * @param maxBuffer		The maximum size of the passed in character buffer.
	 * @param element		The element into the array to get, if this property is an array.
	 *
	 * @return	The number of non-null bytes written into the character buffer.
	*/
	public int GetPropString(PropType propType, const char[] propName, char[] buffer, int maxBuffer, int element = 0)
	{
		return GetEntPropString(this.Index, propType, propName, buffer, maxBuffer, element);
	}

	/**
	 * Sets an integer sendprop or datamap value.
	 *
	 * @param propType		The property type.
	 * @param propName		The name of the property to set.
	 * @param value			The value to set.
	 * @param size			The size of the integer property. This parameter is only used if size detection fails.
	 * @param element		The element into the array to set, if this property is an array.
	*/
	public void SetProp(PropType propType, const char[] propName, int value, int size = 4, int element = 0)
	{
		SetEntProp(this.Index, propType, propName, value, size, element);
	}

	/**
	 * Sets a floating point sendprop or datamap value.
	 *
	 * @param propType		The property type.
	 * @param propName		The name of the property to set.
	 * @param value			The value to set.
	 * @param element		The element into the array to set, if this property is an array.
	*/
	public void SetPropFloat(PropType propType, const char[] propName, float value, int element = 0)
	{
		SetEntPropFloat(this.Index, propType, propName, value, element);
	}

	/**
	 * Sets an entity sendprop or datamap value.
	 *
	 * @param propType		The property type.
	 * @param propName		The name of the property to set.
	 * @param value			The entity to set.
	 * @param element		The element into the array to set, if this property is an array.
	*/
	public void SetPropEnt(PropType propType, const char[] propName, CBaseEntity value, int element = 0)
	{
		SetEntPropEnt(this.Index, propType, propName, value.Index, element);
	}

	/**
	 * Sets a float vector sendprop or datamap value.
	 *
	 * @param propType		The property type.
	 * @param propName		The name of the property to set.
	 * @param vec			The vector buffer value to set.
	 * @param element		The element into the array to set, if this property is an array.
	*/
	public void SetPropVector(PropType propType, const char[] propName, const float vec[3], int element = 0)
	{
		SetEntPropVector(this.Index, propType, propName, vec, element);
	}

	/**
	 * Sets a string sendprop or datamap value.
	 *
	 * @param propType		The property type.
	 * @param propName		The name of the property to get.
	 * @param buffer		The character buffer value to set.
	 *
	 * @return	The number of non-null bytes written into the sendprop or datamap.
	*/
	public int SetPropString(PropType propType, const char[] propName, const char[] buffer)
	{
		return SetEntPropString(this.Index, propType, propName, buffer);
	}

	/*
	 * Entity owner index
	 */
	property CBaseEntity Owner
	{
		public get()
		{
			return view_as<CBaseEntity>(this.GetPropEnt(Prop_Send, "m_hOwnerEntity"));
		}

		public set(CBaseEntity owner)
		{
			this.SetPropEnt(Prop_Send, "m_hOwnerEntity", owner);
		}
	}

	property float LastMadeNoiseTime
	{
		public get()
		{
			return this.GetPropFloat(Prop_Send, "m_flLastMadeNoiseTime");
		}

		public set(float value)
		{
			this.SetPropFloat(Prop_Send, "m_flLastMadeNoiseTime", value);
		}
	}

	/**
	 * Gets or sets this entity's health.
	*/
	property int Health
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_iHealth");
		}

		public set(int health)
		{
			this.SetProp(Prop_Send, "m_iHealth", health);
		}
	}

	/**
	 * Gets or sets this entity's gravity.
	*/
	property float Gravity
	{
		public get()
		{
			return GetEntityGravity(this.Index);
		}

		public set(float gravity)
		{
			SetEntityGravity(this.Index, gravity);
		}
	}

	/**
	 * Gets or sets this entity's solid type.
	*/
	property SolidType_t SolidType
	{
		public get()
		{
			return view_as<SolidType_t>(this.GetProp(Prop_Send, "m_nSolidType"));
		}

		public set(SolidType_t solidType)
		{
			this.SetProp(Prop_Send, "m_nSolidType", view_as<int>(solidType));
		}
	}
	
	/**
	 * Gets or sets this entity's solid flags.
	*/
	property SolidFlags_t SolidFlags
	{
		public get()
		{
			return view_as<SolidFlags_t>(this.GetProp(Prop_Send, "m_usSolidFlags"));
		}

		public set(SolidFlags_t solidFlags)
		{
			this.SetProp(Prop_Send, "m_usSolidFlags", view_as<int>(solidFlags));
		}
	}

	property int ModelIndex
	{
		public get()
		{
			return this.GetProp(Prop_Send, "m_nModelIndex");
		}

		public set(int model)
		{
			this.SetProp(Prop_Send, "m_nModelIndex", model);
		}
	}

	/**
	 * Gets the vector origin of the entity in local space (relative to the parent).
	 *
	 * @param vec		The vector buffer to store the entity origin in.
	*/
	public void GetLocalOrigin(float vec[3])
	{
		this.GetPropVector(Prop_Send, "m_vecOrigin", vec);
	}

	/**
	 * Sets the vector origin of the entity in local space (relative to the parent).
	 *
	 * @param vec		The vector buffer to set the origin to.
	*/
	public void SetLocalOrigin(const float vec[3])
	{
		this.SetPropVector(Prop_Send, "m_vecOrigin", vec);
	}

	/**
	 * Gets the vector angles of the entity in local space (relative to the parent).
	 *
	 * @param ang		The angle buffer to store the entity angles in.
	*/
	public void GetLocalAngles(float ang[3])
	{
		this.GetPropVector(Prop_Send, "m_angRotation", ang);
	}

	/**
	 * Sets the vector angles of the entity in local space (relative to the parent).
	 *
	 * @param ang		The angle buffer to set the angles to.
	*/
	public void SetLocalAngles(const float ang[3])
	{
		this.SetPropVector(Prop_Send, "m_angRotation", ang);
	}

	/**
	 * Gets the vector origin of the entity in world space.
	 *
	 * @param vec		The vector buffer to store the entity origin in.
	*/
	public void GetAbsOrigin(float vec[3])
	{
		this.GetPropVector(Prop_Data, "m_vecAbsOrigin", vec);
	}

	/**
	 * Sets the vector origin of the entity in world space.
	 *
	 * @param vec		The vector buffer to set the origin to.
	*/
	public void SetAbsOrigin(const float vec[3])
	{
		this.SetPropVector(Prop_Data, "m_vecAbsOrigin", vec);
	}

	/**
	 * Gets the vector angles of the entity in world space.
	 *
	 * @param ang		The angle buffer to store the entity angles in.
	*/
	public void GetAbsAngles(float ang[3])
	{
		this.GetPropVector(Prop_Data, "m_angAbsRotation", ang);
	}

	/**
	 * Sets the vector angles of the entity in world space.
	 *
	 * @param ang		The angle buffer to set the angles to.
	*/
	public void SetAbsAngles(const float ang[3])
	{
		this.SetPropVector(Prop_Data, "m_angAbsRotation", ang);
	}

	/**
	 * Gets the vector instantaneous velocity of this entity.
	 *
	 * @param vec		The vector buffer to store the velocity in.
	*/
	public void GetVelocity(float vec[3])
	{
		this.GetPropVector(Prop_Data, "m_vecVelocity", vec);
	}

	/**
	 * Gets the OBB minimum extent of this entity's collision prop.
	 *
	 * @param vec		Vector buffer to store the result in.
	*/
	public void GetMins(float vec[3])
	{
		this.GetPropVector(Prop_Send, "m_vecMins", vec);
	}

	/**
	 * Gets the OBB maximum extent of this entity's collision prop.
	 *
	 * @param vec		Vector buffer to store the result in.
	*/
	public void GetMaxs(float vec[3])
	{
		this.GetPropVector(Prop_Send, "m_vecMaxs", vec);
	}

	/**
	 * Gets the current entity flags from this entity instance.
	 *
	 * @return	The current entity flags.
	*/
	public int GetFlags()
	{
		return GetEntityFlags(this.Index);
	}

	/**
	 * Sets the given entity flags on this entity instance.
	 *
	 * @param	The entity flags to set.
	*/
	public void SetFlags(int flags)
	{
		SetEntityFlags(this.Index, flags);
	}

	/**
	 * Adds the given entity flags to this entity instance.
	 *
	 * @param flags		The entity flags to add.
	*/
	public void AddFlag(int flags)
	{
		this.SetFlags(this.GetFlags() | flags);
	}
	/**
	 * Removes the given entity flags from this entity instance.
	 *
	 * @param flagsToRemove		The entity flags to remove.
	*/
	public void RemoveFlag(int flagsToRemove)
	{
		this.SetFlags(this.GetFlags() & ~flagsToRemove);
	}
	/**
	 * Clears the entity flags of this entity instance.
	*/
	public void ClearFlags()
	{
		this.SetFlags(0);
	}
	/**
	 * Toggles the given entity flag on this entity instance.
	 *
	 * @param flagToToggle		The entity flag to toggle.
	*/
	public void ToggleFlag(int flagToToggle)
	{
		this.SetFlags(this.GetFlags() ^ flagToToggle);
	}

	/*
	 * Teleport entity to position
	 */
	public void Teleport(const float origin[3] = NULL_VECTOR, const float angles[3] = NULL_VECTOR, const float velocity[3] = NULL_VECTOR)
	{
		TeleportEntity(this.Index, origin, angles, velocity);
	}

	/*
	 * Set entity owner index
	 */
	public void SetOwner(CBaseEntity entity)
	{
		this.SetPropEnt(Prop_Send, "m_hOwnerEntity", entity);
	}

	/*
	 * Get entity owner index
	 */
	public CBaseEntity GetOwner()
	{
		return view_as<CBaseEntity>(this.GetPropEnt(Prop_Send, "m_hOwnerEntity"));
	}

	/**
	 * Gets this entity's classname.
	 *
	 * @param classname		Buffer in which to store this entity's classname.
	 * @param maxClassname	The maximum length of the output buffer.
	 *
	 * @return		A boolean value indicating if the classname was successfully retrieved.
	*/
	public bool GetClassName(char[] classname, int maxClassname)
	{
		return GetEntityClassname(this.Index, classname, maxClassname);
	}

	public int GetName(char[] output, int maxlength)
	{
		return this.GetPropString(Prop_Data, "m_iName", output, maxlength);
	}

	public int SetName(const char[] name)
	{
		return this.SetPropString(Prop_Data, "m_iName", name);
	}

	/*
	 * Set entity model
	 */
	public void SetModel(const char[] path)
	{
		if (!IsModelPrecached(path))
			PrecacheModel(path, true);

		SetEntityModel(this.Index, path);
	}

	/*
	 * Spawn entity.
	 */
	public void Spawn()
	{
		DispatchSpawn(this.Index);
	}

	/**
	* Set variant string.
	*/
	public void SetVariantString(const char[] str)
	{
		SetVariantString(str);
	}

	/**
	* Invokes a named input method on this entity.
	*/
	public void AcceptInput(const char[] input, CBaseEntity activator = view_as<CBaseEntity>(INVALID_ENT_REFERENCE), CBaseEntity caller = view_as<CBaseEntity>(INVALID_ENT_REFERENCE), int outputid = 0)
	{
		AcceptEntityInput(this.Index, input, activator.Index, caller.Index, outputid);
	}

	/**
	 * Gets the move parent of this entity, if any.
	*/
	public CBaseEntity GetParent()
	{
		return this.GetPropEnt(Prop_Data, "m_pParent");
	}

	/*
	 * Set parent entity.
	 */
	public void SetParent(CBaseEntity parent)
	{
		this.SetVariantString("!activator");
		AcceptEntityInput(this.Index, "SetParent", parent.Index, parent.Index);
	}

	/**
	 * Gets this entity's render color.
	 *
	 * @param r		The red component of the entity's color, filled by reference.
	 * @param g		The green component of the entity's color, filled by reference.
	 * @param b		The blue component of the entity's color, filled by reference.
	 * @param a		The alpha component of the entity's color, optionally filled by reference.
	*/
	public void GetRenderColor(int &r, int &g, int &b, int &a = 0)
	{
		int color = this.GetProp(Prop_Send, "m_clrRender");

		r = color & 0x000000FF;
		g = (color & 0x0000FF00) >> 8;
		b = (color & 0x00FF0000) >> 16;
		a = (color & 0xFF000000) >> 24;
	}

	/**
	 * Sets this entity's render color.
	 *
	 * @param r		The red component to set. Valid byte values from 0 to 255.
	 * @param g		The green component to set. Valid byte values from 0 to 255.
	 * @param b		The blue component to set. Valid byte values from 0 to 255.
	 * @param a		The optional alpha component to set. Valid byte values from 0 to 255.
	*/
	public void SetRenderColor(int r, int g, int b, int a = 255)
	{
		SetEntityRenderColor(this.Index, r, g, b, a);
	}

	/**
	 * Dispatches a particle effect on this entity instance.
	 *
	 * @param effectName	The name of the effect to dispatch.
	*/
	public void DispatchEffect(const char[] effectName)
	{
		SetVariantString(effectName);
		this.AcceptInput("DispatchEffect");
	}

	/*
	 * Start entity.
	 */
	public void Start()
	{
		this.AcceptInput("Start");
	}

	/*
	 * Kill entity.
	 */
	public void Kill()
	{
		this.AcceptInput("Kill");
	}

	/**
	* Safe remove entity. (this > Kill)
	*/
	public void Remove()
	{
		RemoveEntity(this.Index);
	}

	/*
	 * Activate entity.
	 */
	public void Activate()
	{
		ActivateEntity(this.Index);
	}

	/*
	 * Dispatch entity key value.
	 */
	public void SetKeyValue(const char[] key, const char[] value)
	{
		DispatchKeyValue(this.Index, key, value);
	}

	/*
	 * Dispatch entity key vector value.
	 */
	public void SetKeyValueVector(const char[] key, const float value[3])
	{
		DispatchKeyValueVector(this.Index, key, value);
	}

	/*
	 * Setup single output hook on entity.
	 */
	public void HookSingleOutput(const char[] output, EntityOutput callback, bool once = false)
	{
		HookSingleEntityOutput(this.Index, output, callback, once);
	}

	/*
	 * Remove a single entity output hook.
	 */
	public void UnhookSingleOutput(const char[] output, EntityOutput callback)
	{
		UnhookSingleEntityOutput(this.Index, output, callback);
	}

	/*
	 * Set entity model scale.
	 */
	public void SetModelScale(float scale)
	{
		SetEntPropFloat(this.Index, Prop_Send, "m_flModelScale", scale);
	}

	public bool HasProp(PropType type, const char[] name)
	{
		return HasEntProp(this.Index, type, name);
	}

	/*
	 * Get Entity from handle.
	 * Same as using view_as<Entity>(index);
	 */
	public static CBaseEntity GetFromHandle(int entityIndex)
	{
		return view_as<CBaseEntity>(entityIndex);
	}

	public static float GetEntitiesDistance(CBaseEntity entity1, CBaseEntity entity2, bool squared = false)
	{
		if (!entity1.IsValid || !entity2.IsValid)
			return 0.0;

		if (!entity1.HasProp(Prop_Send, "m_vecOrigin") || !entity1.HasProp(Prop_Send, "m_vecOrigin"))
			return 0.0;
		
		float fOrigin1[3];
		entity1.GetLocalOrigin(fOrigin1);

		float fOrigin2[3];
		entity2.GetLocalOrigin(fOrigin2);
		
		return GetVectorDistance(fOrigin1, fOrigin2, squared);
	}

	/**
	 * Create an entity and wrap it in a Entity methodmap.
	*/
	public static CBaseEntity CreateByName(const char[] className, int forceEdictIndex = -1)
	{
		int entIndex = CreateEntityByName(className, forceEdictIndex);
		return view_as<CBaseEntity>(entIndex);
	}

	/**
	 * Find an entity by classname and wrap the result in a Entity methodmap.
	*/
	public static CBaseEntity FindByClassname(CBaseEntity startEnt, const char[] className)
	{
		int entIndex = FindEntityByClassname(startEnt.Index, className);
		return view_as<CBaseEntity>(entIndex);
	}
}

stock bool operator==(CBaseEntity e1, CBaseEntity e2)
{
	return e1.Index == e2.Index;
}

stock bool operator!=(CBaseEntity e1, CBaseEntity e2)
{
	return e1.Index != e2.Index;
}