@echo off
pushd %cd%
call "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" x64
popd
echo %cd%
set compilerflags=/Od /EHsc /Zi
set linkerflags=/OUT:"%~n1.exe"
cl.exe %compilerflags% %1 /link %linkerflags%