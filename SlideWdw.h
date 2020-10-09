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
    SlideWdw(); // Создать пустую структуру
    int add(const typename SlideWdw::String& arg); // Добавить строку
    void print(); // Распечатать строки по порядку нахождения в структуре
    int get_first_id(); // Получить порядковый номер первой строки
    int get_max_id(); // Получить максимальный порядковый номер строки из структуры
    typename SlideWdw::String* pop_first(); // Получить и удалить первую строку в структуре
    int conn_fragm_size(); // Получить количество строк в первом связном фрагменте
    int conn_fragm_length(); // Получить суммарную длину строк в первом связном фрагменте
    size_t size() const; // Получить количество строк в структуре
};


