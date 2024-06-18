@echo off
:loop
make_data
A
A1
fc A.out A1.out
if errorlevel==1 pause
goto loop