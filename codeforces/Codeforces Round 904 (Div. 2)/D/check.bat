@echo off
:loop
D
D0
fc D.out D0.out
if errorlevel==1 pause
goto loop
