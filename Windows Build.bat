@echo off

SETLOCAL EnableDelayedExpansion
set NL=^

REM randomly breaks
cd /d %~dp0

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

type .\src\functions.h >> %output%

type .\src\operators.h >> %output%

type .\src\types.h >> %output%

echo tail >> %output%

