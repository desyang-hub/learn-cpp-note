/**
 * @FilePath     : /cpp/string/string.h
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2025-12-27 13:37:16
 * @LastEditors  : desyang
 * @LastEditTime : 2025-12-27 13:49:16
**/
#ifndef __MYSTRING__
#define __MYSTRING__

#include <cstring>
#include <iostream>

class String {
public:
    String(const char* str=0) {
        if (str) {
            int len = strlen(str);
            m_data = new char[len + 1];
            strcpy(m_data, str);
        } else {
            m_data = new char[1];
            *m_data = '\0';
        }
    }

    String(const String& str);

    String& operator=(const String& str);


    ~String() {
        delete[] m_data;
    }

    int Size() const {
        return strlen(m_data);
    }

    friend std::ostream& operator<<(std::ostream&, const String& str);
private:
    char* m_data;
};

inline String::String(const String& str) {
    int len = strlen(str.m_data);
    m_data = new char[len + 1];
    strcpy(m_data, str.m_data);
}

inline String& String::operator=(const String& str) {
    // 判断自己给自己赋值
    if (this == &str) {
        return *this;
    }

    // 释放，申请，拷贝
    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}


inline std::ostream& operator<<(std::ostream& os, const String& str) {
    return os << str.m_data;
}


#endif