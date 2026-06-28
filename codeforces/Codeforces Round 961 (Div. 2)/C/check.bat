@echo off
:loop
make_data
C.exe
C0.exe
Fc C.out C0.out
if errorlevel==1 pause
goto loop