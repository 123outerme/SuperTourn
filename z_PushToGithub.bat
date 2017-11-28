@ROBOCOPY %cd% "C:\Program Files\Git\code\SuperTourn" *.c *.h *.txt *.ico *.bin *.rc *.bat *.png *.ttf /MIR /XD dirs .git
@cd "C:\Program Files\Git\code\SuperTourn"
@set commitMessage=""
@IF [%1]==[] (
	set commitMessage=Updated
) ELSE (
	set commitMessage=%1
)
@git init
@git add .
@git commit -m %commitMessage%
@git remote add origin https://github.com/123outerme/SuperTourn
@git push origin master
@cd %~dp0
@pause Done! Press anything to continue.