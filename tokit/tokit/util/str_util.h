#ifndef _str_util_h_
#define _str_util_h_

#include <string>
#include <vector>
#include <set>
#include <wtypes.h>

using std::string;

typedef _ULonglong uint64_t;

namespace strutil
{
    // �Ƴ����ַ�����ͷ��ĩβ���Ŀո��\t����
    // ����: trim("   start xxx end   ") = "start xxx end"
    string trim(char* str);
	string trim(const string& str);

    // �滻�ַ�����������ַ��������޸�
    // ���磺replace("this is an expmple", "is", "") = "th  an expmple"
    // ����: replace("dbdb", "db", "bd") = "bdbd"
    string& replace(string &str, const char *old, const char* to);
    string& replace(string &str, const char *old, const string& to);

    // ѭ���滻����ÿ���ַ������滻�������滻�����ַ����н����滻
    // ����: replace("dbdb", "db", "bd") = "bbbd"
    // ����: replace("good", "o", "oo") = "���ᵼ����ѭ��"
    string& cycle_replace(string &str, const char *old, const char* to);

    // �����ļ���·�������ؽ��ĩβ��/��\
    // ���磺get_dir(../../xxxx.txt) = ../../
    string get_dir(const string &path);

    // �Ƶ�·����ֻ�����ļ�����
    // ���磺strip_dir(../../xxxx.txt) = xxxx.txt
    string strip_dir(const string &path);

    // �Ƶ��ļ�����׺
    // ���磺strip_ext(xxxx.txt) = xxxx
    string strip_ext(const string &filename);

    // ��ȡ��ǰʱ���ַ���
    void time_str();

    // ��������ֱ����һ���ָ����м���ַ���
    // ���磺trip_at("123_456_789", '_') = 123
    string trip_at(const string &str, char delimiter);

    // ��������ֱ�����һ���ָ������ַ���
    // ���磺trip_to("123_456_789", '_') = 123_456
    string trip_to(const string &str, char delimiter);

    // ��������ֱ��ָ���ָ������ַ���
    // ���磺r_trip_at("123_456_789", '_') = 789
    string r_trip_at(const string &str, char delimiter);

    // ���޷���64λ����ת��Ϊ�ַ���
    // ���磺tostr(100123) = "100123"
    string tostr(uint64_t n);

    typedef std::vector<std::string> stringvec_t;

    // ���ַ������ݷָ����ָ�Ϊ�ַ�������
    stringvec_t split(const string &src, char cut = ',');
    
    template <typename T>
    std::vector<T> split_str_to_int_vec(const string &src, char cut = ',')
    {
        typedef std::vector<T> intvec_t;
        intvec_t intvec;

        stringvec_t strvec = split(src, cut);
        for (size_t n = 0; n < strvec.size(); n++){
            std::string str = strvec[n];
            intvec.push_back((T)atoi(str.c_str()));
        }

        return intvec;
    }

    template <typename T>
    std::set<T> split_str_to_int_set(const string &src, char cut = ',')
    {
        typedef std::set<T> intset_t;
        intset_t intset;

        stringvec_t strvec = split(src);
        for (size_t n = 0; n < strvec.size(); n++){
            std::string str = strvec[n];
            intset.insert((T)atoi(str.c_str()));
        }

        return intset;
    }
};

using namespace strutil;

#endif // _str_util_h_