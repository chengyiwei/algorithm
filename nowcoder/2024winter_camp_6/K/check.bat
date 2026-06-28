@echo off
:loop
make_data
K
K0
fc K.out K0.out
if errorlevel==1 pause
goto loop
