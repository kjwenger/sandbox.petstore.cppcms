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

cd %THIRDPARTY_DIR%
svn co svn://vcs.exim.org/pcre/code/trunk pcre
cd pcre
md build
cd build
@rem del /s /f /q *.*
cmake -G "MinGW Makefiles" ^
      -DCMAKE_INSTALL_PREFIX="%USR_DIR%" ^
      ..
mingw32-make -j
mingw32-make -j install
cd ..
cd %CURRENT_DIR%

endlocal