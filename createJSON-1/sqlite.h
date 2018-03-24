#ifndef _SQL3_H_
#define _SQL3_H_
#include <string>
#include <cstdio>
#include <cstdlib>
#include <sqlite3.h>
#include <string>
#include <vector>

#include "SQLString.h"

class SQLite {
  private:
    std::string fileName;
    bool isOpenned;

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    void execCreateTable(std::string);
    SQLite ();


  public:
    void open ();
    bool init();
    bool createTable ();
    bool insert(std::string,
                std::string,
                std::string itm2="NULL");
    std::vector<std::string> getDriversList ();
    std::vector<std::string> getDrivers (std::string);
    std::vector<std::string> getFileByName (std::string);
    bool setDriver (std::string file, std::string people);
    bool clearDrivers (std::string file);
    bool createTables ();
    bool delDrivers (std::string file);

    SQLite (std::string);

    ~SQLite ();
};

#endif
