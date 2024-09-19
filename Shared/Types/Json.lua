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
    local result, err = JsonConvert.Serialize(self.Object, state);

    if (err) then
        error(("Serialization failed: %s"):format(err));
    end

    return result;
end

function JsonObject:Deserialize(string, position, null, objectmeta, arraymeta)
    local result, pos, err = JsonConvert.Deserialize(string, position, null, objectmeta, arraymeta);

    if (err) then
        error(("Deserialization failed: '%s' at position: %d"):format(err, pos));
    end

    return result;
end

JsonConvert.Serialize = (function(obj, state)
    local finalState = {};

    if (type(state) == "boolean") then
        finalState = { indent = state };
    elseif (type(state) == "table") then
        finalState = state;
    end

    local encoded, err = json.encode(obj, finalState);

    if not (encoded) then
        return nil, err;
    end

    return encoded;
end);

JsonConvert.Deserialize = (function(string, position, null, objectmeta, arraymeta)
    local decoded, pos, err = json.decode(string, position, null, objectmeta, arraymeta);

    if not (decoded) then
        return nil, err;
    end

    return decoded, pos;
end);
