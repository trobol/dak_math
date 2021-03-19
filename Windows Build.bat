@echo off

SETLOCAL EnableDelayedExpansion
set NL=^


cd /d %~dp0
REM randomly breaks

REM set output file
set output=dak_math.h 

REM get git rev-parse
FOR /F "tokens=*" %%g IN ('git rev-parse --short HEAD') do (SET COMMIT=%%g)

REM relative LICENSE location
set LICENSE_LOC=LICENSE

REM gets date -> %mydate%
For /f "tokens=2-4 delims=/ " %%a in ('date /t') do (set mydate=%%c-%%a-%%b)

REM Header info
set HEAD_INFO1=/*!NL!THIS FILE IS GENERATED!NL!SOURCE: https://github.com/trobol/dak_math!NL!COMMIT SHA1: %COMMIT%!NL!DATE: %mydate%!NL!LICENSE: 
set HEAD_INFO2=*/!NL!#ifndef _DAK_MATH_H!NL!#define _DAK_MATH_H


set tail=#endif 


REM HEAD
	echo !HEAD_INFO1!>%output%
	for /F delims^=^ eol^= %%i in (%LICENSE_LOC%) do echo %%i>>%output%
	echo !HEAD_INFO2!!NL!>>%output% 


type .\src\constants.h >> %output%

type .\src\types.h >> %output%

type .\src\operators.h >> %output%

type .\src\functions.h >> %output%


echo !NL!%tail% >> %output%

set installed = 0

reg query "HKEY_CLASSES_ROOT\VisualStudio.DTE.16.0" >> nul 2>&1
if %ERRORLEVEL% NEQ 0 ( 
	
	echo VS 2019 not installed 

	reg query "HKEY_CLASSES_ROOT\VisualStudio.DTE.15.0" >> nul 2>&1 
	if %ERRORLEVEL% NEQ 0 ( 

		echo VS 2017 not installed 

		reg query "HKEY_CLASSES_ROOT\VisualStudio.DTE.14.0" >> nul 2>&1
		if %ERRORLEVEL% NEQ 0 ( 
	
			echo VS 2015 not installed 

			reg query "HKEY_CLASSES_ROOT\VisualStudio.DTE.12.0" >> nul 2>&1 
			if %ERRORLEVEL% NEQ 0 ( 

				echo Please install VisualStudio 2013 or higher
				pause

			) else ( 

				echo VS 2013 installed. 
				call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x86_amd64
				set installed=1
			) 

		) else ( 

			echo VS 2015 installed.
			call "C:\Program Files (x86)\Microsoft Visual Studio 15.0\VC\vcvarsall.bat" x86_amd64
			set installed=1
		) 
	) else ( 

		echo VS 2017 installed. 
		echo missing path
		echo if you find it please put it here
		echo https://github.com/trobol/dak_math
		REM call "C:\Program Files (x86)\Microsoft Visual Studio 15.0\VC\vcvarsall.bat" x86_amd64
		set installed=1

	) 

) else ( 

	echo VS 2019 installed.
	call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" x86_amd64
	set installed=1

) 


if %installed%==1 (
pause
cd /d %~dp0
pause
cl /Tp %output% test\test.cpp 
pause

)