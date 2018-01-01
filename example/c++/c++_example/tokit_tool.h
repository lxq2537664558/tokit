#pragma once

#include <string>
#include <vector>
#include <set>
#include <stdlib.h>

using namespace std;

namespace tool
{
	// ��ȡ�ļ�����
	bool GetFileText(const char* path, std::string &text);

	// �滻�ַ�����������ַ��������޸�
    // ���磺replace("this is an expmple", "is", "") = "th  an expmple"
    // ����: replace("dbdb", "db", "bd") = "bdbd"
    string& replace(string &str, const char *old, const char* to);

	// �ַ���תbool
	inline bool str_to_bool(const char* str)
    {
		char c = str[0];
        return !(c == '0' || c == '\0');
    }

	// �ַ���תint
    inline int32 str_to_int(const char* str)
    {
        return atoi(str);
    }

	// �ַ���תint64
	inline int64 str_to_int64(const char* str)
    {
        double val = 0; 
        val = strtod(str, NULL); 

        return (int64)val;
    }

	// �ַ���תfloat
	inline float str_to_float(const char* str)
	{
		double val = 0;
		val = strtod(str, NULL);

		return (float)val;
	}

	// �ַ���תdouble
	inline double str_to_double(const char* str)
	{
		double val = 0;
		val = strtod(str, NULL);

		return val;
	}

    // ���ַ�����ֳ�����
	void split(const char* src, std::vector<std::string>&, const char* cut = ",");

    template <typename T, typename CastFunction>
    inline void split_str_to_vec(const char* src, std::vector<T>& out, CastFunction (*cast_func)(const char*), const char* cut = ",")
    {
		std::vector<std::string> vec;
        split(src, vec, cut);

		for (int i = 0, n = (int)vec.size(); i < n; ++i) {
			const std::string& elem = vec[i];
			T t = (T)cast_func(elem.c_str());
			out.push_back(t);
		}
    }

    template <typename T, typename CastFunction>
    inline void split_str_to_set(const char* src, std::set<T>& out, CastFunction (*cast_func)(const char*), const char* cut = ",")
    {
		std::vector<std::string> vec;
		split(src, vec, cut);

		for (int i = 0, n = (int)vec.size(); i < n; ++i) {
			const std::string& elem = vec[i];
			T t = (T)cast_func(elem.c_str());
			out.insert(t);
		}
    }
};