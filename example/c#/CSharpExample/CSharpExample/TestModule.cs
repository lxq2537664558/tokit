using System.Collections.Generic;
using Newtonsoft.Json;
using System.IO;
using UnityEngine;
using System;



// ����������
public partial class TestConfig
{

	// �ַ���
	public string stringfield;

	// bool��
	public bool boolfield;

	// �ַ�
	public char charfield;

	// 16λ����
	public int int16field;

	// 32λ����
	public int intfield;

	// 64λ����
	public long int64field;

	// 8λ�޷�������
	public int uint8field;

	// 16λ�޷�������
	public int uint16field;

	// 32λ�޷�������
	public int uintfield;

	// 64λ�޷�������
	public long uint64field;

	// ������
	public float floatfield;

	// ˫���ȸ�����
	public double doublefield;

	// �ַ�������
	public string stringfieldprimary;

	// bool������
	public bool boolfieldprimary;

	// �ַ�����
	public char charfieldprimary;

	// 16λ��������
	public int int16fieldprimary;

	// 32λ��������
	public int intfieldprimary;

	// 64λ��������
	public long int64fieldprimary;

	// 8λ�޷�����������
	public int uint8fieldprimary;

	// 16λ�޷�����������
	public int uint16fieldprimary;

	// 32λ�޷�����������
	public int uintfieldprimary;

	// 64λ�޷�����������
	public long uint64fieldprimary;

	// ����������
	public float floatfieldprimary;

	// ˫���ȸ���������
	public double doublefieldprimary;

	// �ַ���Ψһ
	public string stringfieldunique;

	// bool��Ψһ
	public bool boolfieldunique;

	// �ַ�Ψһ
	public char charfieldunique;

	// 16λ����Ψһ
	public int int16fieldunique;

	// 32λ����Ψһ
	public int intfieldunique;

	// 64λ����Ψһ
	public long int64fieldunique;

	// 8λ�޷�������Ψһ
	public int uint8fieldunique;

	// 16λ�޷�������Ψһ
	public int uint16fieldunique;

	// 32λ�޷�������Ψһ
	public int uintfieldunique;

	// 64λ�޷�������Ψһ
	public long uint64fieldunique;

	// ������Ψһ
	public float floatfieldunique;

	// ˫���ȸ�����Ψһ
	public double doublefieldunique;

	// �ַ�������
	public string m_liststringfieldarray;

	// bool������
	public bool m_listboolfieldarray;

	// �ַ�����
	public char m_listcharfieldarray;

	// 16λ��������
	public int m_listint16fieldarray;

	// 32λ��������
	public int m_listintfieldarray;

	// 64λ��������
	public long m_listint64fieldarray;

	// 8λ�޷�����������
	public int m_listuint8fieldarray;

	// 16λ�޷�����������
	public int m_listuint16fieldarray;

	// 32λ�޷�����������
	public int m_listuintfieldarray;

	// 64λ�޷�����������
	public long m_listuint64fieldarray;

	// ����������
	public float m_listfloatfieldarray;

	// ˫���ȸ���������
	public double m_listdoublefieldarray;

	// �ַ�������
	public string m_setstringfieldset;

	// bool�ͼ���
	public bool m_setboolfieldset;

	// �ַ�����
	public char m_setcharfieldset;

	// 16λ��������
	public int m_setint16fieldset;

	// 32λ��������
	public int m_setintfieldset;

	// 64λ��������
	public long m_setint64fieldset;

	// 8λ�޷�����������
	public int m_setuint8fieldset;

	// 16λ�޷�����������
	public int m_setuint16fieldset;

	// 32λ�޷�����������
	public int m_setuintfieldset;

	// 64λ�޷�����������
	public long m_setuint64fieldset;

	// ����������
	public float m_setfloatfieldset;

	// ˫���ȸ���������
	public double m_setdoublefieldset;
 }


public partial class TestModule
{		
	public static TestModule instance = new TestModule();
	
	
	// ����������
	public List<TestConfig> m_listTestConfig = new List<TestConfig>();

	

	// �ַ���Ψһ
	public Dictionary<string, TestConfig> m_mapTestConfigBystringfieldunique = new Dictionary<string, TestConfig>();
	
	// bool��Ψһ
	public Dictionary<bool, TestConfig> m_mapTestConfigByboolfieldunique = new Dictionary<bool, TestConfig>();
	
	// �ַ�Ψһ
	public Dictionary<char, TestConfig> m_mapTestConfigBycharfieldunique = new Dictionary<char, TestConfig>();
	
	// 16λ����Ψһ
	public Dictionary<int, TestConfig> m_mapTestConfigByint16fieldunique = new Dictionary<int, TestConfig>();
	
	// 32λ����Ψһ
	public Dictionary<int, TestConfig> m_mapTestConfigByintfieldunique = new Dictionary<int, TestConfig>();
	
	// 64λ����Ψһ
	public Dictionary<long, TestConfig> m_mapTestConfigByint64fieldunique = new Dictionary<long, TestConfig>();
	
	// 8λ�޷�������Ψһ
	public Dictionary<int, TestConfig> m_mapTestConfigByuint8fieldunique = new Dictionary<int, TestConfig>();
	
	// 16λ�޷�������Ψһ
	public Dictionary<int, TestConfig> m_mapTestConfigByuint16fieldunique = new Dictionary<int, TestConfig>();
	
	// 32λ�޷�������Ψһ
	public Dictionary<int, TestConfig> m_mapTestConfigByuintfieldunique = new Dictionary<int, TestConfig>();
	
	// 64λ�޷�������Ψһ
	public Dictionary<long, TestConfig> m_mapTestConfigByuint64fieldunique = new Dictionary<long, TestConfig>();
	
	// ������Ψһ
	public Dictionary<float, TestConfig> m_mapTestConfigByfloatfieldunique = new Dictionary<float, TestConfig>();
	
	// ˫���ȸ�����Ψһ
	public Dictionary<double, TestConfig> m_mapTestConfigBydoublefieldunique = new Dictionary<double, TestConfig>();
	

	
	
	// �ַ���Ψһ
	public TestConfig GetTestConfigBystringfieldunique(string stringfieldunique)
	{
		TestConfig ret;
		m_mapTestConfigBystringfieldunique.TryGetValue(stringfieldunique, out ret);
		return ret;
	}
	
	// bool��Ψһ
	public TestConfig GetTestConfigByboolfieldunique(bool boolfieldunique)
	{
		TestConfig ret;
		m_mapTestConfigByboolfieldunique.TryGetValue(boolfieldunique, out ret);
		return ret;
	}
	
	// �ַ�Ψһ
	public TestConfig GetTestConfigBycharfieldunique(char charfieldunique)
	{
		TestConfig ret;
		m_mapTestConfigBycharfieldunique.TryGetValue(charfieldunique, out ret);
		return ret;
	}
	
	// 16λ����Ψһ
	public TestConfig GetTestConfigByint16fieldunique(int int16fieldunique)
	{
		TestConfig ret;
		m_mapTestConfigByint16fieldunique.TryGetValue(int16fieldunique, out ret);
		return ret;
	}
	
	// 32λ����Ψһ
	public TestConfig GetTestConfigByintfieldunique(int intfieldunique)
	{
		TestConfig ret;
		m_mapTestConfigByintfieldunique.TryGetValue(intfieldunique, out ret);
		return ret;
	}
	
	// 64λ����Ψһ
	public TestConfig GetTestConfigByint64fieldunique(long int64fieldunique)
	{
		TestConfig ret;
		m_mapTestConfigByint64fieldunique.TryGetValue(int64fieldunique, out ret);
		return ret;
	}
	
	// 8λ�޷�������Ψһ
	public TestConfig GetTestConfigByuint8fieldunique(int uint8fieldunique)
	{
		TestConfig ret;
		m_mapTestConfigByuint8fieldunique.TryGetValue(uint8fieldunique, out ret);
		return ret;
	}
	
	// 16λ�޷�������Ψһ
	public TestConfig GetTestConfigByuint16fieldunique(int uint16fieldunique)
	{
		TestConfig ret;
		m_mapTestConfigByuint16fieldunique.TryGetValue(uint16fieldunique, out ret);
		return ret;
	}
	
	// 32λ�޷�������Ψһ
	public TestConfig GetTestConfigByuintfieldunique(int uintfieldunique)
	{
		TestConfig ret;
		m_mapTestConfigByuintfieldunique.TryGetValue(uintfieldunique, out ret);
		return ret;
	}
	
	// 64λ�޷�������Ψһ
	public TestConfig GetTestConfigByuint64fieldunique(long uint64fieldunique)
	{
		TestConfig ret;
		m_mapTestConfigByuint64fieldunique.TryGetValue(uint64fieldunique, out ret);
		return ret;
	}
	
	// ������Ψһ
	public TestConfig GetTestConfigByfloatfieldunique(float floatfieldunique)
	{
		TestConfig ret;
		m_mapTestConfigByfloatfieldunique.TryGetValue(floatfieldunique, out ret);
		return ret;
	}
	
	// ˫���ȸ�����Ψһ
	public TestConfig GetTestConfigBydoublefieldunique(double doublefieldunique)
	{
		TestConfig ret;
		m_mapTestConfigBydoublefieldunique.TryGetValue(doublefieldunique, out ret);
		return ret;
	}
	

	
	// ���ص����ļ�
	public bool LoadTestConfig(string basePath)
	{
		string jsonPath = basePath + @"TestConfig.json";
		string jsonText = File.ReadAllText(jsonPath, System.Text.Encoding.Default);
		
		try
		{
			m_listTestConfig = (List<TestConfig>)Newtonsoft.Json.JsonConvert.DeserializeObject(jsonText, typeof(List<TestConfig>));
		}
		catch (Exception e)
		{
			Debug.Log("����" + jsonPath + "����ʧ�ܣ�ԭ�� = " + e.Message);
		}			

		for (int i = 0; i < m_listTestConfig.Count; ++i)
		{
			TestConfig row = m_listTestConfig[i];
				m_mapTestConfigBystringfieldunique[row.stringfieldunique] = row;
				m_mapTestConfigByboolfieldunique[row.boolfieldunique] = row;
				m_mapTestConfigBycharfieldunique[row.charfieldunique] = row;
				m_mapTestConfigByint16fieldunique[row.int16fieldunique] = row;
				m_mapTestConfigByintfieldunique[row.intfieldunique] = row;
				m_mapTestConfigByint64fieldunique[row.int64fieldunique] = row;
				m_mapTestConfigByuint8fieldunique[row.uint8fieldunique] = row;
				m_mapTestConfigByuint16fieldunique[row.uint16fieldunique] = row;
				m_mapTestConfigByuintfieldunique[row.uintfieldunique] = row;
				m_mapTestConfigByuint64fieldunique[row.uint64fieldunique] = row;
				m_mapTestConfigByfloatfieldunique[row.floatfieldunique] = row;
				m_mapTestConfigBydoublefieldunique[row.doublefieldunique] = row;
		}
		
		return true;
	}

	
	// ��������
	public bool Load(string basePath)
	{
		if (!LoadTestConfig(basePath))
		{
			return false;
		}
		
		return true;
	}

}






	












