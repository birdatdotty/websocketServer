#include <iostream>
#include "sqlite.h"



using namespace std;

int main () {
  SQLite* sql = new SQLite("new.db");
  sql->open();
// cout << __LINE__ << endl;
  if (sql->init()) {
    // cout << __LINE__ << endl;
    sql->createTables();
    // cout << __LINE__ << endl;
    sql->insert("FILES","file1");
    sql->insert("FILES","file2");
    sql->insert("PEOPLE","Anatoliy");
    sql->insert("PEOPLE","Vasya");
    sql->insert("PEOPLE","Petya");
    sql->setDriver("file1","Anatoliy");
    sql->setDriver("file1","Vasya");
    sql->setDriver("file1","Petya");
    sql->setDriver("file2","Petya");
    sql->clearDrivers("file2");

    cout << "----------------" << endl;
    vector<string> aaa = sql->getDrivers("file1");

    for (auto i: aaa) {
      cout << "\t" << i << endl;
    }


  }
  delete sql;


  return 0;
}
