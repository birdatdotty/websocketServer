#ifndef _SQLSTRING_H_
#define _SQLSTRING_H_

#include <string>
class SQLString : public std::string {
    std::string name;
    std::string password;
    SQLString ();
  public:
    std::string insert();

    SQLString (std::string, std::string);
};

#endif
