---@class Resource
Resource = class "Resource";

function Resource:Constructor(resourceName)
    self.Name = resourceName;
end

function Resource:GetName()
    return self.Name;
end

function Resource:GetPath()
    return GetResourcePath(self.Name);
end

function Resource:GetState()
    return GetResourceState(self.Name);
end

function Resource:GetMetadata(metadataKey, index)
    return GetResourceMetadata(self.Name, metadataKey, index);
end

function Resource:GetNumMetadata(metadataKey)
    return GetNumResourceMetadata(self.Name, metadataKey);
end

function Resource:GetKvpFloat(key)
    return GetExternalKvpFloat(self.Name, key);
end

function Resource:GetKvpInt(key)
    return GetExternalKvpInt(self.Name, key);
end

function Resource:GetKvpString(key)
    return GetExternalKvpString(self.Name, key);
end

function Resource:GetAuthor()
    return self:GetMetadata("author", 0);
end

function Resource:GetDescription()
    return self:GetMetadata("description", 0);
end

function Resource:GetURL()
    return self:GetMetadata("url", 0);
end

function Resource:GetVersion()
    return self:GetMetadata("version", 0);
end

function Resource:GetFXVersion()
    return self:GetMetadata("fx_version", 0);
end

function Resource:IsMap()
    return self:GetNumMetadata("this_is_a_map") > 0;
end

if (IS_SERVER) then
    function Resource:IsServerOnly()
        return self:GetNumMetadata("server_only") > 0;
    end
end

function Resource:IsLoadingScreen()
    return self:GetNumMetadata("loadscreen") > 0;
end

function Resource:LoadFile(fileName)
    return LoadResourceFile(self.Name, fileName);
end

function Resource:SaveFile(fileName, data, dataLength)
    return SaveResourceFile(self.Name, fileName, data, dataLength or -1);
end

function Resource.__eq(lhs, rhs)
    return lhs:GetName() == rhs:GetName();
end

CurrentResource = Resource:New(CONSTANTS.RESOURCE_NAME);

function CurrentResource:SetKvp(key, value)
    SetResourceKvp(key, value);
end

function CurrentResource:SetKvpNoSync(key, value)
    SetResourceKvpNoSync(key, value);
end

function CurrentResource:SetKvpFloat(key, value)
    SetResourceKvpFloat(key, value);
end

function CurrentResource:SetKvpFloatNoSync(key, value)
    SetResourceKvpFloatNoSync(key, value);
end

function CurrentResource:SetKvpInt(key, value)
    SetResourceKvpInt(key, value);
end

function CurrentResource:SetKvpIntNoSync(key, value)
    SetResourceKvpIntNoSync(key, value);
end
