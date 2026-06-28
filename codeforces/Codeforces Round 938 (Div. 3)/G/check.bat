@echo off
:loop
make_data.exe
G.exe
G0.exe
fc G.out G0.out
if errorlevel==1 pause
goto loop