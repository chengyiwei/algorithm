@echo off
:loop
make_data.exe
E.exe
E0.exe
fc E.out E0.out
if errorlevel==1 pause
goto loop