table.deepmerge = (function(target, source)
    local stack = {};

    local function deepMerge(tgt, src)
        local visited = {};

        local function merge(tgt, src)
            for k, v in pairs(src) do
                if type(v) == "table" and type(tgt[k]) == "table" then
                    if not visited[v] then
                        visited[v] = true;
                        merge(tgt[k], v); -- Recursive merge
                    end
                else
                    tgt[k] = v;
                end
            end
        end

        table.insert(stack, { target = tgt, source = src });

        while #stack > 0 do
            local frame = table.remove(stack);
            merge(frame.target, frame.source);
        end
    end

    if type(target) ~= "table" or type(source) ~= "table" then
        error("Both target and source must be tables");
    end

    deepMerge(target, source);
end);

table.dump = (function(t)
    local function InternalDumpTable(t, nb, visited)
        visited = visited or {}
        if visited[t] then
            return "<already visited>"
        end
        visited[t] = true

        if nb == nil then
            nb = 0;
        end

        if type(t) == 'table' then
            local s = '{\n';

            for k, v in pairs(t) do
                if type(k) ~= 'number' then
                    k = '"' .. k .. '"';
                end

                for _ = 1, nb, 1 do
                    s = s .. "    ";
                end

                s = s .. '[' .. k .. '] = ' .. InternalDumpTable(v, nb + 1, visited) .. ',\n';
            end

            -- Check metatable for inherited properties
            local mt = getmetatable(t)
            if mt and not visited[mt] then
                s = s .. '    <metatable> = ' .. InternalDumpTable(mt, nb + 1, visited) .. ',\n'
            end

            for _ = 1, nb - 1, 1 do
                s = s .. "    ";
            end

            return s .. '}';
        else
            return tostring(t);
        end
    end

    return InternalDumpTable(t, 1);
end);

table.contains = (function(table, val)
    if table == nil then
        return false;
    end

    for _, v in pairs(table) do
        if v == val then
            return true;
        end
    end

    return false;
end);
