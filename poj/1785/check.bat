@echo off
:loop
make_data
1785.exe
17850.exe
fc 1785.out 17850.out
if errorlevel==1 pause
goto loop