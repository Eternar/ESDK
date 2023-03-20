/* This file is a part of the Eternar SDK. */

#if defined _ESDK_StringTable_included_
  #endinput
#endif
#define _ESDK_StringTable_included_

#include <sdktools>

const StringTable INVALID_STRINGTABLE = view_as<StringTable>(INVALID_STRING_TABLE);

methodmap StringTable __nullable__
{
	public StringTable(const char[] name)
	{
		return view_as<StringTable>(FindStringTable(name));
	}

	/**
	 * String table index
	 */
	property int Index
	{
		public get()
		{
			return view_as<int>(this);
		}
	}

	/**
	 * Returns the number of strings that currently exist in a given string table.
	 *
	 * @return              Number of strings that currently exist.
	 * @error               Invalid string table index.
	 */
	property int Count
	{
		public get()
		{
			return GetStringTableNumStrings(this.Index);
		}
	}

	/**
	 * Returns the maximum number of strings that are allowed in a given string table.
	 *
	 * @return              Maximum number of strings allowed.
	 * @error               Invalid string table index.
	 */
	property int Length
	{
		public get()
		{
			return GetStringTableMaxStrings(this.Index);
		}
	}

	/**
	 * Searches for the index of a given string in a string table.
	 *
	 * @param fileName		String to find.
	 * @return              String index if found, INVALID_STRING_INDEX otherwise.
	 * @error               Invalid string table index.
	 */
	public int FindIndex(const char[] fileName)
	{
		return FindStringIndex(this.Index, fileName);
	}

	/**
	 * Retrieves the name of a string table.
	 *
	 * @param name          Buffer to store the name of the string table.
	 * @param maxlength     Maximum length of string buffer.
	 * @return              Number of bytes written to the buffer (UTF-8 safe).
	 * @error               Invalid string table index.
	 */
	public int GetName(char[] name, int maxlength)
	{
		return GetStringTableName(this.Index, name, maxlength);
	}

	/**
	 * Retrieves the string at a given index of a string table.
	 *
	 * @param stringidx     A string index.
	 * @param str           Buffer to store the string value.
	 * @param maxlength     Maximum length of string buffer.
	 * @return              Number of bytes written to the buffer (UTF-8 safe).
	 * @error               Invalid string table index or string index.
	 */
	public int Read(int stringidx, char[] str, int maxlength)
	{
		return ReadStringTable(this.Index, stringidx, str, maxlength);
	}

	/**
	 * Returns the length of the user data associated with a given string index.
	 *
	 * @param stringidx     A string index.
	 * @return              Length of user data. This will be 0 if there is no user data.
	 * @error               Invalid string table index or string index.
	 */
	public int GetLength(int stringidx)
	{
		return GetStringTableDataLength(this.Index, stringidx);
	}

	/**
	 * Retrieves the user data associated with a given string index.
	 *
	 * @param stringidx     A string index.
	 * @param userdata      Buffer to store the user data. This will be set to "" if there is no user data
	 * @param maxlength     Maximum length of string buffer.
	 * @return              Number of bytes written to the buffer (binary safe, includes the null terminator).
	 * @error               Invalid string table index or string index.
	 */
	public int GetData(int stringidx, char[] userdata, int maxlength)
	{
		return GetStringTableData(this.Index, stringidx, userdata, maxlength);
	}

	/**
	 * Sets the user data associated with a given string index.
	 *
	 * @param stringidx     A string index.
	 * @param userdata      User data string that will be set.
	 * @param length        Length of user data string. This should include the null terminator.
	 * @error               Invalid string table index or string index.
	 */
	public void SetData(int stringidx, const char[] userdata, int length)
	{
		SetStringTableData(this.Index, stringidx, userdata, length);
	}

	/**
	 * Adds a string to a given string table.
	 *
	 * @param str           String to add.
	 * @param userdata      An optional user data string.
	 * @param length        Length of user data string. This should include the null terminator.
	 *                      If set to -1, then user data will be not be altered if the specified string
	 *                      already exists in the string table.
	 * @error               Invalid string table index.
	 */
	public void Add(const char[] str, const char[] userdata = "", int length = -1)
	{
		AddToStringTable(this.Index, str, userdata, length);
	}

	/**
	 * Searches for a string table.
	 *
	 * @param name          Name of string table to find.
	 * @return              A string table index number if found, INVALID_STRINGTABLE otherwise.
	 */
	public static StringTable Find(const char[] name)
	{
		return new StringTable(name);
	}

	/**
	 * Returns the number of string tables that currently exist.
	 *
	 * @return              Number of string tables that currently exist.
	 */
	public static int GetCount()
	{
		return GetNumStringTables();
	}

	/**
	 * Locks or unlocks the network string tables.
	 *
	 * @param lock          Determines whether network string tables should be locked.
	 *                      True means the tables should be locked for writing; false means unlocked.
	 * @return              Previous lock state.
	 */
	public static bool Lock(bool lock)
	{
		return LockStringTables(lock);
	}
}