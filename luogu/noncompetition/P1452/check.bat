@echo off
:loop
make_data
P1452.exe
P14520.exe
FC out.out out0.out
if errorlevel==1 pause
goto loop