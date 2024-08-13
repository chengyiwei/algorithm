@echo off
:loop
make_data
A_
A2
fc A_.out A2.out
if errorlevel==1 pause
goto loop
