@echo off
:loop
make_data.exe
F0.exe
timeout /t 2
check.exe
fc check.out ok.out
if errorlevel==1 pause
goto loop
