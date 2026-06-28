@echo off
:loop
make_data
H.exe
H0.exe
Fc H.out H0.out
if errorlevel==1 pause
goto loop