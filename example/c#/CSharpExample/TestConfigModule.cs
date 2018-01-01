//------------------------------------------------------------
// ���ļ��ɹ����Զ����ɣ�����Ķ�
//------------------------------------------------------------

using System.Collections.Generic;
using System.IO;
using System;

// ����������
public partial class TestConfig
{

	// �ַ���
	public string stringfield;
	
	// bool��
	public bool boolfield;
	
	// �ַ�
	public byte charfield;
	
	// 16λ����
	public int int16field;
	
	// 32λ����
	public int intfield;
	
	// 64λ����
	public long int64field;
	
	// ������
	public float floatfield;
	
	// ˫���ȸ�����
	public double doublefield;
	
	// �ַ���Ψһ
	public string stringfieldunique;
	
	// bool��Ψһ
	public bool boolfieldunique;
	
	// �ַ�Ψһ
	public byte charfieldunique;
	
	// 16λ����Ψһ
	public int int16fieldunique;
	
	// 32λ����Ψһ
	public int intfieldunique;
	
	// 64λ����Ψһ
	public long int64fieldunique;
	
	// ������Ψһ
	public float floatfieldunique;
	
	// ˫���ȸ�����Ψһ
	public double doublefieldunique;
	
	// �ַ�������
	public List<string> stringfieldarray;
	
	// bool������
	public List<bool> boolfieldarray;
	
	// �ַ�����
	public List<byte> charfieldarray;
	
	// 16λ��������
	public List<int> int16fieldarray;
	
	// 32λ��������
	public List<int> intfieldarray;
	
	// 64λ��������
	public List<long> int64fieldarray;
	
	// ����������
	public List<float> floatfieldarray;
	
	// ˫���ȸ���������
	public List<double> doublefieldarray;
	
}

public partial class TestConfigModule : IConfigModule
{		
	public static TestConfigModule instance;
	
	// ��ʼ��
	public override bool Init()
	{
		instance = this;
		return true;
	}
	
	// ����������
	public List<TestConfig> m_listTestConfig = new List<TestConfig>();

	// �ַ���Ψһ
	public Dictionary<string, TestConfig> m_mapTestConfigBystringfieldunique = new Dictionary<string, TestConfig>();
	
	// bool��Ψһ
	public Dictionary<bool, TestConfig> m_mapTestConfigByboolfieldunique = new Dictionary<bool, TestConfig>();
	
	// �ַ�Ψһ
	public Dictionary<byte, TestConfig> m_mapTestConfigBycharfieldunique = new Dictionary<byte, TestConfig>();
	
	// 16λ����Ψһ
	public Dictionary<int, TestConfig> m_mapTestConfigByint16fieldunique = new Dictionary<int, TestConfig>();
	
	// 32λ����Ψһ
	public Dictionary<int, TestConfig> m_mapTestConfigByintfieldunique = new Dictionary<int, TestConfig>();
	
	// 64λ����Ψһ
	public Dictionary<long, TestConfig> m_mapTestConfigByint64fieldunique = new Dictionary<long, TestConfig>();
	
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
	public TestConfig GetTestConfigBycharfieldunique(byte charfieldunique)
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
	
	// ��ȡ�ļ����ݣ�������unsafe���η���
	public unsafe bool UnsafeLoadTestConfigBinary(string binaryPath, Byte[] bytes)
	{
		fixed (byte* p = bytes)
		{
			if (bytes.Length < sizeof(int))
			{
				Console.WriteLine("����" + binaryPath + "����������ʧ�ܣ�ԭ�����ļ��Ĵ�С" + bytes.Length + "���Ϸ������� >= " + sizeof(int));
				return false;
			}
			
			// ȡ������
			int rowCount = *((int*)p);
			if (rowCount < 0 || rowCount >= 1000000)
			{
				Console.WriteLine("����" + binaryPath + "����������ʧ�ܣ�ԭ���Ƕ�ȡ���ļ���ͷ������" + rowCount + "���Ϸ�");
				return false;
			}			
			
			m_listTestConfig.Capacity = rowCount;
						
			for (int peek = sizeof(int); peek < bytes.Length;)
			{
				TestConfig row = new TestConfig();
				
				// ������������
			
				row.stringfield = ConfigModule.ReadByteString(p, ref peek);
				
				row.boolfield = (p[peek] != '\0');peek += sizeof(bool);
				
				row.charfield = (byte)p[peek];peek += sizeof(byte);
				
				row.int16field = *((short*)(p + peek));peek += sizeof(short);
				
				row.intfield = *((int*)(p + peek));peek += sizeof(int);
				
				row.int64field = *((long*)(p + peek));peek += sizeof(long);
				
				row.floatfield = *((float*)(p + peek));peek += sizeof(float);
				
				row.doublefield = *((double*)(p + peek));peek += sizeof(double);
				
				row.stringfieldunique = ConfigModule.ReadByteString(p, ref peek);
				
				row.boolfieldunique = (p[peek] != '\0');peek += sizeof(bool);
				
				row.charfieldunique = (byte)p[peek];peek += sizeof(byte);
				
				row.int16fieldunique = *((short*)(p + peek));peek += sizeof(short);
				
				row.intfieldunique = *((int*)(p + peek));peek += sizeof(int);
				
				row.int64fieldunique = *((long*)(p + peek));peek += sizeof(long);
				
				row.floatfieldunique = *((float*)(p + peek));peek += sizeof(float);
				
				row.doublefieldunique = *((double*)(p + peek));peek += sizeof(double);
				
				row.stringfieldarray = new List<string>();
				
				int stringfieldarrayArraySize = *((int*)(p + peek));peek += sizeof(int);
				if (!ConfigModule.IsArraySizeValid(stringfieldarrayArraySize))
				{
					Console.WriteLine("����" + binaryPath + "����������ʧ�ܣ�ԭ���Ƕ�ȡ��stringfieldarray���鳤�Ȳ��Ϸ� = " + stringfieldarrayArraySize);
					return false;
				}
				
				row.stringfieldarray.Capacity = stringfieldarrayArraySize;
				
				for (int i = 0; i < stringfieldarrayArraySize; ++i)
				{
					row.stringfieldarray.Add(ConfigModule.ReadByteString(p, ref peek));
					
				}
				
				row.boolfieldarray = new List<bool>();
				
				int boolfieldarrayArraySize = *((int*)(p + peek));peek += sizeof(int);
				if (!ConfigModule.IsArraySizeValid(boolfieldarrayArraySize))
				{
					Console.WriteLine("����" + binaryPath + "����������ʧ�ܣ�ԭ���Ƕ�ȡ��boolfieldarray���鳤�Ȳ��Ϸ� = " + boolfieldarrayArraySize);
					return false;
				}
				
				row.boolfieldarray.Capacity = boolfieldarrayArraySize;
				
				for (int i = 0; i < boolfieldarrayArraySize; ++i)
				{
					row.boolfieldarray.Add(p[peek] != '\0');peek += sizeof(bool);
					
				}
				
				row.charfieldarray = new List<byte>();
				
				int charfieldarrayArraySize = *((int*)(p + peek));peek += sizeof(int);
				if (!ConfigModule.IsArraySizeValid(charfieldarrayArraySize))
				{
					Console.WriteLine("����" + binaryPath + "����������ʧ�ܣ�ԭ���Ƕ�ȡ��charfieldarray���鳤�Ȳ��Ϸ� = " + charfieldarrayArraySize);
					return false;
				}
				
				row.charfieldarray.Capacity = charfieldarrayArraySize;
				
				for (int i = 0; i < charfieldarrayArraySize; ++i)
				{
					row.charfieldarray.Add((byte)p[peek]);peek += sizeof(byte);
					
				}
				
				row.int16fieldarray = new List<int>();
				
				int int16fieldarrayArraySize = *((int*)(p + peek));peek += sizeof(int);
				if (!ConfigModule.IsArraySizeValid(int16fieldarrayArraySize))
				{
					Console.WriteLine("����" + binaryPath + "����������ʧ�ܣ�ԭ���Ƕ�ȡ��int16fieldarray���鳤�Ȳ��Ϸ� = " + int16fieldarrayArraySize);
					return false;
				}
				
				row.int16fieldarray.Capacity = int16fieldarrayArraySize;
				
				for (int i = 0; i < int16fieldarrayArraySize; ++i)
				{
					row.int16fieldarray.Add(*((short*)(p + peek)));peek += sizeof(short);
					
				}
				
				row.intfieldarray = new List<int>();
				
				int intfieldarrayArraySize = *((int*)(p + peek));peek += sizeof(int);
				if (!ConfigModule.IsArraySizeValid(intfieldarrayArraySize))
				{
					Console.WriteLine("����" + binaryPath + "����������ʧ�ܣ�ԭ���Ƕ�ȡ��intfieldarray���鳤�Ȳ��Ϸ� = " + intfieldarrayArraySize);
					return false;
				}
				
				row.intfieldarray.Capacity = intfieldarrayArraySize;
				
				for (int i = 0; i < intfieldarrayArraySize; ++i)
				{
					row.intfieldarray.Add(*((int*)(p + peek)));peek += sizeof(int);
					
				}
				
				row.int64fieldarray = new List<long>();
				
				int int64fieldarrayArraySize = *((int*)(p + peek));peek += sizeof(int);
				if (!ConfigModule.IsArraySizeValid(int64fieldarrayArraySize))
				{
					Console.WriteLine("����" + binaryPath + "����������ʧ�ܣ�ԭ���Ƕ�ȡ��int64fieldarray���鳤�Ȳ��Ϸ� = " + int64fieldarrayArraySize);
					return false;
				}
				
				row.int64fieldarray.Capacity = int64fieldarrayArraySize;
				
				for (int i = 0; i < int64fieldarrayArraySize; ++i)
				{
					row.int64fieldarray.Add(*((long*)(p + peek)));peek += sizeof(long);
					
				}
				
				row.floatfieldarray = new List<float>();
				
				int floatfieldarrayArraySize = *((int*)(p + peek));peek += sizeof(int);
				if (!ConfigModule.IsArraySizeValid(floatfieldarrayArraySize))
				{
					Console.WriteLine("����" + binaryPath + "����������ʧ�ܣ�ԭ���Ƕ�ȡ��floatfieldarray���鳤�Ȳ��Ϸ� = " + floatfieldarrayArraySize);
					return false;
				}
				
				row.floatfieldarray.Capacity = floatfieldarrayArraySize;
				
				for (int i = 0; i < floatfieldarrayArraySize; ++i)
				{
					row.floatfieldarray.Add(*((float*)(p + peek)));peek += sizeof(float);
					
				}
				
				row.doublefieldarray = new List<double>();
				
				int doublefieldarrayArraySize = *((int*)(p + peek));peek += sizeof(int);
				if (!ConfigModule.IsArraySizeValid(doublefieldarrayArraySize))
				{
					Console.WriteLine("����" + binaryPath + "����������ʧ�ܣ�ԭ���Ƕ�ȡ��doublefieldarray���鳤�Ȳ��Ϸ� = " + doublefieldarrayArraySize);
					return false;
				}
				
				row.doublefieldarray.Capacity = doublefieldarrayArraySize;
				
				for (int i = 0; i < doublefieldarrayArraySize; ++i)
				{
					row.doublefieldarray.Add(*((double*)(p + peek)));peek += sizeof(double);
					
				}
				
				m_listTestConfig.Add(row);
			
			}
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
			
			m_mapTestConfigByfloatfieldunique[row.floatfieldunique] = row;
			
			m_mapTestConfigBydoublefieldunique[row.doublefieldunique] = row;
			
		}
		
		return true;
	}

	// ���ص����ļ���ͨ��ԭʼָ�뷽ʽ��
	public bool LoadTestConfigBinaryByPointer(string basePath)
	{
		string binaryPath = basePath + @"Binary/TestConfig.bin";

		try
		{
			FileStream fileStream = new FileStream(binaryPath, FileMode.Open);

			Byte[] bytes = new Byte[fileStream.Length];
			fileStream.Read(bytes, 0, (int)fileStream.Length);
			fileStream.Close();

			if (!UnsafeLoadTestConfigBinary(binaryPath, bytes))
			{
				return false;
			}
		}
		catch (Exception e)
		{
			Console.WriteLine("����" + binaryPath + "����������ʧ�ܣ�ԭ�� = " + e.Message);
			return false;
		}			
		
		return true;
	}

	// ��������
	public override bool Load(string configDirectory)
	{
		
		if (!LoadTestConfigBinaryByPointer(configDirectory))
		{
			return false;
		}
		
		return true;
	}

}