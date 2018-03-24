#include <string>
#include <vector>

#include "../createJSON/sqlite.h"

class toSQL {
private:
  SQLite* sql;
  bool status;
public:
  std::vector<std::string> getOptins(std::string file);
  bool setDriver (std::string file, std::string name);
  toSQL (std::string fileDB);
};
