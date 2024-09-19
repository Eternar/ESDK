---@class MapDataStore
MapDataStore = extends("MapDataStore", "RageHash");

function MapDataStore:GetIndex()
    return GetMapdataFromHashKey(self:GetRawHash())
end
