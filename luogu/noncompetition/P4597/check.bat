@echo off
:loop
make_data
P4597
P45970
fc P4597.out P45970.out
if errorlevel==1 pause
goto loop
