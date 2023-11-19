@echo off
:loop
make_data
A
A0
fc A.out A0.out 
if errorlevel==1 pause
goto loop
