@echo off

g++ -o me me.cpp
for %%i in (1, 2, 3) do (
    me < in%%i.in > out.out
    fc out.out ans%%i.out
    if errorlevel==1 pause
)