-- v7

---@class Guid
Guid = class "Guid";

Guid.__tostring = (function(self)
    return self.Value;
end);

function Guid:Constructor()
    self.Value = Guid.Generate();
end

function Guid:ToString()
    return self.Value;
end

function Guid.Generate()
    local function TimestampToHex()
        return string.format("%012x", os.time() * 1000);
    end

    local timePart = TimestampToHex();
    local version = "7";
    local variant = string.format("%x", math.random(8, 11));
    local randomPart = string.random(12);

    local guid = string.format("%s-%s%s-%s-%s",
        timePart:sub(1, 8),
        timePart:sub(9, 12),
        version,
        variant .. randomPart:sub(1, 3),
        randomPart:sub(4, 12)
    );

    return guid;
end
