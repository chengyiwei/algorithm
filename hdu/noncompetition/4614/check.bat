@echo off
:loop
make_data
4614
46140
fc 4614.out 46140.out 
if errorlevel==1 pause
goto loop