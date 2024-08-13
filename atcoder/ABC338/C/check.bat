@echo off
:loop
make
C
C0
fc C.out C0.out
if errorlevel==1 pause
goto loop