#include <iostream>
#include "ConfigModule.h"
#include "TestConfigModule.h"

bool ConfigModule::Init()
{
	// ע��ģ��
	RegisterConfig(TestConfigModule::instance);
	return Reload();
}

bool ConfigModule::Reload()
{
	// std::string clientResourcePath = "E:\\proj\\mine\\game\\client\\Config\\";
	m_resourcePath = "binary\\";

	bool ok = true;

	// ��ʼ����ÿ��ģ�������
	for (int i = 0; i < (int)m_vecConfigModule.size(); ++i)
	{
		IConfigModule* configModule = m_vecConfigModule[i];

		// ͨ�������Ʒ�ʽ��ȡ
		if (!configModule->LoadBinary(m_resourcePath))
		{
			ok = false;
		}
	}

	return ok;
}

bool ConfigModule::RegisterConfig(IConfigModule& configModule)
{
	m_vecConfigModule.push_back(&configModule);
	return true;
}

bool ConfigModule::ReadString(const char* buffer, int& peek, std::string& str)
{
	// �ڴ�ֲ���|  �ַ�����С(int)  |  �ַ�������(char[])  |
	int stringSize = *((int*)(buffer + peek));
	peek += sizeof(int);

	if (stringSize == 0)
	{
		// ���ַ�����������
		return true;
	}

	int before = peek;
	peek += stringSize;

	if (stringSize < 0 || stringSize > 1000000)
	{
		std::cerr << "���ض���������ʧ�ܣ�ԭ�� = ��ȡ�ַ���ʱ����ȡ�����ַ������Ȳ��Ϸ� = " <<  stringSize;
		return false;
	}

	str.append(buffer + before, stringSize);
	return true;
}

bool ConfigModule::IsArraySizeValid(int arraySize)
{
	if (arraySize == 0)
	{
		return true;
	}

	if (arraySize < 0 || arraySize > 1000000)
	{
		std::cerr << "���ض���������ʧ�ܣ�ԭ�� = ��ȡ����ʱ����ȡ���鳤�Ȳ��Ϸ� = " << arraySize;
		return false;
	}

	return true;
}