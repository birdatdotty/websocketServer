// #include "SQLHelper.h"

#include <iostream>

#include "SQLHelper.h"

#define _INSERT_AUTH2_(l,p) \
    "INSERT INTO AUTH (login, password) "\
    "VALUES ('"+l+"', '"+p+"'); "

using namespace std;
inline
string insertAuth (string login, string password);

// inline string insertAuth (string login, string password)
// {
//   string tmp = ("INSERT INTO AUTH (login, password) VALUES ('" +
//     login+"', '"+password+"'); ");
//   return tmp;
// }

// #include "test-inline.cc"

int main ()
{
  string a = "string a";
  int i = 4;
  cout << "Hello, world" << endl;
  cout << insertAuth( "loGin" , "P@sSw0rD" ) << endl;

  return 0;
}
