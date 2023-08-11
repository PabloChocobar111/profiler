@echo off
set filename=profiler
cl /nologo /FC /Fo"%CD%\executables"\ /Fe"%CD%\executables\%filename%" "src\*.c" 

echo executing...
"%CD%\executables\%filename%"