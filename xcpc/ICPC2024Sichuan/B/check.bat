@echo off
:loop
make
B
B0
fc B.out B0.out
if errorlevel==1 pause
goto loop