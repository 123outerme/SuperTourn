@windres resource.rc resource.o
gcc -L"%cd%\SDL" main.c superTourn.c superTourn.h outermeSDL.c outermeSDL.h resource.o -o SuperTourn.exe -mwindows -lSDL2 -lSDL2_image -lSDL2_ttf
@rem the above line can't be muted or it won't compile
@move /Y %~dp0\SuperTourn.exe %~dp0\..\execute\
@cd ..\execute
@set execDir=%cd%
@cd ..\build
@powershell "$s=(New-Object -COM WScript.Shell).CreateShortcut('%userprofile%\Desktop\SuperTourn.lnk');$s.TargetPath='%execDir%\SuperTourn.exe';$s.IconLocation='%cd%\icon.ico';$s.workingDirectory='%execDir%';$s.Save()"
@echo Done assembling! You can find and launch SuperTourn from your Desktop, hopefully. If not, you can make a shortcut from the .exe in the execute subfolder.
@pause