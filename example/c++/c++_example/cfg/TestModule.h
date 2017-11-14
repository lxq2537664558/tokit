//------------------------------------------------------------------------------
// ��ͷ�ļ��ɹ����Զ����ɣ������ڱ��ļ������Ķ�
// ���ڣ�
//------------------------------------------------------------------------------

#pragma once

#include <string>
#include <map>
#include <vector>
#include <set>






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
		
	
		uint8field = 0;
		
	
		uint16field = 0;
		
	
		uintfield = 0;
		
	
		uint64field = 0;
		
	
		floatfield = 0.0f;
		
	
		doublefield = 0.0f;
		
	
		stringfieldprimary = "";
		
	
		boolfieldprimary = false;
		
	
		charfieldprimary = 0;
		
	
		int16fieldprimary = 0;
		
	
		intfieldprimary = 0;
		
	
		int64fieldprimary = 0;
		
	
		uint8fieldprimary = 0;
		
	
		uint16fieldprimary = 0;
		
	
		uintfieldprimary = 0;
		
	
		uint64fieldprimary = 0;
		
	
		floatfieldprimary = 0.0f;
		
	
		doublefieldprimary = 0.0f;
		
	
		stringfieldunique = "";
		
	
		boolfieldunique = false;
		
	
		charfieldunique = 0;
		
	
		int16fieldunique = 0;
		
	
		intfieldunique = 0;
		
	
		int64fieldunique = 0;
		
	
		uint8fieldunique = 0;
		
	
		uint16fieldunique = 0;
		
	
		uintfieldunique = 0;
		
	
		uint64fieldunique = 0;
		
	
		floatfieldunique = 0.0f;
		
	
		doublefieldunique = 0.0f;
		
	
		vecstringfieldarray.clear();
		
	
		vecboolfieldarray.clear();
		
	
		veccharfieldarray.clear();
		
	
		vecint16fieldarray.clear();
		
	
		vecintfieldarray.clear();
		
	
		vecint64fieldarray.clear();
		
	
		vecuint8fieldarray.clear();
		
	
		vecuint16fieldarray.clear();
		
	
		vecuintfieldarray.clear();
		
	
		vecuint64fieldarray.clear();
		
	
		vecfloatfieldarray.clear();
		
	
		vecdoublefieldarray.clear();
		
	
		setstringfieldset.clear();
		
	
		setboolfieldset.clear();
		
	
		setcharfieldset.clear();
		
	
		setint16fieldset.clear();
		
	
		setintfieldset.clear();
		
	
		setint64fieldset.clear();
		
	
		setuint8fieldset.clear();
		
	
		setuint16fieldset.clear();
		
	
		setuintfieldset.clear();
		
	
		setuint64fieldset.clear();
		
	
		setfloatfieldset.clear();
		
	
		setdoublefieldset.clear();
		
	
	}
	
	std::string stringfield; // �ַ���
	bool boolfield; // bool��
	char charfield; // �ַ�
	int int16field; // 16λ����
	int intfield; // 32λ����
	long int64field; // 64λ����
	int uint8field; // 8λ�޷�������
	int uint16field; // 16λ�޷�������
	int uintfield; // 32λ�޷�������
	int64_t uint64field; // 64λ�޷�������
	float floatfield; // ������
	double doublefield; // ˫���ȸ�����
	std::string stringfieldprimary; // �ַ�������<����>
	bool boolfieldprimary; // bool������<����>
	char charfieldprimary; // �ַ�����<����>
	int int16fieldprimary; // 16λ��������<����>
	int intfieldprimary; // 32λ��������<����>
	long int64fieldprimary; // 64λ��������<����>
	int uint8fieldprimary; // 8λ�޷�����������<����>
	int uint16fieldprimary; // 16λ�޷�����������<����>
	int uintfieldprimary; // 32λ�޷�����������<����>
	int64_t uint64fieldprimary; // 64λ�޷�����������<����>
	float floatfieldprimary; // ����������
	double doublefieldprimary; // ˫���ȸ���������
	std::string stringfieldunique; // �ַ���Ψһ<Ψһ>
	bool boolfieldunique; // bool��Ψһ<Ψһ>
	char charfieldunique; // �ַ�Ψһ<Ψһ>
	int int16fieldunique; // 16λ����Ψһ<Ψһ>
	int intfieldunique; // 32λ����Ψһ<Ψһ>
	long int64fieldunique; // 64λ����Ψһ<Ψһ>
	int uint8fieldunique; // 8λ�޷�������Ψһ<Ψһ>
	int uint16fieldunique; // 16λ�޷�������Ψһ<Ψһ>
	int uintfieldunique; // 32λ�޷�������Ψһ<Ψһ>
	int64_t uint64fieldunique; // 64λ�޷�������Ψһ<Ψһ>
	float floatfieldunique; // ������Ψһ<Ψһ>
	double doublefieldunique; // ˫���ȸ�����Ψһ<Ψһ>
	std::vector<std::string> vecstringfieldarray; // �ַ�������<����>
	std::vector<bool> vecboolfieldarray; // bool������<����>
	std::vector<char> veccharfieldarray; // �ַ�����<����>
	std::vector<int> vecint16fieldarray; // 16λ��������<����>
	std::vector<int> vecintfieldarray; // 32λ��������<����>
	std::vector<long> vecint64fieldarray; // 64λ��������<����>
	std::vector<int> vecuint8fieldarray; // 8λ�޷�����������<����>
	std::vector<int> vecuint16fieldarray; // 16λ�޷�����������<����>
	std::vector<int> vecuintfieldarray; // 32λ�޷�����������<����>
	std::vector<int64_t> vecuint64fieldarray; // 64λ�޷�����������<����>
	std::vector<float> vecfloatfieldarray; // ����������<����>
	std::vector<double> vecdoublefieldarray; // ˫���ȸ���������<����>
	std::set<std::string> setstringfieldset; // �ַ�������<����>
	std::set<bool> setboolfieldset; // bool�ͼ���<����>
	std::set<char> setcharfieldset; // �ַ�����<����>
	std::set<int> setint16fieldset; // 16λ��������<����>
	std::set<int> setintfieldset; // 32λ��������<����>
	std::set<long> setint64fieldset; // 64λ��������<����>
	std::set<int> setuint8fieldset; // 8λ�޷�����������<����>
	std::set<int> setuint16fieldset; // 16λ�޷�����������<����>
	std::set<int> setuintfieldset; // 32λ�޷�����������<����>
	std::set<int64_t> setuint64fieldset; // 64λ�޷�����������<����>
	std::set<float> setfloatfieldset; // ����������<����>
	std::set<double> setdoublefieldset; // ˫���ȸ���������<����>
	
};















class TestModule
{
public:
	static TestModule instance;

public:
	// ��ȡ������������
	const char* Name(){ return "TestModule"; }

public:
	
	// ��������
	bool Load(std::string basePath);


	bool LoadTestConfig(std::string basePath);



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
	const TestConfig* FindTestConfigByint16fieldunique(int int16fieldunique);

	// 32λ����Ψһ
	const TestConfig* FindTestConfigByintfieldunique(int intfieldunique);

	// 64λ����Ψһ
	const TestConfig* FindTestConfigByint64fieldunique(long int64fieldunique);

	// 8λ�޷�������Ψһ
	const TestConfig* FindTestConfigByuint8fieldunique(int uint8fieldunique);

	// 16λ�޷�������Ψһ
	const TestConfig* FindTestConfigByuint16fieldunique(int uint16fieldunique);

	// 32λ�޷�������Ψһ
	const TestConfig* FindTestConfigByuintfieldunique(int uintfieldunique);

	// 64λ�޷�������Ψһ
	const TestConfig* FindTestConfigByuint64fieldunique(int64_t uint64fieldunique);

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
	std::map<int, TestConfig*> m_mapTestConfigByint16fieldunique;

	// 32λ����Ψһ
	std::map<int, TestConfig*> m_mapTestConfigByintfieldunique;

	// 64λ����Ψһ
	std::map<long, TestConfig*> m_mapTestConfigByint64fieldunique;

	// 8λ�޷�������Ψһ
	std::map<int, TestConfig*> m_mapTestConfigByuint8fieldunique;

	// 16λ�޷�������Ψһ
	std::map<int, TestConfig*> m_mapTestConfigByuint16fieldunique;

	// 32λ�޷�������Ψһ
	std::map<int, TestConfig*> m_mapTestConfigByuintfieldunique;

	// 64λ�޷�������Ψһ
	std::map<int64_t, TestConfig*> m_mapTestConfigByuint64fieldunique;

	// ������Ψһ
	std::map<float, TestConfig*> m_mapTestConfigByfloatfieldunique;

	// ˫���ȸ�����Ψһ
	std::map<double, TestConfig*> m_mapTestConfigBydoublefieldunique;



};