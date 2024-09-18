Citizen.WrapThread = (function(handler, ...)
    local args <const> = { ... };

    Citizen.CreateThread(function()
        handler(table.unpack(args));
    end);
end);