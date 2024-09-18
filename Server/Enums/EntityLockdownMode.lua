EntityLockdownMode =
{
    -- No entities can be created by clients at all.
    STRICT = "strict";

    -- Only script-owned entities created by clients are blocked.
    RELAXED = "relaxed";

    -- Clients can create any entity they want.
    INACTIVE = "inactive";
};
