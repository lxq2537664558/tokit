using System.Collections.Generic;
using Newtonsoft.Json;
using System.IO;
using UnityEngine;
using System;



// dotaװ����
public partial class DotaEquipConfig
{

	// ��ƷID
	public int id;

	// ��Ʒ����
	public string name;

	// ����
	public string desc;

	// �۳��۸�
	public int price;

	// �Ƿ���������
	public bool isdrop;

	// ������
	public int attack;

	// �ϳ��б�
	public int m_listbornlist;

	// �ϳ�����
	public int m_listbornnum;
 }

// dotaӢ�۱�
public partial class DotaHeroConfig
{

	// Ӣ��ID
	public int id;

	// Ӣ������
	public string name;

	// ����
	public double strength;

	// ����
	public double agile;

	// ����
	public double intelligense;
 }

// dota���ܱ�
public partial class DotaSkillConfig
{

	// Ӣ��ID
	public int id;

	// Ӣ������
	public string name;

	// ����
	public double strength;

	// ����
	public double agile;

	// ����
	public double intelligense;
 }

// dota�����
public partial class DotaNpcConfig
{

	// Ӣ��ID
	public int id;

	// Ӣ������
	public string name;

	// ����
	public double strength;

	// ����
	public double agile;

	// ����
	public double intelligense;
 }


public partial class DotaModule
{		
	public static DotaModule instance = new DotaModule();
	
	
	// dotaװ����
	public List<DotaEquipConfig> m_listDotaEquipConfig = new List<DotaEquipConfig>();

	// dotaӢ�۱�
	public List<DotaHeroConfig> m_listDotaHeroConfig = new List<DotaHeroConfig>();

	// dota���ܱ�
	public List<DotaSkillConfig> m_listDotaSkillConfig = new List<DotaSkillConfig>();

	// dota�����
	public List<DotaNpcConfig> m_listDotaNpcConfig = new List<DotaNpcConfig>();

	

	// ��ƷID
	public Dictionary<int, DotaEquipConfig> m_mapDotaEquipConfigByid = new Dictionary<int, DotaEquipConfig>();
	
	// ��Ʒ����
	public Dictionary<string, DotaEquipConfig> m_mapDotaEquipConfigByname = new Dictionary<string, DotaEquipConfig>();
	


	// Ӣ��ID
	public Dictionary<int, DotaHeroConfig> m_mapDotaHeroConfigByid = new Dictionary<int, DotaHeroConfig>();
	
	// Ӣ������
	public Dictionary<string, DotaHeroConfig> m_mapDotaHeroConfigByname = new Dictionary<string, DotaHeroConfig>();
	


	// Ӣ��ID
	public Dictionary<int, DotaSkillConfig> m_mapDotaSkillConfigByid = new Dictionary<int, DotaSkillConfig>();
	
	// Ӣ������
	public Dictionary<string, DotaSkillConfig> m_mapDotaSkillConfigByname = new Dictionary<string, DotaSkillConfig>();
	


	// Ӣ��ID
	public Dictionary<int, DotaNpcConfig> m_mapDotaNpcConfigByid = new Dictionary<int, DotaNpcConfig>();
	
	// Ӣ������
	public Dictionary<string, DotaNpcConfig> m_mapDotaNpcConfigByname = new Dictionary<string, DotaNpcConfig>();
	

	
	
	// ��ƷID
	public DotaEquipConfig GetDotaEquipConfigByid(int id)
	{
		DotaEquipConfig ret;
		m_mapDotaEquipConfigByid.TryGetValue(id, out ret);
		return ret;
	}
	
	// ��Ʒ����
	public DotaEquipConfig GetDotaEquipConfigByname(string name)
	{
		DotaEquipConfig ret;
		m_mapDotaEquipConfigByname.TryGetValue(name, out ret);
		return ret;
	}
	

	
	// Ӣ��ID
	public DotaHeroConfig GetDotaHeroConfigByid(int id)
	{
		DotaHeroConfig ret;
		m_mapDotaHeroConfigByid.TryGetValue(id, out ret);
		return ret;
	}
	
	// Ӣ������
	public DotaHeroConfig GetDotaHeroConfigByname(string name)
	{
		DotaHeroConfig ret;
		m_mapDotaHeroConfigByname.TryGetValue(name, out ret);
		return ret;
	}
	

	
	// Ӣ��ID
	public DotaSkillConfig GetDotaSkillConfigByid(int id)
	{
		DotaSkillConfig ret;
		m_mapDotaSkillConfigByid.TryGetValue(id, out ret);
		return ret;
	}
	
	// Ӣ������
	public DotaSkillConfig GetDotaSkillConfigByname(string name)
	{
		DotaSkillConfig ret;
		m_mapDotaSkillConfigByname.TryGetValue(name, out ret);
		return ret;
	}
	

	
	// Ӣ��ID
	public DotaNpcConfig GetDotaNpcConfigByid(int id)
	{
		DotaNpcConfig ret;
		m_mapDotaNpcConfigByid.TryGetValue(id, out ret);
		return ret;
	}
	
	// Ӣ������
	public DotaNpcConfig GetDotaNpcConfigByname(string name)
	{
		DotaNpcConfig ret;
		m_mapDotaNpcConfigByname.TryGetValue(name, out ret);
		return ret;
	}
	

	
	// ���ص����ļ�
	public bool LoadDotaEquipConfig(string basePath)
	{
		string jsonPath = basePath + @"DotaEquipConfig.json";
		string jsonText = File.ReadAllText(jsonPath, System.Text.Encoding.Default);
		
		try
		{
			m_listDotaEquipConfig = (List<DotaEquipConfig>)Newtonsoft.Json.JsonConvert.DeserializeObject(jsonText, typeof(List<DotaEquipConfig>));
		}
		catch (Exception e)
		{
			Debug.Log("����" + jsonPath + "����ʧ�ܣ�ԭ�� = " + e.Message);
		}			

		for (int i = 0; i < m_listDotaEquipConfig.Count; ++i)
		{
			DotaEquipConfig row = m_listDotaEquipConfig[i];
				m_mapDotaEquipConfigByid[row.id] = row;
				m_mapDotaEquipConfigByname[row.name] = row;
		}
		
		return true;
	}

	// ���ص����ļ�
	public bool LoadDotaHeroConfig(string basePath)
	{
		string jsonPath = basePath + @"DotaHeroConfig.json";
		string jsonText = File.ReadAllText(jsonPath, System.Text.Encoding.Default);
		
		try
		{
			m_listDotaHeroConfig = (List<DotaHeroConfig>)Newtonsoft.Json.JsonConvert.DeserializeObject(jsonText, typeof(List<DotaHeroConfig>));
		}
		catch (Exception e)
		{
			Debug.Log("����" + jsonPath + "����ʧ�ܣ�ԭ�� = " + e.Message);
		}			

		for (int i = 0; i < m_listDotaHeroConfig.Count; ++i)
		{
			DotaHeroConfig row = m_listDotaHeroConfig[i];
				m_mapDotaHeroConfigByid[row.id] = row;
				m_mapDotaHeroConfigByname[row.name] = row;
		}
		
		return true;
	}

	// ���ص����ļ�
	public bool LoadDotaSkillConfig(string basePath)
	{
		string jsonPath = basePath + @"DotaSkillConfig.json";
		string jsonText = File.ReadAllText(jsonPath, System.Text.Encoding.Default);
		
		try
		{
			m_listDotaSkillConfig = (List<DotaSkillConfig>)Newtonsoft.Json.JsonConvert.DeserializeObject(jsonText, typeof(List<DotaSkillConfig>));
		}
		catch (Exception e)
		{
			Debug.Log("����" + jsonPath + "����ʧ�ܣ�ԭ�� = " + e.Message);
		}			

		for (int i = 0; i < m_listDotaSkillConfig.Count; ++i)
		{
			DotaSkillConfig row = m_listDotaSkillConfig[i];
				m_mapDotaSkillConfigByid[row.id] = row;
				m_mapDotaSkillConfigByname[row.name] = row;
		}
		
		return true;
	}

	// ���ص����ļ�
	public bool LoadDotaNpcConfig(string basePath)
	{
		string jsonPath = basePath + @"DotaNpcConfig.json";
		string jsonText = File.ReadAllText(jsonPath, System.Text.Encoding.Default);
		
		try
		{
			m_listDotaNpcConfig = (List<DotaNpcConfig>)Newtonsoft.Json.JsonConvert.DeserializeObject(jsonText, typeof(List<DotaNpcConfig>));
		}
		catch (Exception e)
		{
			Debug.Log("����" + jsonPath + "����ʧ�ܣ�ԭ�� = " + e.Message);
		}			

		for (int i = 0; i < m_listDotaNpcConfig.Count; ++i)
		{
			DotaNpcConfig row = m_listDotaNpcConfig[i];
				m_mapDotaNpcConfigByid[row.id] = row;
				m_mapDotaNpcConfigByname[row.name] = row;
		}
		
		return true;
	}

	
	// ��������
	public bool Load(string basePath)
	{
		if (!LoadDotaEquipConfig(basePath))
		{
			return false;
		}
		
		if (!LoadDotaHeroConfig(basePath))
		{
			return false;
		}
		
		if (!LoadDotaSkillConfig(basePath))
		{
			return false;
		}
		
		if (!LoadDotaNpcConfig(basePath))
		{
			return false;
		}
		
		return true;
	}

}






	












