#Snake++ port
Snake++ solution ported from CLion IDE with CMake configuration
on Linux to Visual Studio on Windows.

Set up for compilation:
1. extract the SDL2.zip archive
2. open the solution in Visual Studio
3. open View > Other Windows > Property Manager
4. open SnakePlusPlusPort > Debug | Win32 > Microsoft.Cpp.Win32.user
5. in the User Macros tab, add a macro with the name **PG4400\_SDL2\_PATH**
and the value is the path to the "SDL2" folder you have extracted from the archive in step 1
