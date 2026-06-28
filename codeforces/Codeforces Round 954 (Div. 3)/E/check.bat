@echo off
:loop
make_data
E
E0
FC E.out E0.out
if errorlevel==1 pause
goto loop