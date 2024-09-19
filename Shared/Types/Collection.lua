---@class Collection
Collection = class "Collection";

function Collection:Constructor(col)
    self.Items = col or {};
end

function Collection:Add(item, index)
    if (index) then
        table.insert(self.Items, index, item);
    else
        table.insert(self.Items, item);
    end
end

function Collection:First()
    return self.Items[1];
end

function Collection:Last()
    return self.Items[#self.Items];
end

function Collection:Any(predicate)
    if (predicate) and (type(predicate) == "function") then
        self:ForEach(function(_, item)
            if (predicate(_, item)) then
                return true;
            end
        end);
    else
        if (self:Count() > 0 and self:First() ~= nil) then
            return true;
        end
    end

    return false;
end

function Collection:Remove(item)
    for i, v in ipairs(self.Items) do
        if v == item then
            table.remove(self.Items, i);
            return true;
        end
    end

    return false;
end

function Collection:RemoveIndex(index)
    table.remove(self.Items, index);
end

function Collection:Contains(item)
    for _, v in ipairs(self.Items) do
        if v == item then
            return true;
        end
    end

    return false;
end

function Collection:ForEach(func)
    for k, v in ipairs(self.Items) do
        func(k, v);
    end
end

function Collection:Find(predicate)
    for _, v in ipairs(self.Items) do
        if predicate(v) then
            return v;
        end
    end

    return nil;
end

function Collection:FindAll(predicate)
    local collection = Collection:New();

    for _, v in ipairs(self.Items) do
        if predicate(v) then
            collection:Add(v);
        end
    end

    return collection;
end

function Collection:Count()
    return #self.Items;
end

function Collection:IsEmpty()
    return #self.Items == 0;
end

function Collection:Clear()
    self.Items = {};
end

function Collection:IndexOf(item)
    for i, v in ipairs(self.Items) do
        if v == item then
            return i;
        end
    end

    return -1;
end

function Collection:Reverse()
    local reversed = Collection:New();

    for i = #self.Items, 1, -1 do
        reversed:Add(self.Items[i]);
    end

    return reversed;
end

function Collection:Map(func)
    local mapped = Collection:New();

    for _, v in ipairs(self.Items) do
        mapped:Add(func(v));
    end

    return mapped;
end

function Collection:Filter(predicate)
    local filtered = Collection:New();

    for _, v in ipairs(self.Items) do
        if predicate(v) then
            filtered:Add(v);
        end
    end

    return filtered;
end

function Collection:Reduce(func, initial)
    local acc = initial;

    for _, v in ipairs(self.Items) do
        acc = func(acc, v);
    end

    return acc;
end

function Collection:Merge(otherCollection)
    for _, v in ipairs(otherCollection:GetRaw()) do
        self:Add(v);
    end
end

function Collection:GetRaw()
    return self.Items;
end

--[[ cfx.re only ]]
if (IS_SERVER) then
    if (TriggerClientEvent) then
        function Collection:SendToClient(eventName, playerId)
            TriggerClientEvent(eventName, playerId, self:GetRaw());
        end
    end
else
    if (TriggerServerEvent) then
        function Collection:SendToServer(eventName)
            TriggerServerEvent(eventName, self:GetRaw());
        end
    end
end
