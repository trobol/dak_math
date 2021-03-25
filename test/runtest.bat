@echo  off

REM data to upload
set data_loc=data.txt

REM move here
cd /D %~dp0

REM get access token and decode it to data.decode
certutil -f -decode %data_loc% data.decode

REM curl -i -X GET www.google.com

REM curl -i -X PUT -H 'Authorization: token 4d013330xxxxxxxxxxxxxx' -d "{\"path\": \"mattei.csv\", \
REM \"message\": \"update\", \"content\": \"$(openssl base64 -A -in $cartella/mattei.csv)\", \"branch\": \"master\",\
REM \"sha\": $(curl -X GET https://api.github.com/repos/username/repo/contents/mattei.csv | jq .sha)}" \
REM https://api.github.com/repos/username/repo/contents/mattei.csv


REM no witnesses
del data.decode


REM EVEYTHING BELOW THIS IS BAD 
REM REEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
REM saving for later tho- just in case

echo get date and time
REM get hostname, date and time
FOR /F "usebackq" %%i IN (`hostname`) DO SET HOSTNAME=%%i
for /f "tokens=2 delims==" %%I in ('wmic os get localdatetime /format:list') do set datetime=%%I

echo format date and time
REM format date and time
set datetime=%datetime:~0,8%-%datetime:~8,6%
for /f "tokens=2 delims==" %%I in ('wmic datafile where name^="%file:\=\\%" get lastmodified /format:list') do set datetime=%%I

echo filename
REM set filename
set filename=%~dp0results\%HOSTNAME%--%datetime%.data

echo make new file
REM create data with file
echo "this data is fake" >> %filename%

REM make post request to API

