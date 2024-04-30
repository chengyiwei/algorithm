@echo off
:loop
make_data.exe
K.exe
J.exe
fc K.in K0.out
if errorlevel==1 pause
goto loop
