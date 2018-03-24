#include "SQLString.h"

#include <iostream>

using std::cout;
using std::endl;
using std::string;

using std::to_string;


SQLString::SQLString (string login, string password)
: string(login)
{
  this->password = password;
}


string SQLString::insert()
{
  string tmpInsert =
  //  _INSERT_AUTH_(+*this+,+password+);
  "INSERT INTO AUTH (login, password) "
   "VALUES ('"+*this+"', '"+password+"'); ";

  // cout << tmpInsert << endl;

  return tmpInsert;
}
