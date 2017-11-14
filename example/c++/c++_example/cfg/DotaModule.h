//------------------------------------------------------------------------------
// ��ͷ�ļ��ɹ����Զ����ɣ������ڱ��ļ������Ķ�
// ���ڣ�
//------------------------------------------------------------------------------

#pragma once

#include <string>
#include <map>
#include <vector>
#include <set>






// dotaװ����
struct DotaEquipConfig
{
	DotaEquipConfig()
	{
		Clear();
	}
	
	inline void Clear()
	{
	
		id = 0;
		
	
		name = "";
		
	
		desc = "";
		
	
		price = 0;
		
	
		isdrop = false;
		
	
		attack = 0;
		
	
		vecbornlist.clear();
		
	
		vecbornnum.clear();
		
	
	}
	
	int id; // ��ƷID<Ψһ>
	std::string name; // ��Ʒ����<Ψһ>
	std::string desc; // ����
	int price; // �۳��۸�
	bool isdrop; // �Ƿ���������
	int attack; // ������
	std::vector<int> vecbornlist; // �ϳ��б�<����>
	std::vector<int> vecbornnum; // �ϳ�����<����>
	
};



// dotaӢ�۱�
struct DotaHeroConfig
{
	DotaHeroConfig()
	{
		Clear();
	}
	
	inline void Clear()
	{
	
		id = 0;
		
	
		name = "";
		
	
		strength = 0.0f;
		
	
		agile = 0.0f;
		
	
		intelligense = 0.0f;
		
	
	}
	
	int id; // Ӣ��ID<Ψһ>
	std::string name; // Ӣ������<Ψһ>
	double strength; // ����
	double agile; // ����
	double intelligense; // ����
	
};



// dota���ܱ�
struct DotaSkillConfig
{
	DotaSkillConfig()
	{
		Clear();
	}
	
	inline void Clear()
	{
	
		id = 0;
		
	
		name = "";
		
	
		strength = 0.0f;
		
	
		agile = 0.0f;
		
	
		intelligense = 0.0f;
		
	
	}
	
	int id; // Ӣ��ID<Ψһ>
	std::string name; // Ӣ������<Ψһ>
	double strength; // ����
	double agile; // ����
	double intelligense; // ����
	
};



// dota�����
struct DotaNpcConfig
{
	DotaNpcConfig()
	{
		Clear();
	}
	
	inline void Clear()
	{
	
		id = 0;
		
	
		name = "";
		
	
		strength = 0.0f;
		
	
		agile = 0.0f;
		
	
		intelligense = 0.0f;
		
	
	}
	
	int id; // Ӣ��ID<Ψһ>
	std::string name; // Ӣ������<Ψһ>
	double strength; // ����
	double agile; // ����
	double intelligense; // ����
	
};















class DotaModule
{
public:
	static DotaModule instance;

public:
	// ��ȡ������������
	const char* Name(){ return "DotaModule"; }

public:
	
	// ��������
	bool Load(std::string basePath);


	bool LoadDotaEquipConfig(std::string basePath);


	bool LoadDotaHeroConfig(std::string basePath);


	bool LoadDotaSkillConfig(std::string basePath);


	bool LoadDotaNpcConfig(std::string basePath);



    // �������
    void Clear();
	
public:
	



	// ��ƷID
	const DotaEquipConfig* FindDotaEquipConfigByid(int id);

	// ��Ʒ����
	const DotaEquipConfig* FindDotaEquipConfigByname(std::string name);




	// Ӣ��ID
	const DotaHeroConfig* FindDotaHeroConfigByid(int id);

	// Ӣ������
	const DotaHeroConfig* FindDotaHeroConfigByname(std::string name);




	// Ӣ��ID
	const DotaSkillConfig* FindDotaSkillConfigByid(int id);

	// Ӣ������
	const DotaSkillConfig* FindDotaSkillConfigByname(std::string name);




	// Ӣ��ID
	const DotaNpcConfig* FindDotaNpcConfigByid(int id);

	// Ӣ������
	const DotaNpcConfig* FindDotaNpcConfigByname(std::string name);



	
public:
	

	// dotaװ����
	std::vector<DotaEquipConfig> m_vecDotaEquipConfig;

	// dotaӢ�۱�
	std::vector<DotaHeroConfig> m_vecDotaHeroConfig;

	// dota���ܱ�
	std::vector<DotaSkillConfig> m_vecDotaSkillConfig;

	// dota�����
	std::vector<DotaNpcConfig> m_vecDotaNpcConfig;




	// ��ƷID
	std::map<int, DotaEquipConfig*> m_mapDotaEquipConfigByid;

	// ��Ʒ����
	std::map<std::string, DotaEquipConfig*> m_mapDotaEquipConfigByname;




	// Ӣ��ID
	std::map<int, DotaHeroConfig*> m_mapDotaHeroConfigByid;

	// Ӣ������
	std::map<std::string, DotaHeroConfig*> m_mapDotaHeroConfigByname;




	// Ӣ��ID
	std::map<int, DotaSkillConfig*> m_mapDotaSkillConfigByid;

	// Ӣ������
	std::map<std::string, DotaSkillConfig*> m_mapDotaSkillConfigByname;




	// Ӣ��ID
	std::map<int, DotaNpcConfig*> m_mapDotaNpcConfigByid;

	// Ӣ������
	std::map<std::string, DotaNpcConfig*> m_mapDotaNpcConfigByname;



};