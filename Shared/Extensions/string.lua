function string.random(length)
    local result = "";

    for _ = 1, length do
        result = result .. string.format("%x", math.random(0, 15));
    end

    return result;
end

function string.replace(str, from, to)
    return str:gsub("%" .. from, to);
end

function string.keywords(str, ...)
    for k, v in pairs(...) do
        str = string.replace(str, k, v);
    end

    return str;
end

function string.stripcolors(str)
    return str:gsub("%^%d", ""):gsub("%^#[%dA-Fa-f]+", ""):gsub("~[%a]~", "");
end