Citizen.WrapThread = (function(handler, ...)
    local args <const> = { ... };

    Citizen.CreateThread(function()
        handler(table.unpack(args));
    end);
end);

Citizen.Yield = (function(cb, errorMessage, timeout)
    local value = cb();

    if (value ~= nil) then
        return value;
    end

    if (timeout) or (timeout == nil) then
        if (type(timeout) ~= "number") then
            timeout = 1000;
        end
    end

    local start = timeout and GetGameTimer();

    while (value == nil) do
        Citizen.Wait(0);

        local elapsed = timeout and GetGameTimer() - start;

        if (elapsed) and (elapsed > timeout) then
            return error(("\"^1%s^0\" (waited ^6%.1f^0 ms)") : format(errorMessage or "Failed to resolve callback", elapsed), 2);
        end

        value = cb();
    end

    return value;
end);
