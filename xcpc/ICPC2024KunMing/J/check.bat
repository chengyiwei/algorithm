@echo off
:loop
make_data
J
J0
fc J.out J0.out
if errorlevel==1 pause
goto loop