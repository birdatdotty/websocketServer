// http://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm

#include <iostream>
#include "../sql/sql.h"
#include "../SQLString/SQLString.h"

using std::cout;
using std::endl;
using std::string;

using std::to_string;

int main ()
{
  // Проверка конструктора по умолчанию
  // TestSQL *qqqq = new TestSQL();

  TestSQL *test = new TestSQL("Test.db");
  test->open();
  test->createTable();
  SQLString tmp(string("login"), string("secret"));
  SQLString tmp2(string("logiasdn"), string("sasdsadecret"));

  test->insert(tmp);
  test->insert(tmp2);
  test->insert(SQLString(string("logi"), string("sasds22ad2e2c2r2e2t")));

  cout << "\tgetPassword: " << test->check("logi","sasds22ad2e2c2r2e2t") << endl;

  return 0;
}
