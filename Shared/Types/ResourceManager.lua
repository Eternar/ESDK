---@class ResourceManager
ResourceManager = implements("ResourceManager", "IEventHandler");

local CurrentResourceManager = nil;

-- event handler for 'onResourceStart'
ResourceManager.OnResourceStart = nil;

-- event handler for 'onResourceStop'
ResourceManager.OnResourceStop = nil;

ResourceManager.OnResourceStartInternal = (function(resourceName)
    if not (CurrentResourceManager) then
        return;
    end

    CurrentResourceManager:AddResource(resourceName);
end);

ResourceManager.OnResourceStopInternal = (function(resourceName)
    if not (CurrentResourceManager) then
        return;
    end

    CurrentResourceManager:RemoveResourceByName(resourceName);
end);

ResourceManager.GetCurrent = (function()
    return CurrentResourceManager;
end);

function ResourceManager:Constructor()
    self.Resources = Collection:New();

    for i = 0, GetNumResources(), 1 do
        local resource = GetResourceByFindIndex(i);

        if resource and GetResourceState(resource) == ResourceState.STARTED then
            self:AddResource(resource)
        end
    end

    self.OnResourceStart = self:OnEvent("OnResourceStart", ResourceManager.OnResourceStartInternal);
    self.OnResourceStop = self:OnEvent("onResourceStop", ResourceManager.OnResourceStopInternal);

    CurrentResourceManager = self;
end

function ResourceManager:Destructor()
    self:OffEvent(self.OnResourceStart);
    self:OffEvent(self.OnResourceStop);
end

function ResourceManager:GetResourceList()
    local resources = {};

    self.Resources:ForEach(function(_, resource)
        table.insert(resources, resource:GetName());
    end);

    return resources;
end

function ResourceManager:GetNumResources()
    return #self.Resources;
end

function ResourceManager:GetResourceByFindIndex(findIndex)
    return GetResourceByFindIndex(findIndex);
end

function ResourceManager:GetResourceState(resourceName)
    return GetResourceState(resourceName);
end

function ResourceManager:AddResource(resourceName)
    if (self:GetResourceByName(resourceName)) then
        return; -- we already have this resource
    end

    self.Resources:Add(Resource:New(resourceName));
end

function ResourceManager:GetResourceByName(resourceName)
    return self.Resources:Find(function(resource)
        return resource:GetName() == resourceName;
    end);
end

function ResourceManager:RemoveResourceByName(resourceName)
    self.Resources:Remove(self:GetResourceByName(resourceName));
end

function ResourceManager:RemoveResource(resource)
    self.Resources:Remove(resource);
end

function ResourceManager:GetResources(predicate)
    local resources = Collection:New();

    self.Resources:ForEach(function(_, resource)
        if (predicate(resource)) then
            resources:Add(resource);
        end
    end);

    return resources;
end

function ResourceManager:GetMapResources()
    return self:GetResources(function(resource)
        return resource:IsMap();
    end);
end

ResourcesManager = ResourceManager:New();
