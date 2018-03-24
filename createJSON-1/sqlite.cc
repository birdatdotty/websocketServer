#include "sqlite.h"
#include "log.h"
#include "SQLHelper.h"

#include <sstream>
#include <iostream>
#include <cstring>
#include <vector>

using std::string;
using std::cout;
using std::endl;

static int callbackSelect(void *tmp_data, int argc, char **argv, char **azColName){
  int i;

  std::vector<string>* data = (std::vector<string> *) tmp_data;

  for(i = 0; i<argc; i++)
  {
    (*data).push_back(argv[i]);
  }


  return 0;
}

bool SQLite::init() {
  return isOpenned;
}

std::vector<std::string> SQLite::getDriversList () {
  string sql = "select FIO from people;";

  std::vector<string> vec;

  rc = sqlite3_exec(db, sql.c_str(), callbackSelect, (void*)&vec, &zErrMsg);
  if( rc != SQLITE_OK )
  {
     log ("SQL error", zErrMsg);
     sqlite3_free(zErrMsg);
  }

  cout << "AAAAAAAAAAAAAAAAAAAAA" << endl;
  for (auto i: vec)
    cout << i << endl;
  cout << "AAAAAAAAAAAAAAAAAAAAA" << endl;

  return vec;
}

std::vector<string> SQLite::getFileByName (string name) {
  string sql = "select File from FILES where id in (select id_FILE from drivers where id_FIO in (select id from people where FIO='"+name+"'))";

  std::vector<string> vec;

  rc = sqlite3_exec(db, sql.c_str(), callbackSelect, (void*)&vec, &zErrMsg);
  if( rc != SQLITE_OK )
  {
     log ("SQL error", zErrMsg);
     sqlite3_free(zErrMsg);
  }

  return vec;
}

std::vector<string> SQLite::getDrivers (string file) {
  string sql = "select FIO from people where id in (select id_FIO from "
               "drivers where id_FILE=(select id from files where File='" +
               file +"'));";

  std::vector<string> vec;

  rc = sqlite3_exec(db, sql.c_str(), callbackSelect, (void*)&vec, &zErrMsg);
  if( rc != SQLITE_OK )
  {
     log ("SQL error", zErrMsg);
     sqlite3_free(zErrMsg);
  }

  return vec;
}

bool SQLite::delDrivers (string file) {
  string sql = "delete from drivers where id_FILE = (select id from files where file='"+file+"');";

  rc = sqlite3_exec(db, sql.c_str(), NULL /*callback*/, 0, &zErrMsg);
  if( rc != SQLITE_OK )
  {
     log ("SQL error", zErrMsg);
     sqlite3_free(zErrMsg);
     return false;
  }
  else
  {
     return true;
  }

}

bool SQLite::setDriver (string file, string people) {

  string sql = "  INSERT INTO DRIVERS ('id_FIO',id_FILE) VALUES ("
      "(select ID from people where FIO='"+people+"'),"
      "(select ID from FILES where File='"+file+"')"
      ");";

  rc = sqlite3_exec(db, sql.c_str(), NULL /*callback*/, 0, &zErrMsg);
  if( rc != SQLITE_OK )
  {
     log ("SQL error", zErrMsg);
     sqlite3_free(zErrMsg);
     return false;
  }
  else
  {
     return true;
  }

}

bool SQLite::clearDrivers (std::string file) {
  string sql = "DELETE FROM DRIVERS WHERE id_File=(select id from files where File='"+file+"');";
  log("SQLite::clearDrivers",sql);
  cout << sql << endl;
  rc = sqlite3_exec(db, sql.c_str(), NULL /*callback*/, 0, &zErrMsg);
  if( rc != SQLITE_OK )
  {
     log ("SQL error", zErrMsg);
     sqlite3_free(zErrMsg);
     log("SQLite::clearDrivers FALSE",sql);
     return false;
  }
  else
  {
    log("SQLite::clearDrivers TRUE",sql);
    return true;
  }
}

SQLite::SQLite ()
{
  isOpenned = false;
  fileName = string("test.db");
}


SQLite::SQLite (string tmp)
{
  isOpenned = false;
  fileName = string(tmp);
}


void SQLite::open () {
  rc = sqlite3_open(fileName.c_str(), &db);

  if( rc )
  {
    isOpenned = false;
    log ("Can't open database", sqlite3_errmsg(db));
  }
  else
  {
    isOpenned = true;
    log ("Opened database successfully");
  }

}

void SQLite::execCreateTable(string sql) {
  rc = sqlite3_exec(db, sql.c_str(), NULL /*callback*/, 0, &zErrMsg);
  if( rc != SQLITE_OK )
  {
    log("SQL error", zErrMsg);
    sqlite3_free(zErrMsg);
  }
  else
  {
    log ("Table created successfully");
  }
}

bool SQLite::createTables () {
  execCreateTable (string(_CREATE_TABLE_FILES_));
  execCreateTable (string(_CREATE_TABLE_DRIVERS_));
  execCreateTable (string(_CREATE_TABLE_PEOPLE_));
}


bool SQLite::insert(string table,string itm, string itm2){
  string sql;
  if (table == "DRIVERS")
    sql = "INSERT INTO DRIVERS ('id_FIO','id_FILE') VALUES ('" + itm +
          "','"+itm2+"');";
  if (table == "FILES")
    sql = "INSERT INTO FILES ('File') VALUES ('"+itm+"');";
  if (table == "PEOPLE")
    sql = "INSERT INTO PEOPLE ('FIO') VALUES ('"+itm+"');";
  rc = sqlite3_exec(db, sql.c_str(), NULL /*callback*/, 0, &zErrMsg);
  if( rc != SQLITE_OK )
  {
     log ("SQL error", zErrMsg);
     sqlite3_free(zErrMsg);
     return false;
  }
  else
  {
     return true;
  }

};


SQLite::~SQLite ()
{
  sqlite3_close(db);
}
