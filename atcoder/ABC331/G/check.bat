@echo off
:loop
make_data.exe
G
G0
fc G.out G0.out
if errorlevel==1 pause
goto loop