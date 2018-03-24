#include "myAuth.h"

#include <iostream>

using namespace std;

my_auth::my_auth () {
  cout << "my_auth::my_auth" << endl;
}

my_auth::~my_auth () {
  cout << "my_auth::~my_auth" << endl;
}

bool my_auth::fnInsert (std::string login, std::string password) {
  m_login = login;
  m_password = password;
  cout << "\n\tLogin: " << login << endl;
  cout << "\tPassword: " << password << endl;
  db->insert(SQLString(login, password));
}

bool my_auth::fnCheck (std::string login, std::string password) {

  // return true;
  return db->check(login, password);
}

bool my_auth::fnDelete (std::string login) {
  cout << "my_auth::fnDelete" << endl;
}

bool my_auth::init(string dbFile) {
  db = new TestSQL(dbFile);
  db->open();
  db->createTable();
  cout << "my_auth::init" << endl;
  return true;
}
