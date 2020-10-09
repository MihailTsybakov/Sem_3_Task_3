#include "SlideWdw.h"

SlideWdw::String::String()
{
    id = -1;
    s = "";
}

SlideWdw::String::String(int id, string s)
{
    this->id = id;
    this->s = s;
}

int SlideWdw::String::get_id()
{
    return id;
}

string SlideWdw::String::get_str()
{
    return s;
}

typename SlideWdw::String& SlideWdw::String::operator =(const typename SlideWdw::String& arg)
{
    id = arg.id;
    s = arg.s;
    return *this;
}

SlideWdw::SlideWdw()
{
    str_num = 0;
    strings = nullptr;
}
int SlideWdw::add(const typename SlideWdw::String& arg)
{
    if (strings != nullptr){
        for (int i = 0; i < str_num; i++)
        {
            if (strings[i].id == arg.id)
            {
                cout << "Warning: cannot add string '" << arg.s[0] << arg.s[1] << arg.s[2] << arg.s[3] << "...', it has not unique ID." << endl;
                return 0;
            }
        }
    }
    else
    {
        strings = new typename SlideWdw::String[1];
        str_num = 1;
        strings[0] = arg;
        return 1;
    }
    str_num ++;
    int str_pos = 0;
    for (int i = 0; i < str_num - 1; i++)
    {
        if (arg.id > strings[i].id)
        {
            str_pos++;
        }
    }
    String* old_strings = new typename SlideWdw::String[str_num - 1];
    for (int i = 0; i < str_num - 1; i++)
    {
        old_strings[i] = strings[i];
    }
    delete[] strings;
    strings = new typename SlideWdw::String[str_num];
    strings[str_pos] = arg;
    int pos = 0;
    for (int i = 0; i < str_num; i++)
    {
        if (i != str_pos)
        {
            strings[i] = old_strings[pos];
            pos++;
        }
    }
    delete[] old_strings;
    return 0;
}
void SlideWdw::print()
{
    if (strings == nullptr)
    {
        cout << "Cannot print anything: structure is empty." << endl;
    }
    else
    {
        for (int i = 0; i < str_num; i++)
        {
            cout << strings[i].id << " " << strings[i].s << endl;
        }
    }
}

int SlideWdw::get_first_id()
{
    if (strings == nullptr)
    {
        cout << "Structure is empty now, cannot return first ID, returning -1." << endl;
        return -1;
    }
    return strings[0].id;
}
int SlideWdw::get_max_id()
{
    if (strings == nullptr)
    {
        cout << "Structure is empty now, cannot return first ID, returning -1." << endl;
        return -1;
    }
    int max_ID = -1;
    for (int i = 0; i < str_num; i++)
    {
        if (max_ID < strings[i].id)
        {
            max_ID = strings[i].id;
        }
    }
    return max_ID;
}

typename SlideWdw::String* SlideWdw::pop_first()
{
    if (strings == nullptr)
    {
        cout << "Cannot pop first string: structure is empty. Returning nullptr." << endl;
        return nullptr;
    }
    typename SlideWdw::String* res = new typename SlideWdw::String;
    res->id = strings[0].id;
    res->s = strings[0].s;
    typename SlideWdw::String* new_strings = new typename SlideWdw::String[str_num - 1];
    for (int i = 1; i < str_num; i++)
    {
        new_strings[i - 1] = strings[i];
    }
    delete[] strings;
    str_num--;
    strings = new typename SlideWdw::String[str_num];
    for (int i = 0; i < str_num; i++)
    {
        strings[i] = new_strings[i];
    }
    delete[] new_strings;
    return res;
}

int SlideWdw::conn_fragm_size()
{
    if (strings == nullptr)
    {
        return 0;
    }
    int conn_fragm_sz = 0;
    for (int i = 0; i < str_num; i++)
    {
        if (i == 0)
        {
            conn_fragm_sz = 1;
        }
        else
        {
            if (strings[i - 1].id + 1 == strings[i].id)
            {
                conn_fragm_sz++;
            }
            else
            {
                return conn_fragm_sz;
            }
        }
    }
    return conn_fragm_sz;
}

int SlideWdw::conn_fragm_length()
{
    if (strings == nullptr)
    {
        return 0;
    }
    int conn_fragm_len = 0;
    for (int i = 0; i < str_num; i++)
    {
        if (i == 0)
        {
            conn_fragm_len = static_cast<int>(strings[0].s.size());
        }
        else
        {
            if (strings[i - 1].id + 1 == strings[i].id)
            {
                conn_fragm_len += static_cast<int>(strings[i].s.size());
            }
            else
            {
                return conn_fragm_len;
            }
        }
    }
    return conn_fragm_len;
}

size_t SlideWdw::size() const
{
    return static_cast<size_t>(str_num);
}
