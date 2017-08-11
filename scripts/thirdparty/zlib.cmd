@echo off

setlocal

set CURRENT_DIR=%cd%
echo Current Dir: %CURRENT_DIR%
set PARENT_DIR=%~dp0
echo Batch File Parent Dir: %PARENT_DIR%
for %%A in ("%PARENT_DIR%") do set "THIRDPARTY_DIR=%%~dpA"
echo Third-party Dir: %THIRDPARTY_DIR%
for %%A in (%THIRDPARTY_DIR:~0,-1%) do set "SCRIPTS_DIR=%%~dpA"
echo Scripts Dir: %SCRIPTS_DIR%
for %%A in (%SCRIPTS_DIR:~0,-1%) do set "PROJECT_DIR=%%~dpA"
echo Project Dir: %PROJECT_DIR%
set USR_DIR=%PROJECT_DIR%usr
echo Usr Dir: %USR_DIR%
set ZLIB_DIR=%THIRDPARTY_DIR%\zlib
echo Zlib Dir: %ZLIB_DIR%
set TMP_DIR=%PROJECT_DIR%\tmp
echo Tmp Dir: %TMP_DIR%

md %ZLIB_DIR%
md %TMP_DIR%
cd %TMP_DIR%
wget -c https://netix.dl.sourceforge.net/project/gnuwin32/zlib/1.2.3/zlib-1.2.3-src.zip
unzip -o -d zlib-1.2.3-src zlib-1.2.3-src.zip
xcopy /s /e /y %TMP_DIR%\zlib-1.2.3-src\src\zlib\1.2.3\zlib-1.2.3\*.* %ZLIB_DIR%
cd %CURRENT_DIR%

cd %THIRDPARTY_DIR%
cd zlib
set PREFIX=%USR_DIR%
set INCLUDE_PATH=%PREFIX%\include
set LIBRARY_PATH=%PREFIX%\lib
set INSTALL=copy /b
mingw32-make -j -f win32\Makefile.gcc libz.a zlib1.dll libzdll.a
@rem mingw32-make -f win32\Makefile.gcc install
copy /b /y zlib.h %INCLUDE_PATH%
copy /b /y zconf.h %INCLUDE_PATH%
copy /b /y libz.a %LIBRARY_PATH%
copy /b /y libzdll.a %LIBRARY_PATH%
cd ..
cd ..
cd %CURRENT_DIR%

endlocal