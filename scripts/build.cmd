@echo off

setlocal

set CURRENT_DIR=%~dp0

call %CURRENT_DIR%\thirdparty\pcre.cmd
call %CURRENT_DIR%\thirdparty\zlib.cmd
call %CURRENT_DIR%\thirdparty\cppcms.cmd

call %CURRENT_DIR%\app.cmd

endlocal
