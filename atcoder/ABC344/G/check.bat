@echo off
:loop
make_data
G
G0
fc G.out G0.out
if errorlevel==1 pause
goto loop
