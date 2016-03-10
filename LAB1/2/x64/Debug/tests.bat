REM запуск программы без параметров
2.exe
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы с одним нечисловым параметром
2.exe 1
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы с пустой строкой в качестве одного из параметров
2.exe "" 5 2
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы с одним числовым параметром (и проверяем результат)
test.exe 1 5 q
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы с двумя числовыми параметрами
2.exe 15 2 q
IF NOT ERRORLEVEL 1 GOTO err

2.exe 15 2 3
IF ERRORLEVEL 1 GOTO err

2.exe 2 1 1 > out
FC /B out 1
IF ERRORLEVEL 1 GOTO err

2.exe 4 3 1 > out
FC /B out -2 -10
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)

TIMEOUT /T 10 /NOBREAK
EXIT

:err
ECHOProgramtestingfailed :-(

TIMEOUT /T 10 /NOBREAK
EXIT