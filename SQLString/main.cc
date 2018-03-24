#include <iostream>

#include "SQLString.h"

using namespace std;

int main()
{
  SQLString test("logOn", "p@ssw0rd");

  cout << test.insert() << endl;
  cout << test << endl;

  return 0;
}
