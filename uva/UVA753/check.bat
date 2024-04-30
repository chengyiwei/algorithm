@echo off
:loop
make_data
UVA753
UVA7530
fc UVA753.out UVA7530.out
if errorlevel==1 pause
goto loop
