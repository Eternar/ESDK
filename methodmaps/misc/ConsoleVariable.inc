/* This file is a part of the Eternar SDK. */

methodmap ConsoleVariable < ConVar
{
    /**
     * Creates a new console variable.
     *
     * @param name          Name of new convar.
     * @param defaultValue  String containing the default value of new convar.
     * @param description   Optional description of the convar.
     * @param flags         Optional bitstring of flags determining how the convar should be handled. See FCVAR_* constants for more details.
     * @param hasMin        Optional boolean that determines if the convar has a minimum value.
     * @param min           Minimum floating point value that the convar can have if hasMin is true.
     * @param hasMax        Optional boolean that determines if the convar has a maximum value.
     * @param max           Maximum floating point value that the convar can have if hasMax is true.
     * @return              A handle to the newly created convar. If the convar already exists, a handle to it will still be returned.
     * @error               Convar name is blank or is the same as an existing console command.
     */
    public ConsoleVariable(const char[] name, const char[] defaultValue, const char[] description="", int flags=0, bool hasMin=false, float min=0.0, bool hasMax=false, float max=0.0)
    {
        return view_as<ConsoleVariable>(CreateConVar(name, defaultValue, description, flags, hasMin, min, hasMax, max));
    }

    /**
     * Name of convar to find.
     *
     * Searches for a console variable.
     *
     * @param name — Name of convar to find.
     *
     * @return A ConVar object if found; null otherwise.
     */
    public static ConsoleVariable Find(const char[] name)
    {
        return view_as<ConsoleVariable>(FindConVar(name));
    }
}