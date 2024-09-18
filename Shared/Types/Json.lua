---@class JsonObject
JsonObject = class "JsonObject";

---@interface JsonConvert
JsonConvert = interface "JsonConvert";

function JsonObject:Constructor(obj)
    self.Object = obj or {};
end

function JsonObject:Set(key, value)
    self.Object[key] = value;
end

function JsonObject:Get(key)
    return self.Object[key];
end

function JsonObject:Serialize(state)
    return JsonConvert.Serialize(self.Object, state);
end

function JsonObject:Deserialize(string, position, null, objectmeta, arraymeta)
    return JsonConvert.Deserialize(string, position, null, objectmeta, arraymeta);
end

JsonConvert.Serialize = (function(obj, state)
    local finalState = {};

    if (type(state) == "boolean") then
        finalState = { indent = state, };
    elseif type(state) == "table" then
        finalState = state;
    end

    return json.encode(obj, finalState);
end);

JsonConvert.Deserialize = (function(string, position, null, objectmeta, arraymeta)
    return json.decode(string, position, null, objectmeta, arraymeta)
end);
