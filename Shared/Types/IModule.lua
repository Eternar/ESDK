---@interface IModule
IModule = extends("IModule", "IEventHandler");

DefineInterfaceMethod("IModule", "Start");
DefineInterfaceMethod("IModule", "Stop");

DefineInterfaceMethod("IModule", "OnStart");
DefineInterfaceMethod("IModule", "OnStop");

DefineInterfaceMethod("IModule", "GetType");
