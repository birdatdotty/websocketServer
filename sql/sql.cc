#include "../sql/sql.h"
#include "../log/log.h"
#include "SQLHelper.h"

#include <sstream>
#include <iostream>
#include <cstring>

using std::string;
using std::cout;
using std::endl;

static int callbackSelect(void *tmp_data, int argc, char **argv, char **azColName){
  int i;
  string* data = (string*)tmp_data;

  for(i = 0; i<argc; i++)
  {
    *data = argv[i] ? argv[i] : "NULL";
  }

  return 0;
}

TestSQL::TestSQL ()
{
  isOpenned = false;
  fileName = string("test.db");
}


TestSQL::TestSQL (string tmp)
{
  isOpenned = false;
  fileName = string(tmp);
}


void TestSQL::open () {
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


bool TestSQL::createTable () {
  string sql = _CREATE_TABLE_;
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


std::string TestSQL::getPassword (std::string login) {
  string sql = _SELECT_PASSWORD1_ + login + _SELECT_PASSWORD2_;
  string data = string("callbackSelect function called");
  /* Execute SQL statement */
  rc = sqlite3_exec(db, sql.c_str(), callbackSelect, (void*)&data, &zErrMsg);

  if( rc != SQLITE_OK )
  {
    log ("SQL error", zErrMsg);
    sqlite3_free(zErrMsg);
  }
  else
  {
    log ("Operation done successfully");
  }

  return data;
}

bool TestSQL::insert(SQLString itm){
  string sql = strdup(itm.insert().c_str());

  rc = sqlite3_exec(db, sql.c_str(), NULL /*callback*/, 0, &zErrMsg);
  if( rc != SQLITE_OK )
  {
     log ("SQL error", zErrMsg);
     sqlite3_free(zErrMsg);
     return true;
  }
  else
  {
     return false;
  }

};

bool TestSQL::check(std::string login,std::string password) {
  cout << "TestSQL::check login: " << login << endl;
  cout << "TestSQL::check password: " << password << endl;

  return (getPassword(login)==password);
}


TestSQL::~TestSQL ()
{
  sqlite3_close(db);
}
