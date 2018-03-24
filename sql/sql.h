#ifndef _SQL_H_
#define _SQL_H_
#include <string>
#include <cstdio>
#include <cstdlib>
#include <sqlite3.h>

#include "../SQLString/SQLString.h"

class TestSQL {
  private:
    std::string fileName;
    bool isOpenned;

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    TestSQL ();
    std::string getPassword (std::string);


  public:
    void open ();
    bool createTable ();
    bool check(std::string,std::string);
    bool insert(SQLString);
    bool rmDriver(std::string);

    TestSQL (std::string);

    ~TestSQL ();
};

#endif
