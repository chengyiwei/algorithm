@echo off
:loop
make_data.exe
D.exe
D0.exe
FC D.out D0.out
if errorlevel==1 pause
goto loop