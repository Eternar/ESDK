#include <SteamWorks>

methodmap Server
{
    public static void GetHostname(char[] output, int maxsize, bool showport = false)
    {
        ConsoleVariable.Find("hostname").GetString(output, maxsize);
    }

    public static void GetAddress(char[] output, int maxsize, bool showport = true)
    {
        int ip = FindConVar("hostip").IntValue;

        if (ip == 0)
        {
            char ips[4];
            SteamWorks_GetPublicIP(ips);
            Format(output, maxsize, "%d.%d.%d.%d", ips[0], ips[1], ips[2], ips[3]);
        } else {
            int ips[4];
            ips[0] = (ip >> 24) & 0x000000FF;
            ips[1] = (ip >> 16) & 0x000000FF;
            ips[2] = (ip >> 8) & 0x000000FF;
            ips[3] = ip & 0x000000FF;

            Format(output, maxsize, "%d.%d.%d.%d", ips[0], ips[1], ips[2], ips[3]);
        }

        if (showport)
            Format(output, maxsize, "%s:%d", output, FindConVar("hostport").IntValue);
    }

    public static int GetPort()
    {
        return ConsoleVariable.Find("hostport").IntValue;
    }

    public static int GetMaxRounds()
    {
        return ConsoleVariable.Find("mp_maxrounds").IntValue;
    }

    public static int GetCurrentMap(char[] output, int maxsize)
    {
        return GetCurrentMap(output, maxsize);
    }
}