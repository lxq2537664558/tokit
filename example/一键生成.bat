@echo off
rem ��ע��excel_dir=excel�ļ���·��
set excel_dir=./excel/

rem ��ע��tool=�����ߵ�·��
set tool=.\tool\tokit.exe

rem ��ע��gen_dir=���ɵ��ļ������ĸ��ļ���
set gen_dir=./

rem ��ע��template=ģ���ļ���·��
set template=D:\proj\mine\tokit\example\tool

rem �������һ��windows��������Ĺ���
rem 	��ע��%~dp0 =��ǰ�̷�+·������: d:\xxx\xxx
rem
rem ͬʱ�����������forѭ���У����ַ��ŵĺ�������
rem 	��ע��%%s   =��ȫ�ļ�·����  ��: d:\abc.txt�����е�s�����Ǳ����ĸ����%%x
rem 	��ע��%%~nxs=�ļ�������չ��  ��: abc.txt
rem 	��ע��%%~ns =�ļ���������չ����: abc

echo 1. ����c#�ļ�
    for /F %%x in ('dir /b /a-d /s "%excel_dir%\*.xlsx"') do (
        echo ���ڴ���[ %%x ]
        %tool% %%x ^
			-template %template%\C#Template.cs -out %gen_dir%\c#\CSharpExample\CSharpExample ^
			-template %template%\JsonTemplate.json -split-out %gen_dir%\json\ ^
			-template %template%\C++Template.cpp %template%\C++Template.h -out %gen_dir%\c++\c++_example\cfg
    )

pause