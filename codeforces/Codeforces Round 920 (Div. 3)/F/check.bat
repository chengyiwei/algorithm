@echo off
:loop
make_data
F.exe
F0.exe
fc F.out F0.out
if errorlevel==1 pause
goto loop
