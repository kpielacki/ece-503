# Result Text File #
Place the result text files in the executable directory of QT otherwiseit's viewed as missing and you
will no be able to make any purchases, sales, or view stock values. Example directory below.

This may not appear until the code is compiled by QT.

C:\Users\ekevpie\Documents\build-FinalProject_gui_kevin_pielacki-Desktop_Qt_5_9_0_MinGW_32bit-Debug
<Project Directory Setting>\build-FinalProject_gui_kevin_pielacki-Desktop_Qt_5_9_0_MinGW_32bit-Debug

# Environment Variables #
Set Visual Studio Envirement Variable to Matlab Path
PATH=C:\Program Files\MATLAB\R2017a\bin\win64

# VC++ Directories #
Excutable Directories=C:\Program Files\MATLAB\R2017a\bin\win64;$(ExecutablePath)
Include Directories=C:\Program Files\MATLAB\R2017a\extern\include;$(IncludePath)
Library Directories=C:\Program Files\MATLAB\R2017a\extern\lib\win64\microsoft;$(LibraryPath)

# Linker Input #
Additional Dependencies=libmx.lib;libmex.lib;libeng.lib;libmat.lib;%(AdditionalDependencies)
