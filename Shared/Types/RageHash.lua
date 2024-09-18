---@class RageHash
RageHash = class "RageHash";

function RageHash:Constructor(hash)
    if not (hash) then
        error("No hash specified.");
    end

    self.Value = hash or nil;
end

-- forcefully returns 32bit version
function RageHash:GetHash()
    return self.Value & 0xFFFFFFFF;
end

-- could return 64bit version, depends on the stored value
function RageHash:GetRawHash()
    return self.Value;
end

function RageHash:ToString()
    return string.format("0x%X", self:GetHash());
end

function RageHash:GetHashNum()
    return tonumber(self:ToString():match("0x[%x]+"), 0x10);
end

function RageHash.__eq(lhs, rhs)
    return lhs:GetHash() == rhs:GetHash();
end

function RageHash.Create(input, full, ignore_casing)
    if (full) then
        return RageHash:New(joaat(input, ignore_casing));
    end

    -- this substring stuff is experimental, for some reason fivem truncates it?
    return RageHash:New(joaat(input:sub(1, 18), ignore_casing));
end
