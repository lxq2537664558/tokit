@echo off
set excel_dir=excel
set copy_dir=�����ļ�
set tool=.\tool\tokit.exe
set template=.\tool

echo 1. ������ʱ�ļ�
	xcopy %excel_dir% %copy_dir% /D /Y

echo 2. �����ļ�
    for /F %%x in ('dir /b /a-d /s "%copy_dir%\*.xlsx"') do (
        echo ���ڴ���[ %%x ]
        %tool% %%x ^
			-template %template%\JsonTemplate.json -split-out "json" ^
			-template %template%\C#BinaryTemplate.bin -split-out "c#\CSharpExample\binary" ^
			-template %template%\C#Template.cs -out "c#\CSharpExample" ^
			-template %template%\C++BinaryTemplate.bin -split-out "c++\c++_example\binary" ^
			-template %template%\C++Template.cpp %template%\C++Template.h -out "c++\c++_example"			
    )

echo.

pause
rem echo ���ɽ�����8����Զ��رգ�
rem @choice /t 8 /d y /n >nul