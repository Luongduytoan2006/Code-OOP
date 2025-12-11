#include <iostream>
using namespace std;

int& Func()
{
    static int var_x = 10;
    return var_x;
}

int main()
{
    cout << Func() = 30;
    return 0;
}
//Kết quả: Compiled error
main.cpp:12:22: error: no match for ‘operator=’ (operand types are ‘std::basic_ostream’ and ‘int’)
   12 |     cout << Func() = 30;
      |                      ^~
In file included from /usr/include/c++/11/iostream:39,
                 from main.cpp:1:
/usr/include/c++/11/ostream:415:7: note: candidate: ‘std::basic_ostream<_CharT, _Traits>& std::basic_ostream<_CharT, _Traits>::operator=(std::basic_ostream<_CharT, _Traits>&&) [with _CharT = char; _Traits = std::char_traits]’
  415 |       operator=(basic_ostream&& __rhs)
      |       ^~~~~~~~
/usr/include/c++/11/ostream:415:33: note:   no known conversion for argument 1 from ‘int’ to ‘std::basic_ostream&&’
  415 |       operator=(basic_ostream&& __rhs)
      |                 ~~~~~~~~~~~~~~~~^~~~~