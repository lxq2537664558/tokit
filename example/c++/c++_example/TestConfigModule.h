//------------------------------------------------------------------------------
// ���ļ��ɹ����Զ�����
//------------------------------------------------------------------------------

#pragma once

#include <string>
#include <map>
#include <vector>
#include <set>
#include "ConfigModule.h"

// ����������
struct TestConfig
{
	TestConfig()
	{
		Clear();
	}
	
	inline void Clear()
	{
	
		stringfield = "";
		
		boolfield = false;
		
		charfield = 0;
		
		int16field = 0;
		
		intfield = 0;
		
		int64field = 0;
		
		floatfield = 0.0f;
		
		doublefield = 0.0f;
		
		stringfieldunique = "";
		
		boolfieldunique = false;
		
		charfieldunique = 0;
		
		int16fieldunique = 0;
		
		intfieldunique = 0;
		
		int64fieldunique = 0;
		
		floatfieldunique = 0.0f;
		
		doublefieldunique = 0.0f;
		
		vecstringfieldarray.clear();
		
		vecboolfieldarray.clear();
		
		veccharfieldarray.clear();
		
		vecint16fieldarray.clear();
		
		vecintfieldarray.clear();
		
		vecint64fieldarray.clear();
		
		vecfloatfieldarray.clear();
		
		vecdoublefieldarray.clear();
		
	}
	
	std::string stringfield; // �ַ���
	
	bool boolfield; // bool��
	
	char charfield; // �ַ�
	
	int16 int16field; // 16λ����
	
	int intfield; // 32λ����
	
	int64 int64field; // 64λ����
	
	float floatfield; // ������
	
	double doublefield; // ˫���ȸ�����
	
	std::string stringfieldunique; // �ַ���Ψһ<Ψһ>
	
	bool boolfieldunique; // bool��Ψһ<Ψһ>
	
	char charfieldunique; // �ַ�Ψһ<Ψһ>
	
	int16 int16fieldunique; // 16λ����Ψһ<Ψһ>
	
	int intfieldunique; // 32λ����Ψһ<Ψһ>
	
	int64 int64fieldunique; // 64λ����Ψһ<Ψһ>
	
	float floatfieldunique; // ������Ψһ<Ψһ>
	
	double doublefieldunique; // ˫���ȸ�����Ψһ<Ψһ>
	
	std::vector<std::string> vecstringfieldarray; // �ַ�������<����=,>
	
	std::vector<bool> vecboolfieldarray; // bool������<����=,>
	
	std::vector<char> veccharfieldarray; // �ַ�����<����=,>
	
	std::vector<int16> vecint16fieldarray; // 16λ��������<����=,>
	
	std::vector<int> vecintfieldarray; // 32λ��������<����=,>
	
	std::vector<int64> vecint64fieldarray; // 64λ��������<����=,>
	
	std::vector<float> vecfloatfieldarray; // ����������<����=,>
	
	std::vector<double> vecdoublefieldarray; // ˫���ȸ���������<����=,>
	
};

class TestConfigModule : public IConfigModule
{
public:
	static TestConfigModule instance;

public:
	// ��ȡ������������
	const char* Name() override{ return "TestConfigModule"; }

public:
	
	// �������������
	bool LoadBinary(const std::string& basePath) override;

	bool LoadBinaryTestConfig(const std::string& basePath);

    // �������
    void Clear();
	
public:
	
	// �ַ���Ψһ
	const TestConfig* FindTestConfigBystringfieldunique(std::string stringfieldunique);

	// bool��Ψһ
	const TestConfig* FindTestConfigByboolfieldunique(bool boolfieldunique);

	// �ַ�Ψһ
	const TestConfig* FindTestConfigBycharfieldunique(char charfieldunique);

	// 16λ����Ψһ
	const TestConfig* FindTestConfigByint16fieldunique(int16 int16fieldunique);

	// 32λ����Ψһ
	const TestConfig* FindTestConfigByintfieldunique(int intfieldunique);

	// 64λ����Ψһ
	const TestConfig* FindTestConfigByint64fieldunique(int64 int64fieldunique);

	// ������Ψһ
	const TestConfig* FindTestConfigByfloatfieldunique(float floatfieldunique);

	// ˫���ȸ�����Ψһ
	const TestConfig* FindTestConfigBydoublefieldunique(double doublefieldunique);

public:
	
	// ����������
	std::vector<TestConfig> m_vecTestConfig;

	// �ַ���Ψһ
	std::map<std::string, TestConfig*> m_mapTestConfigBystringfieldunique;

	// bool��Ψһ
	std::map<bool, TestConfig*> m_mapTestConfigByboolfieldunique;

	// �ַ�Ψһ
	std::map<char, TestConfig*> m_mapTestConfigBycharfieldunique;

	// 16λ����Ψһ
	std::map<int16, TestConfig*> m_mapTestConfigByint16fieldunique;

	// 32λ����Ψһ
	std::map<int, TestConfig*> m_mapTestConfigByintfieldunique;

	// 64λ����Ψһ
	std::map<int64, TestConfig*> m_mapTestConfigByint64fieldunique;

	// ������Ψһ
	std::map<float, TestConfig*> m_mapTestConfigByfloatfieldunique;

	// ˫���ȸ�����Ψһ
	std::map<double, TestConfig*> m_mapTestConfigBydoublefieldunique;

};