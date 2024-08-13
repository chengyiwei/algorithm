@echo off
:loop
make_data
D
D1
fc D.out D1.out 
if errorlevel==1 pause
goto loop
