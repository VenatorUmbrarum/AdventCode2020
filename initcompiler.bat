::So I could probably have just called the batch file using the full path to the file
::And skipped all the cd's and saving directories and whatnot
::But at least this way I got an intro to batch variables

@echo off
set working_path="%cd%"
cd "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build"
call vcvars64.bat
cd %working_path%