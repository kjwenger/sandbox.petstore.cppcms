@echo off

setlocal

set CURRENT_DIR="%cd%"
echo Current Dir: %CURRENT_DIR%
set PARENT_DIR=%~dp0
echo Batch File Parent Dir: %PARENT_DIR%
for %%A in ("%PARENT_DIR%") do set "THIRDPARTY_DIR=%%~dpA"
echo Third-party Dir: %THIRDPARTY_DIR%
for %%A in (%THIRDPARTY_DIR:~0,-1%) do set "SCRIPTS_DIR=%%~dpA"
echo Scripts Dir: %SCRIPTS_DIR%
for %%A in (%SCRIPTS_DIR:~0,-1%) do set "PROJECT_DIR=%%~dpA"
echo Project Dir: %PROJECT_DIR%
set USR_DIR="%PROJECT_DIR%\usr"
echo Usr Dir: %USR_DIR%

cd %THIRDPARTY_DIR%

git clone https://github.com/artyom-beilis/cppcms.git cppcms
cd cppcms
md build
cd build
@rem del /s /f /q *.*
cmake -G "MinGW Makefiles" ^
      -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON ^
      -DCMAKE_INSTALL_PREFIX=%USR_DIR% ^
      -DCMAKE_INCLUDE_PATH=%USR_DIR%\include ^
      -DCMAKE_LIBRARY_PATH=%USR_DIR%\lib ^
      -DDISABLE_GCRYPT=ON ^
      -DDISABLE_OPENSSL=ON ^
      ..
set VERBOSE=1
mingw32-make
mingw32-make install
cd ..
cd ..

cd %CURRENT_DIR%

endlocal