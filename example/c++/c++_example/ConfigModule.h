#pragma once
#include <vector>

class IConfigModule
{
public:
	virtual const char* Name() = 0;

	virtual bool LoadBinary(const std::string& configDirectory) = 0;
};

// ����ģ�飨����ͳһ�������õļ��أ�
class ConfigModule
{
public:
	// ��ʼ��
	bool Init();

	// ��������
	bool Reload();

	// ע��һ������ģ��
	bool RegisterConfig(IConfigModule& configModule);

public:
	// �Ӷ����ƴ��ж�ȡ�ַ���
	static bool ReadString(const char* buffer, int& peek, std::string& str);

	// �����С�Ƿ�Ϸ�
	static bool IsArraySizeValid(int arraySize);

public:
	std::string m_resourcePath;

	std::vector<IConfigModule*> m_vecConfigModule;
};