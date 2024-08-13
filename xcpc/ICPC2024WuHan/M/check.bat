chcp 65001
@echo off
:loop
make_data.exe
M.exe
M0.exe
fc M.out M0.out
if errorlevel == 1 pause
goto loop
