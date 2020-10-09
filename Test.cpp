#include "Test.h"

int Autotest()
{
    cout << ">---------------- Autotest actions ----------------<" << endl;
    SlideWdw Test_Window;
    // 1.
    if (static_cast<int>(Test_Window.size()) != 0)
    {
        cout << "Autotest failed (size = 0)" << endl;
        return 0;
    }
    cout << "  Tested size of empty: ok" << endl;
    string str_1 = "test_string_1", str_2 = "test_string_2", str_3 = "test_string_3";
    SlideWdw::String STR_1(1, str_1), STR_2(2, str_2), STR_3(4, str_3);
    Test_Window.add(STR_1);
    Test_Window.add(STR_2);
    Test_Window.add(STR_3);
    // 2.
    if (static_cast<int>(Test_Window.size()) != 3)
    {
        cout << "Autotest failed (size = 3)" << endl;
        return 0;
    }
    cout << "  Tested size of not empty: ok" << endl;
    // 3.
    if (Test_Window.conn_fragm_size() != 2)
    {
        cout << "Autotest failed (connected fragment size = 2)" << endl;
        return 0;
    }
    cout << "  Tested size of connected fragment: ok" << endl;
    // 4.
    if (Test_Window.conn_fragm_length() != 26)
    {
        cout << "Autotest failed (connected fragment length = 26)" << endl;
        return 0;
    }
    cout << "  Tested length of connected fragment: ok" << endl;
    // 5.
    if (Test_Window.get_first_id() != 1)
    {
        cout << "Autotest failed (ID of first string)" << endl;
        return 0;
    }
    cout << "  Tested ID of first string: ok" << endl;
    // 6.
    if (Test_Window.get_max_id() != 4)
    {
        cout << "Autotest failed (maximum ID)" << endl;
        return 0;
    }
    cout << "  Tested maximum ID: ok" << endl;
    // 7.
    Test_Window.pop_first();
    if (static_cast<int>(Test_Window.size()) != 2)
    {
        cout << "Autotest failed (deleting first element)" << endl;
        return 0;
    }
    cout << "  Testted 'pop' function: ok" << endl;
    // 8.
    if (Test_Window.conn_fragm_size() != 1)
    {
        cout << "Autotest failed (connected fragment size - 2)" << endl;
        return 0;
    }
    cout << "  Tested conneted fragment size after deleting: ok" << endl;
    // 9.
    string str_f = "string to fail";
    SlideWdw::String STR_F(4, str_f);
    int add_status = Test_Window.add(STR_F);
    if (add_status != 0)
    {
        cout << "Autotest failed (adding not unique element)" << endl;
        return 0;
    }
    cout << "  Tested adding not unique element: ok" << endl;
    // 10.
    Test_Window.pop_first();
    Test_Window.pop_first();
    if (static_cast<int>(Test_Window.size()) != 0)
    {
        cout << "Autotest failed (size # 2)" << endl;
        return 0;
    }
    cout << "  Tested size function after clearing: ok" << endl;
    // 11.
    string str_l = "last_string";
    SlideWdw::String LAST(5, str_l);
    Test_Window.add(LAST);
    if (static_cast<int>(Test_Window.size()) != 1)
    {
        cout << "Autotest failed (adding to empty)" << endl;
        return 0;
    }
    cout << "  Tested adding to empty: ok" << endl;
    cout << ">---------------- Autotest actions ----------------<" << endl << endl << endl;
    return 1;
}
