@echo off
:loop
make_data
D.exe
D0.exe
fc D.out D0.out
if errorlevel==1 pause
goto loop
