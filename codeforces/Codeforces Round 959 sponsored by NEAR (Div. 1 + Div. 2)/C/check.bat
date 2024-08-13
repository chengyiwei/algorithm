@echo off
:loop
make_data
C
C0
Fc C.out C0.out
if errorlevel==1 pause
goto loop