@echo off

g++ -o me me.cpp
for %%i in (1, 2) do (
    me < in%%i.in > out.out
    fc out.out ans%%i.out
    if errorlevel==1 pause
)

g++ -o data data.cpp
g++ -o std std.cpp

:loop
data > in.in
me < in.in > out.out
std < in.in > ans.out
fc ans.out out.out
if errorlevel==1 pause
goto loop