---@class Streaming
Streaming = class "Streaming";

local function RequestStreamAsset(request, hasLoaded, type, asset, timeout, ...)
    if (hasLoaded(asset)) then
        return asset;
    end

    request(asset, ...);

    return Citizen.Yield(function()
        if (hasLoaded(asset)) then
            return asset;
        end
    end, ("Failed to request \"^6%s^0\" (^5%s^0)") : format(asset, type), timeout);
end

local function InvalidRequest(value, type)
    Console.Error(("Attempted to request invalid \"^5%s^0\": ^5%s^0") : format(type, value));
end

function Streaming.RequestAnimDict(animDict, timeout)
    if not (DoesAnimDictExist(animDict)) then
        return InvalidRequest(animDict, "AnimDict");
    end

    return RequestStreamAsset(RequestAnimDict, HasAnimDictLoaded, "AnimDict", animDict, timeout);
end

function Streaming.RequestAnimSet(animSet, timeout)
    return RequestStreamAsset(RequestAnimSet, HasAnimSetLoaded, "AnimSet", animSet, timeout);
end

function Streaming.RequestModel(model, timeout)
    if (type(model) ~= "number") then
        model = GetHashKey(model);
    end

    if not (IsModelValid(model)) then
        return InvalidRequest(model, "Model");
    end

    return RequestStreamAsset(RequestModel, HasModelLoaded, "Model", model, timeout);
end

function Streaming.RequestNamedPtfxAsset(ptfxName, timeout)
    return RequestStreamAsset(RequestNamedPtfxAsset, HasNamedPtfxAssetLoaded, "PtFx", ptfxName, timeout);
end

function Streaming.RequestScaleformMovie(scaleformName, timeout)
    return RequestStreamAsset(RequestScaleformMovie, HasScaleformMovieLoaded, "ScaleformMovie", scaleformName, timeout);
end

function Streaming.RequestStreamedTextureDict(textureDict, timeout)
    return RequestStreamAsset(RequestStreamedTextureDict, HasStreamedTextureDictLoaded, "TextureDict", textureDict, timeout);
end

function Streaming.RequestWeaponAsset(weaponHash, timeout, weaponResourceFlags, extraWeaponComponentFlags)
    return RequestStreamAsset(RequestWeaponAsset, HasWeaponAssetLoaded, "WeaponHash", weaponHash, timeout, weaponResourceFlags or 31, extraWeaponComponentFlags or 0);
end
