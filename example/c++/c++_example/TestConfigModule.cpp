//------------------------------------------------------------
// ���ļ��ɹ����Զ�����
//------------------------------------------------------------

#include "TestConfigModule.h"
#include <iostream>
#include "tokit_tool.h"

TestConfigModule TestConfigModule::instance;

// �ַ���Ψһ
const TestConfig* TestConfigModule::FindTestConfigBystringfieldunique(std::string stringfieldunique)
{
	const auto itr = m_mapTestConfigBystringfieldunique.find(stringfieldunique);
	if (itr == m_mapTestConfigBystringfieldunique.end())
	{
		return nullptr;
	}

	const TestConfig* ret = itr->second;
	return ret;
}

// bool��Ψһ
const TestConfig* TestConfigModule::FindTestConfigByboolfieldunique(bool boolfieldunique)
{
	const auto itr = m_mapTestConfigByboolfieldunique.find(boolfieldunique);
	if (itr == m_mapTestConfigByboolfieldunique.end())
	{
		return nullptr;
	}

	const TestConfig* ret = itr->second;
	return ret;
}

// �ַ�Ψһ
const TestConfig* TestConfigModule::FindTestConfigBycharfieldunique(char charfieldunique)
{
	const auto itr = m_mapTestConfigBycharfieldunique.find(charfieldunique);
	if (itr == m_mapTestConfigBycharfieldunique.end())
	{
		return nullptr;
	}

	const TestConfig* ret = itr->second;
	return ret;
}

// 16λ����Ψһ
const TestConfig* TestConfigModule::FindTestConfigByint16fieldunique(int16 int16fieldunique)
{
	const auto itr = m_mapTestConfigByint16fieldunique.find(int16fieldunique);
	if (itr == m_mapTestConfigByint16fieldunique.end())
	{
		return nullptr;
	}

	const TestConfig* ret = itr->second;
	return ret;
}

// 32λ����Ψһ
const TestConfig* TestConfigModule::FindTestConfigByintfieldunique(int intfieldunique)
{
	const auto itr = m_mapTestConfigByintfieldunique.find(intfieldunique);
	if (itr == m_mapTestConfigByintfieldunique.end())
	{
		return nullptr;
	}

	const TestConfig* ret = itr->second;
	return ret;
}

// 64λ����Ψһ
const TestConfig* TestConfigModule::FindTestConfigByint64fieldunique(int64 int64fieldunique)
{
	const auto itr = m_mapTestConfigByint64fieldunique.find(int64fieldunique);
	if (itr == m_mapTestConfigByint64fieldunique.end())
	{
		return nullptr;
	}

	const TestConfig* ret = itr->second;
	return ret;
}

// ������Ψһ
const TestConfig* TestConfigModule::FindTestConfigByfloatfieldunique(float floatfieldunique)
{
	const auto itr = m_mapTestConfigByfloatfieldunique.find(floatfieldunique);
	if (itr == m_mapTestConfigByfloatfieldunique.end())
	{
		return nullptr;
	}

	const TestConfig* ret = itr->second;
	return ret;
}

// ˫���ȸ�����Ψһ
const TestConfig* TestConfigModule::FindTestConfigBydoublefieldunique(double doublefieldunique)
{
	const auto itr = m_mapTestConfigBydoublefieldunique.find(doublefieldunique);
	if (itr == m_mapTestConfigBydoublefieldunique.end())
	{
		return nullptr;
	}

	const TestConfig* ret = itr->second;
	return ret;
}

void TestConfigModule::Clear()
{

	m_vecTestConfig.clear();

	m_mapTestConfigBystringfieldunique.clear();
	m_mapTestConfigByboolfieldunique.clear();
	m_mapTestConfigBycharfieldunique.clear();
	m_mapTestConfigByint16fieldunique.clear();
	m_mapTestConfigByintfieldunique.clear();
	m_mapTestConfigByint64fieldunique.clear();
	m_mapTestConfigByfloatfieldunique.clear();
	m_mapTestConfigBydoublefieldunique.clear();

}

bool TestConfigModule::LoadBinaryTestConfig(const std::string& basePath)
{
	std::string binaryPath = basePath + "TestConfig.bin";
	std::string binaryText;
	if (!tool::GetFileText(binaryPath.c_str(), binaryText))
	{
		std::cerr << "[error] parse failed, not found the file <" << binaryPath << ">!\n";
		return false;
	}
	
	const char* buffer = binaryText.c_str();
	int size = (int)binaryText.size();
	if (size < sizeof(int))
	{
		std::cerr << "[error] parse file <" << binaryPath << "> failed, size = " << size << " is invalid, must >= " << sizeof(int) << "!\n";
		return false;
	}
	
	// ȡ������
	int rowCount = *((int*)buffer);
	if (rowCount < 0 || rowCount >= 1000000)
	{
		std::cerr << "[error] parse file <" << binaryPath << "> failed, size = " << size << " is invalid!\n";
		return false;
	}
	
	m_vecTestConfig.resize(rowCount);
	
	for (int peek = sizeof(int), rowIndex = 0; peek < size && rowIndex < rowCount; ++rowIndex)
	{
	
		TestConfig& row = m_vecTestConfig[rowIndex];
	
		// ������������
	
		if (!ConfigModule::ReadString(buffer, peek, row.stringfield))
		{
			std::cerr << "����" << binaryPath << "����������ʧ�ܣ�ԭ����stringfield�ַ������Ϸ� = " << peek;
			return false;
		}		
		
		row.boolfield = (buffer[peek] != '\0');peek += sizeof(bool);
		
		row.charfield = buffer[peek];peek += sizeof(char);
		
		row.int16field = *((int16*)(buffer + peek));peek += sizeof(int16);
		
		row.intfield = *((int*)(buffer + peek));peek += sizeof(int);
		
		row.int64field = *((int64*)(buffer + peek));peek += sizeof(int64);
		
		row.floatfield = *((float*)(buffer + peek));peek += sizeof(float);
		
		row.doublefield = *((double*)(buffer + peek));peek += sizeof(double);
		
		if (!ConfigModule::ReadString(buffer, peek, row.stringfieldunique))
		{
			std::cerr << "����" << binaryPath << "����������ʧ�ܣ�ԭ����stringfieldunique�ַ������Ϸ� = " << peek;
			return false;
		}		
		
		row.boolfieldunique = (buffer[peek] != '\0');peek += sizeof(bool);
		
		row.charfieldunique = buffer[peek];peek += sizeof(char);
		
		row.int16fieldunique = *((int16*)(buffer + peek));peek += sizeof(int16);
		
		row.intfieldunique = *((int*)(buffer + peek));peek += sizeof(int);
		
		row.int64fieldunique = *((int64*)(buffer + peek));peek += sizeof(int64);
		
		row.floatfieldunique = *((float*)(buffer + peek));peek += sizeof(float);
		
		row.doublefieldunique = *((double*)(buffer + peek));peek += sizeof(double);
		
		int stringfieldarrayArraySize = *((int*)(buffer + peek));
		peek += sizeof(int);
		
		if (!ConfigModule::IsArraySizeValid(stringfieldarrayArraySize))
		{
			std::cerr << "����" << binaryPath << "����������ʧ�ܣ�ԭ���Ƕ�ȡ��stringfieldarray���鳤�Ȳ��Ϸ� = " << stringfieldarrayArraySize;
			return false;
		}
		
		row.vecstringfieldarray.resize(stringfieldarrayArraySize);
		
		for (int i = 0; i < stringfieldarrayArraySize; ++i)
		{
			
			if (!ConfigModule::ReadString(buffer, peek, row.vecstringfieldarray[i]))
			{
				std::cerr << "����" << binaryPath << "����������ʧ�ܣ�ԭ����stringfieldarray�����е��ַ������Ϸ� = " << peek;
				return false;
			}
			
		}				
		
		int boolfieldarrayArraySize = *((int*)(buffer + peek));
		peek += sizeof(int);
		
		if (!ConfigModule::IsArraySizeValid(boolfieldarrayArraySize))
		{
			std::cerr << "����" << binaryPath << "����������ʧ�ܣ�ԭ���Ƕ�ȡ��boolfieldarray���鳤�Ȳ��Ϸ� = " << boolfieldarrayArraySize;
			return false;
		}
		
		row.vecboolfieldarray.resize(boolfieldarrayArraySize);
		
		for (int i = 0; i < boolfieldarrayArraySize; ++i)
		{
			row.vecboolfieldarray[i] = (buffer[peek] != '\0');peek += sizeof(bool);
			
		}				
		
		int charfieldarrayArraySize = *((int*)(buffer + peek));
		peek += sizeof(int);
		
		if (!ConfigModule::IsArraySizeValid(charfieldarrayArraySize))
		{
			std::cerr << "����" << binaryPath << "����������ʧ�ܣ�ԭ���Ƕ�ȡ��charfieldarray���鳤�Ȳ��Ϸ� = " << charfieldarrayArraySize;
			return false;
		}
		
		row.veccharfieldarray.resize(charfieldarrayArraySize);
		
		for (int i = 0; i < charfieldarrayArraySize; ++i)
		{
			row.veccharfieldarray[i] = buffer[peek];peek += sizeof(char);
			
		}				
		
		int int16fieldarrayArraySize = *((int*)(buffer + peek));
		peek += sizeof(int);
		
		if (!ConfigModule::IsArraySizeValid(int16fieldarrayArraySize))
		{
			std::cerr << "����" << binaryPath << "����������ʧ�ܣ�ԭ���Ƕ�ȡ��int16fieldarray���鳤�Ȳ��Ϸ� = " << int16fieldarrayArraySize;
			return false;
		}
		
		row.vecint16fieldarray.resize(int16fieldarrayArraySize);
		
		for (int i = 0; i < int16fieldarrayArraySize; ++i)
		{
			row.vecint16fieldarray[i] = *((int16*)(buffer + peek));peek += sizeof(int16);
			
		}				
		
		int intfieldarrayArraySize = *((int*)(buffer + peek));
		peek += sizeof(int);
		
		if (!ConfigModule::IsArraySizeValid(intfieldarrayArraySize))
		{
			std::cerr << "����" << binaryPath << "����������ʧ�ܣ�ԭ���Ƕ�ȡ��intfieldarray���鳤�Ȳ��Ϸ� = " << intfieldarrayArraySize;
			return false;
		}
		
		row.vecintfieldarray.resize(intfieldarrayArraySize);
		
		for (int i = 0; i < intfieldarrayArraySize; ++i)
		{
			row.vecintfieldarray[i] = *((int*)(buffer + peek));peek += sizeof(int);
			
		}				
		
		int int64fieldarrayArraySize = *((int*)(buffer + peek));
		peek += sizeof(int);
		
		if (!ConfigModule::IsArraySizeValid(int64fieldarrayArraySize))
		{
			std::cerr << "����" << binaryPath << "����������ʧ�ܣ�ԭ���Ƕ�ȡ��int64fieldarray���鳤�Ȳ��Ϸ� = " << int64fieldarrayArraySize;
			return false;
		}
		
		row.vecint64fieldarray.resize(int64fieldarrayArraySize);
		
		for (int i = 0; i < int64fieldarrayArraySize; ++i)
		{
			row.vecint64fieldarray[i] = *((int64*)(buffer + peek));peek += sizeof(int64);
			
		}				
		
		int floatfieldarrayArraySize = *((int*)(buffer + peek));
		peek += sizeof(int);
		
		if (!ConfigModule::IsArraySizeValid(floatfieldarrayArraySize))
		{
			std::cerr << "����" << binaryPath << "����������ʧ�ܣ�ԭ���Ƕ�ȡ��floatfieldarray���鳤�Ȳ��Ϸ� = " << floatfieldarrayArraySize;
			return false;
		}
		
		row.vecfloatfieldarray.resize(floatfieldarrayArraySize);
		
		for (int i = 0; i < floatfieldarrayArraySize; ++i)
		{
			row.vecfloatfieldarray[i] = *((float*)(buffer + peek));peek += sizeof(float);
			
		}				
		
		int doublefieldarrayArraySize = *((int*)(buffer + peek));
		peek += sizeof(int);
		
		if (!ConfigModule::IsArraySizeValid(doublefieldarrayArraySize))
		{
			std::cerr << "����" << binaryPath << "����������ʧ�ܣ�ԭ���Ƕ�ȡ��doublefieldarray���鳤�Ȳ��Ϸ� = " << doublefieldarrayArraySize;
			return false;
		}
		
		row.vecdoublefieldarray.resize(doublefieldarrayArraySize);
		
		for (int i = 0; i < doublefieldarrayArraySize; ++i)
		{
			row.vecdoublefieldarray[i] = *((double*)(buffer + peek));peek += sizeof(double);
			
		}				
		
	}
	
	for (int i = 0, size = (int)m_vecTestConfig.size(); i < size; ++i)
	{
		TestConfig& row = m_vecTestConfig[i];
		
		m_mapTestConfigBystringfieldunique[row.stringfieldunique] = &row;
		
		m_mapTestConfigByboolfieldunique[row.boolfieldunique] = &row;
		
		m_mapTestConfigBycharfieldunique[row.charfieldunique] = &row;
		
		m_mapTestConfigByint16fieldunique[row.int16fieldunique] = &row;
		
		m_mapTestConfigByintfieldunique[row.intfieldunique] = &row;
		
		m_mapTestConfigByint64fieldunique[row.int64fieldunique] = &row;
		
		m_mapTestConfigByfloatfieldunique[row.floatfieldunique] = &row;
		
		m_mapTestConfigBydoublefieldunique[row.doublefieldunique] = &row;
		
	}
	
	return true;
}

bool TestConfigModule::LoadBinary(const std::string& basePath)
{
	Clear();
		
	if (!LoadBinaryTestConfig(basePath))
	{
		return false;
	}
	
	return true;
}