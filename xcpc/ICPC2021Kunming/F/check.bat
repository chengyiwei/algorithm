@echo off
:lo
make_data.exe
F.exe
F0.exe
fc F.out F0.out
if errorlevel==1 pause
goto lo
