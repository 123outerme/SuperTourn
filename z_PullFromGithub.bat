@set folder=C:\Program Files\Git\tmp\pulls
@cd %folder%\SuperTourn
@IF EXIST "%folder%\SuperTourn\.git" (
	cd /d "%folder%\SuperTourn\.git"
	for /F "delims=" %%i in ('dir /b') do (rmdir "%%i" /s/q || del "%%i" /s/q)
	cd ..
)

@git init
@git remote add origin https://github.com/123outerme/SuperTourn.git
git pull origin master --allow-unrelated-histories
@ROBOCOPY "%folder%\SuperTourn" "C:\Program Files\Git\code\SuperTourn" /MIR
@IF EXIST "%folder%\SuperTourn" (
	@cd /d "%folder%\SuperTourn"
	@for /F "delims=" %%i in ('dir /b') do (rmdir "%%i" /s/q || del "%%i" /s/q)
)
@ROBOCOPY "C:\Program Files\Git\code\SuperTourn" %~dp0 *.c *.h *.txt *.ico *.rc *.png *.bat /MIR /XD dirs .git ST ST-bin
@cd "C:\Program Files\Git\code\SuperTourn"
@git init
@git add -A
@cd %~dp0
@rem @pause Done! Press anything to continue.