---@class MapDataStore
MapDataStore = extends("MapDataStore", "RageHash");

--[[ if not works correctly, investigate the ctor problem
---@diagnostic disable-next-line: duplicate-set-field
function MapDataStore:New(hash)
    local obj = RageHash:New(hash);
    setmetatable(obj, self);
    return obj;
end
]]

if not (IS_SERVER) then
    function MapDataStore:GetIndex()
        return GetMapdataFromHashKey(self:GetRawHash())
    end
end
