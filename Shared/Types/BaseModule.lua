---@class BaseModule
BaseModule = implements("BaseModule", "IModule");

BaseModule.Status = ModuleState.MISSING;

function BaseModule:Start()
    Console.Log(("Starting module '%s'"):format(self:GetType()));

    if (self.Status == ModuleState.STARTED) then
        Console.Warning(("Module '%s' is already started"):format(self:GetType()));
        return;
    end

    self.Status = ModuleState.STARTING;
    self:OnStart();
    self.Status = ModuleState.STARTED;

    Console.Log(("Module '%s' has been started"):format(self:GetType()));
end

function BaseModule:Stop()
    Console.Log(("Stopping module '%s'"):format(self:GetType()));

    if (self.Status == ModuleState.STOPPED) then
        Console.Warning(("Module '%s' is already stopped"):format(self:GetType()));
        return;
    end

    self.Status = ModuleState.STOPPING;
    self:OnStop();
    self.Status = ModuleState.STOPPED;

    Console.Log(("Module '%s' has been stopped"):format(self:GetType()));
end

function BaseModule:GetStatus()
    return self.Status;
end
