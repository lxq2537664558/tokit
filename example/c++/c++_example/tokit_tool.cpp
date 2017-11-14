///<------------------------------------------------------------------------------
//< @file:   c++\c++_example\tokit_tool.cpp
//< @author: 
//< @date:   2014��9��27�� 0:3:56
//< @brief:  
//< Copyright (c) 2014 Tokit. All rights reserved.
///<------------------------------------------------------------------------------

#include "tokit_tool.h"
#include <fstream>
#include <sstream>
#include <iostream>

#ifdef WIN32
    #include <windows.h>
	#include <io.h>
#else
    #include <stdio.h>
    #define __STDC_FORMAT_MACROS  
    #include <inttypes.h>
#endif

#include <string.h>
#include <time.h>

namespace tool
{
#ifdef WIN32
    // ��ȡCPUÿ��ĵδ����
	int64_t GetTickFrequency()
    {
        static LARGE_INTEGER static_perfFreq = {0};
        if(0 == static_perfFreq.QuadPart){
            QueryPerformanceFrequency(&static_perfFreq); 
        }

        return static_perfFreq.QuadPart;
    }
#endif

	int64_t get_tick()
    {
#ifdef WIN32
        LARGE_INTEGER tick;

        QueryPerformanceCounter(&tick);
        return tick.QuadPart;
#else
        timespec ts;
        clock_gettime(CLOCK_REALTIME, &ts);

        return ts.tv_sec * 1000000000 + ts.tv_nsec;
#endif
    }

    uint32 tick_diff(int64_t old_tick)
    {
		int64_t tick_now = get_tick();

#ifdef WIN32
        uint32 ms = (uint32)((tick_now - old_tick) * 1000 / GetTickFrequency());
#else
        uint32 ms = (tick_now - old_tick) / 1000000;
#endif

        return ms;
    }

    // �滻�ַ���
    // ���磺replace("this is an expmple", "is", "") = "th  an expmple"
    string& replace(string &str, const char *old, const char* to)
    {
        string::size_type pos = 0;
        int len_old = strlen(old);
        int len_new = strlen(to);

        while((pos = str.find(old, pos)) != string::npos){   
            str.replace(pos, len_old, to);   
            pos += len_new;
        }

        return str;
    }

	void split(const char* src, std::vector<std::string>& out, const char* cut)
    {
        std::string str(src);

		int n = (int)str.size();

		std::string::size_type a = 0, b = 0;
		while (b != std::string::npos) {
			a = str.find_first_not_of(cut, b);
			if (a == std::string::npos) {
				break;
			}

			b = str.find_first_of(cut, a + 1);
			if (b == std::string::npos) {
				if (a != n) {
					out.push_back(str.substr(a));
				}

				break;
			}

			out.push_back(str.substr(a, b - a));
		}
    }

	void split_str_set(const char* src, std::set<std::string>& out, const char* cut)
    {
		std::vector<std::string> vec;
        split(src, vec, cut);

		for (int i = 0, n = (int)vec.size(); i < n; ++i) {
            out.insert(vec[i]);
        }
    }

	void split_int_vec(const char* src, std::vector<int>& out, const char* cut /*= ","*/)
	{
		std::vector<std::string> vec;
		split(src, vec, cut);

		for (int i = 0, n = (int)vec.size(); i < n; ++i) {
			int num = str_to_int(vec[i].c_str());
			out.push_back(num);
		}
	}

	void split_int_set(const char* src, std::set<int>& out, const char* cut /*= ","*/)
	{

	}

}

bool exist(const char* path)
{
	return _access(path, 0) != -1;
}

bool tool::GetFileText(const char* path, std::string &text)
{
	if (false == exist(path)) {
		text = "";
		return false;
	}

	if (false == exist(path)) {
		std::cout << "open <" << path << "> file failed: not found file!";
		text = "";
		return false;
	}

	/* ��Ҫһ��byte��©�ض��������ļ���ֻ�ܲ��ö����Ʒ�ʽ�� */
	FILE *file = NULL;

	int err = fopen_s(&file, path, "rb");
	if (NULL == file || err > 0) {
		std::cout << "[error] open file <" << path << "> failed��error code = " << err << "\n";
		return false;
	}

	/* ��ȡ�ļ���С */
	fseek(file, 0, SEEK_END);
	long size = ftell(file);
	rewind(file);

	/* �����ڴ�洢�����ļ� */
	text.resize(size );
	
	/* ���ļ�������buffer�� */
	size_t n = fread((void*)text.c_str(), 1, size, file);
	if (n != size) {
		std::cout << "����<" << path << ">�ļ�ʧ�ܣ�����ԭ��:�ļ���ȡ��С����" << n << " != " << size;
		return false;
	}

	/* ���������ļ��Ѿ���buffer�� */
	/* �ر��ļ����ͷ��ڴ� */
	fclose(file);
	return true;
}
