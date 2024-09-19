---@class MapDataStore
MapDataStore = extends("MapDataStore", "RageHash");

if not (IS_SERVER) then
    function MapDataStore:GetIndex()
        return GetMapdataFromHashKey(self:GetRawHash())
    end
end
