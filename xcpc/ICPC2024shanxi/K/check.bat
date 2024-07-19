@echo off
:loop
make_data.exe
K.exe
K0.exe
Fc K.out K0.out
if errorlevel==1 pause
goto loop