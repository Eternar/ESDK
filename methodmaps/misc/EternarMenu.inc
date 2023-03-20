/* This file is a part of the Eternar SDK. */

#if defined _ESDK_EternarMenu_included_
  #endinput
#endif
#define _ESDK_EternarMenu_included_

static stock char displayBuffer[512];
static stock char infoBuffer[512];

methodmap EternarMenu < Menu
{
	public EternarMenu(MenuHandler callback, MenuAction actions = MENU_ACTIONS_DEFAULT)
	{
		return view_as<EternarMenu>(new Menu(callback, actions));
	}

	property Menu Base
	{
		public get()
		{
			return view_as<Menu>(this);
		}
	}

	public EternarMenu NewItem(const char[] info, const char[] display, any ...)
	{
		strcopy(infoBuffer, sizeof(infoBuffer), info);
		VFormat(displayBuffer, sizeof(displayBuffer), display, 4);
		return this;
	}

	public EternarMenu NewItemInt(int info, const char[] display, any ...)
	{
		VFormat(displayBuffer, sizeof(displayBuffer), display, 4);
		IntToString(info, infoBuffer, sizeof(infoBuffer));
		return this;
	}

	public void Add(int itemstyle = ITEMDRAW_DEFAULT)
	{
		this.AddItem(infoBuffer, displayBuffer, itemstyle);
	}

#if defined _ESDK_Player_included_
	public void Display(Player player, int time = MENU_TIME_FOREVER)
	{
		this.Base.Display(player.Index, time);
	}
#else
	public void Display(int client, int time = MENU_TIME_FOREVER)
	{
		this.Base.Display(client, time);
	}
#endif
}