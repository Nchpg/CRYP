@ECHO OFF
cd src

set txt = "src"
FOR /R "%CD%" %%f IN (*.c) DO (
   FOR /f "tokens=9 delims=\" %%a IN ("%%f") DO (
      FOR /f "tokens=1 delims=." %%b IN ("%%a") DO (
         echo %%b

         IF "%%b"=="CRYP" (gcc ROT.c CRYP.c -o ../CRYP)
         IF not "%%b"=="CRYP" cd ../ignoreMain
         IF not "%%b"=="CRYP" .\ignore.exe %%b
         IF not "%%b"=="CRYP" cd ../src
         IF not "%%b"=="CRYP" gcc %%b_tmp.c -o ../%%b
         IF not "%%b"=="CRYP" del %%b_tmp.c
   )
   )
)

:script


