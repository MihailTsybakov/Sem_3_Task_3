#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class SlideWdw
{
public:
    class String
    {
    private:
        string s;
        int id;
    public:
        String();
        String(int id, string s);
        String& operator=(const String& arg);
        int get_id();
        string get_str();
        friend class SlideWdw;
    };
private:
    int str_num;
    String* strings;
public:
    SlideWdw(); // ������� ������ ���������
    int add(const typename SlideWdw::String& arg); // �������� ������
    void print(); // ����������� ������ �� ������� ���������� � ���������
    int get_first_id(); // �������� ���������� ����� ������ ������
    int get_max_id(); // �������� ������������ ���������� ����� ������ �� ���������
    typename SlideWdw::String* pop_first(); // �������� � ������� ������ ������ � ���������
    int conn_fragm_size(); // �������� ���������� ����� � ������ ������� ���������
    int conn_fragm_length(); // �������� ��������� ����� ����� � ������ ������� ���������
    size_t size() const; // �������� ���������� ����� � ���������
};


