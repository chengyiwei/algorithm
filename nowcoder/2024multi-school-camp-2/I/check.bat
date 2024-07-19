@echo off
:loop
make_data
I.exe
I0.exe
Fc I.out I0.out
if errorlevel==1 pause
goto loop