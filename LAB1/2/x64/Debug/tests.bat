REM ������ ��������� ��� ����������
2.exe
IF NOT ERRORLEVEL 1 GOTO err

REM ������ ��������� � ����� ���������� ����������
2.exe 1
IF NOT ERRORLEVEL 1 GOTO err

REM ������ ��������� � ������ ������� � �������� ������ �� ����������
2.exe "" 5 2
IF NOT ERRORLEVEL 1 GOTO err

REM ������ ��������� � ����� �������� ���������� (� ��������� ���������)
test.exe 1 5 q
IF NOT ERRORLEVEL 1 GOTO err

REM ������ ��������� � ����� ��������� �����������
2.exe 15 2 q
IF NOT ERRORLEVEL 1 GOTO err

2.exe 2 1 1 > out
FC /B out output/out1.txt
IF ERRORLEVEL 1 GOTO err

2.exe 4 3 1 > out
FC /B out output/out2.txt
IF ERRORLEVEL 1 GOTO err

2.exe 30.58 12.28 5.21 > out
FC /B out output/out3.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Programtestingfailed :-(

EXIT