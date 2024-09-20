CONSTANTS =
{
    RESOURCE_NAME = GetCurrentResourceName(),
};

IS_SERVER = IsDuplicityVersion();

-- The game the script environment is running in.
--
-- Possible values:
--
-- - fxserver	Server-side code ('Duplicity')
--
-- - fivem	FiveM for GTA V
--
-- - libertym	LibertyM for GTA IV
--
-- - redm	RedM for Red Dead Redemption 2
GAME_NAME = GetGameName();

-- The build number.
--
-- Internal build number of the current game being executed.
--
-- Possible values:
--
-- FiveM
--  - 1604
--  - 2060
--  - 2189
--  - 2372
--  - 2545
--  - 2612
--  - 2699
--  - 2802
--  - 2944
--  - 3095
--  - 3258
--  - 3323
--
-- RedM
--  - 1311
--  - 1355
--  - 1436
--  - 1491
--
-- LibertyM
--  - 43
--
-- FXServer
--  - 0
GAME_BUILD = GetGameBuildNumber();

GetGameNameFromBuildNumber = (function(build)
    if (build == 0) then
        return Game.FXServer;
    end

    if (build == 43) then
        return Game.LibertyM;
    end

    -- TODO: change with updates when needed
    if (build < 1604) then
        return Game.RedM;
    end

    return Game.FiveM;
end);

-- True if the current game being executed is FiveM.
IS_FIVEM = GAME_NAME == Game.FiveM;

-- True if the current game being executed is RedM.
IS_REDM = GAME_NAME == Game.RedM;

-- True if the current game being executed is LibertyM.
IS_LIBERTYM = GAME_NAME == Game.LibertyM;

-- True if the script is executed by the FXServer.
IS_FXSERVER = GAME_NAME == Game.FXServer;

-- RedM related common variables..
if IS_REDM then
    -- FiveM related common variables..
elseif IS_FIVEM then
    -- LibertyM related common variables..
elseif IS_LIBERTYM then

end

-- Server related common variables..
if IS_SERVER then
    -- RedM related server-common variables..
    if IS_REDM then
        -- FiveM related server-common variables..
    elseif IS_FIVEM then
        -- LibertyM related server-common variables..
    elseif IS_LIBERTYM then

    end

    -- Shared server related common variables..
else
    -- RedM related client-common variables..
    if IS_REDM then
        MP_CHARACTER_MALE = `mp_male`;
        MP_CHARACTER_FEMALE = `mp_female`;

    -- FiveM related client-common variables..
    elseif IS_FIVEM then
        MP_CHARACTER_MALE = `mp_m_freemode_01`;
        MP_CHARACTER_FEMALE = `mp_f_freemode_01`;

    -- LibertyM related client-common variables..
    elseif IS_LIBERTYM then
        -- TODO: unknown atm
    end

    -- Shared client related common variables..
end
