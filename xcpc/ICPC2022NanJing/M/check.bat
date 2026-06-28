@echo off
:loop
make_data
M.exe
M0.exe
FC M.out M0.out
if errorlevel==1 pause
goto loop