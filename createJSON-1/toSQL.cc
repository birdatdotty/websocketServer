#include "toSQL.h"

using std::string;
using std::vector;

vector<string> toSQL::getOptins(string file) {
  if (status) {
    return sql->getDrivers(file);
  }
};
bool toSQL::setDriver (string file, string name) {
  sql->insert("FILES",file);
  sql->insert("PEOPLE",name);
  sql->setDriver(file,name);
}
toSQL::toSQL (string fileDB) {
  sql = new SQLite(fileDB);
  sql->open();
  status = sql->init();
  sql->createTables();
}
