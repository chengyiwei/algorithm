@echo off
:loop
make_data
H.exe
fc H.out H0.out
if errorlevel==1 pause
goto loop
