Console = {};

local DEFAULT <const> = "^0";
local INFO <const> = DEFAULT .. "[^2" .. "INFO" .. DEFAULT .. "]";
local ERROR <const> = DEFAULT .. "[^1" .. "ERROR" .. DEFAULT .. "]";
local WARNING <const> = DEFAULT .. "[^3" .. "WARNING" .. DEFAULT .. "]";
local DEBUG <const> = DEFAULT .. "[^5" .. "DEBUG" .. DEFAULT .. "]";

local function InternalWrite(prefix, str)
    if (IS_SERVER) then
        Citizen.CreateThreadNow(function()
            -- Wait to prevent from printing the debug strings to ingame chat (same frame bug)
            Citizen.Wait(0);

            print(string.format("%s %s", prefix, str));
        end);
    else
        print(string.format("%s %s", prefix, str));
    end
end

function Console.Info(str)
    InternalWrite(INFO, str);
end

function Console.Error(str)
    InternalWrite(ERROR, str);
end

function Console.Warning(str)
    if not (Runtime.Debug.IgnoreWarnings) then
        InternalWrite(WARNING, str);
    end
end

function Console.Log(str)
    if (Runtime.Debug.Enable) then
        InternalWrite(DEBUG, str);
    end
end

function Console.DumpTable(t)
    Console.Log("<Table Dump>\n" .. table.dump(t));
end

if (IS_SERVER) then
    function Console.GetBuffer(maxLength)
        local buffer = GetConsoleBuffer();

        if (maxLength) then
            return buffer:sub(-maxLength)
        end

        return buffer;
    end

    function Console.GetLastCharacters(characters)
        return Console.GetBuffer(characters);
    end

    function Console.GetLastLines(count)
        local function SplitLines(inputString)
            local lines = {};

            for line in string.gmatch(inputString, "([^\r\n]+)") do
                table.insert(lines, line);
            end

            return lines;
        end

        local lines = SplitLines(Console.GetBuffer());
        local totalLines = #lines;

        local startLine = math.max(1, totalLines - count + 1);
        local latestLines = {};

        for i = startLine, totalLines do
            table.insert(latestLines, lines[i]);
        end

        return table.concat(latestLines, "\n");
    end

    function Console.PrintStack(stackObject)
        PrintStructuredTrace(json.encode(stackObject));
    end
end
