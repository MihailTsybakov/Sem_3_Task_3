#include "SlideWdw.h"
#include "Test.h"
/*
Задача № 27
*/
int main(void)
{
    if (Autotest() != 1)
    {
        exit(-1);
    }
    else
    {
        cout << "Autotest passed successfully" << endl << endl;
    }
    SlideWdw Window;

    string str_1 = "String_1", str_2 = "sTRING - II", str_3 = "sTrInGg__3", str_4 = "strinG_IV";
    string str_5 = "Attempt to add me should be failed!";
    SlideWdw::String STR_1(1, str_1), STR_2(4, str_2), STR_3(7, str_3), STR_4(0, str_4), STR_F(7, str_5);
    SlideWdw::String *Str;

    Window.add(STR_1);
    Window.add(STR_2);
    Window.add(STR_3);
    Window.add(STR_4);

    Window.add(STR_F);

    Window.print();
    cout << "--- --- ---" << endl;
    Str = Window.pop_first();
    Window.print();
    cout << "--- --- ---" << endl;
    cout << " <" << Str->get_id() << ">  <" << Str->get_str() << "> " << endl << endl;

    string str_6 = "String Six";
    SlideWdw::String STR_SIX(2, str_6);
    Window.add(STR_SIX);
    cout << "--- --- ---" << endl;
    Window.print();
    cout << "--- --- ---" << endl;
    cout << "Connected fragment size is: " << Window.conn_fragm_size() << endl;
    cout << "Summary string length in connected fragment is: " << Window.conn_fragm_length() << endl;
    cout << "--- --- ---" << endl;
    Window.pop_first();
    Window.print();
    cout << "--- --- ---" << endl;
    Window.pop_first();
    Window.print();
    cout << "--- --- ---" << endl;
    Window.pop_first();
    Window.print();
    cout << "--- --- ---" << endl;
    cout << "Connected fragment size is: " << Window.conn_fragm_size() << endl;
    cout << "Summary string length in connected fragment is: " << Window.conn_fragm_length() << endl;
    cout << "--- --- ---" << endl;
    cout << "Now size is: " << Window.size() << endl;
    return 0;
}
