REM запуск программы без параметров
3.exe
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы с одним не строковым параметром
3.exe 1
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы с пустой строкой в качестве одного из параметров
3.exe "" "m2.txt"
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы с неверным строковым параметром
3.exe "m1.txt" "err.txt"
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы с неправильной матрицой
3.exe "input/1/m1.txt" "input/1/m2.txt"
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы с проверкой вычисления
3.exe "input/2/m1.txt" "input/2/m2.txt"
FC /B result_martix.txt output/right_matrix2.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с проверкой вычисления2222
3.exe "input/3/m1.txt" "input/3/m2.txt"
FC /B result_martix.txt output/right_matrix3.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)
EXIT

:err
ECHO Programtestingfailed :-(
EXIT