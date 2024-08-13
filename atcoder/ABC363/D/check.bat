@echo off
:loop
make_data
D 
D0
FC D.out D0.out
if errorlevel==1 pause
goto loop