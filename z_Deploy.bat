@ROBOCOPY %cd% "%cd%\ST-bin\build" *.c *.h *.ico *.rc
@ROBOCOPY %cd% "%cd%\ST-bin\execute" *.txt *.png *.ttf /MIR /XD dirs "%cd%\GtL" "%cd%\GtL-bin" "%cd%\.github" "%cd%\.git" "%cd%\bin" "%cd%\builds" "%cd%\documentation" "%cd%\obj"
@ROBOCOPY %cd% "%cd%\ST-bin" *.txt
@ROBOCOPY %cd% "%cd%\ST-bin\stuff" *.ico *.rc
@del %cd%\builds\binaries\GatewayToLegendbin.zip
@del %cd%\ST-bin\execute\GatewayToLegend.exe
@del %cd%\ST-bin\execute\GatewayToLegendToolchain.exe
@del %cd%\ST-bin\execute\GatewayToLegend.cfg
@ROBOCOPY %cd% "%cd%\ST\execute" *.txt *.png /MIR /XD dirs "%cd%\GtL" "%cd%\GtL-bin" "%cd%\.github" "%cd%\.git" "%cd%\bin" "%cd%\builds" "%cd%\documentation" "%cd%\obj"
@cd GtL-bin
@rem zip it up...
@%cd%\..\7za.exe a -y -tzip "%cd%\..\builds\binaries\SuperTournBin.zip" "%cd%" -mx5
@rem done...
@cd build
@del %cd%\..\..\builds\prebuilt\SuperTourn.zip
@del %cd%\..\..\ST\execute\SuperTourn.exe
@del %cd%\ST-bin\execute\SuperTourn.exe
@del %cd%\..\..\ST\execute\SuperToun.cfg
call a_makeWindows.bat
@ROBOCOPY %cd%\..\execute %cd%\..\..\ST\execute *.exe *.ico *.bat *.ttf
@rem zip it up...
cd ..\..
@%cd%\7za.exe a -y -tzip "%cd%\builds\prebuilt\SuperTourn.zip" "%cd%\ST" -mx5
@rem done...