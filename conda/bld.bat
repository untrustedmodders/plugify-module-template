@echo off
REM bld.bat - For Windows builds

REM Create the target directories
if not exist "%PREFIX%\bin" mkdir "%PREFIX%\bin"
if not exist "%PREFIX%" mkdir "%PREFIX%"

REM Copy the DLL and module file
copy bin\plugify-module-template.dll "%PREFIX%\bin\" || exit 1
copy plugify-module-template.pmodule "%PREFIX%\" || exit 1

REM Create activation scripts
if not exist "%PREFIX%\etc\conda\activate.d" mkdir "%PREFIX%\etc\conda\activate.d"
if not exist "%PREFIX%\etc\conda\deactivate.d" mkdir "%PREFIX%\etc\conda\deactivate.d"

REM Create activation script
echo @echo off > "%PREFIX%\etc\conda\activate.d\plugify-module-template.bat"
echo set "PLUGIFY_LM_MODULE_PATH=%%CONDA_PREFIX%%;%%PLUGIFY_LM_MODULE_PATH%%" >> "%PREFIX%\etc\conda\activate.d\plugify-module-template.bat"

REM Create deactivation script  
echo @echo off > "%PREFIX%\etc\conda\deactivate.d\plugify-module-template.bat"
echo set "PLUGIFY_LM_MODULE_PATH=%%PLUGIFY_LM_MODULE_PATH:%%CONDA_PREFIX%%;=%%" >> "%PREFIX%\etc\conda\deactivate.d\plugify-module-template.bat"

exit 0
