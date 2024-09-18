-- FileSystem is server only.
if not (IS_SERVER) then
    return;
end

FileSystem = {};

FileSystem.GetFilesWithExtension = (function(directoryPath, fileExtension)
    local directoryHandle = nil;

    if (Runtime.Platform == OperatingSystem.WINDOWS) then
        directoryHandle = io.popen(('dir "%s\\*.%s" /b'):format(directoryPath, fileExtension));
    elseif (Runtime.Platform == OperatingSystem.LINUX) then
        directoryHandle = io.popen(('ls %s/*.%s'):format(directoryPath, fileExtension));
    else
        error("Invalid runtime platform specified");
    end

    if not (directoryHandle) then
        error(("Unable to open directory at path '%s'"):format(directoryPath));
    end

    local result = directoryHandle:read("*a");
    directoryHandle:close();

    if not (result) then
        error("Could not read from directory handle");
    end

    local files = Collection:New();

    for file in string.gmatch(result, "[^\r\n]+") do
        files:Add(file);
    end

    return files;
end);

FileSystem.RemoveFileExtension = (function(filePath)
    return string.match(filePath, "(.+)%.[^.]+$");
end);
