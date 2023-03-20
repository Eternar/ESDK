/* This file is a part of the Eternar SDK. */

#if defined _ESDK_PluginManager_included_
  #endinput
#endif
#define _ESDK_PluginManager_included_

methodmap PluginManager __nullable__
{
	public static bool IsValidPlugin(Handle hPlugin)
	{
		if (hPlugin == null)
			return false;

		Handle hIterator = GetPluginIterator();

		bool bPluginValid = false;
		while (MorePlugins(hIterator))
		{
			Handle hLoadedPlugin = ReadPlugin(hIterator);
			
			if (hLoadedPlugin == hPlugin)
			{
				bPluginValid = GetPluginStatus(hLoadedPlugin) == Plugin_Running;
				break;
			}
		}

		delete hIterator;
		return bPluginValid;
	}

	public static bool PluginExists(const char[] pluginName)
	{
		char szBuffer[PLATFORM_MAX_PATH];
		Format(szBuffer, sizeof(szBuffer), "addons/sourcemod/plugins/%s", pluginName);
		return FileExists(szBuffer);
	}

	public static bool DeletePlugin(const char[] pluginName)
	{
		char szBuffer[PLATFORM_MAX_PATH];
		Format(szBuffer, sizeof(szBuffer), "addons/sourcemod/plugins/%s", pluginName);
		return DeleteFile(szBuffer);
	}

	public static void ManagePlugin(const char[] pluginName, const char[] action)
	{
		ServerCommand("sm_rcon sm plugins %s %s", action, pluginName);
	}
}