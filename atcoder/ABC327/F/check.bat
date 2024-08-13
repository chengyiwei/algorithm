@echo off
:loop
make_data
F
F1
fc F.out F1.out
if errorlevel == 1 pause
goto loop
