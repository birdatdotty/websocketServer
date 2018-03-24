#ifndef _MY_AYTH_H_
#define _MY_AYTH_H_

#include "ACAuth.h"
#include "../sql/sql.h"


class my_auth : public ACAuth {
  private:
    std::string m_login;
    std::string m_password;
    TestSQL *db;
  public:
    my_auth ();
    ~my_auth ();
    bool fnInsert (std::string login, std::string password);
    bool fnCheck (std::string login, std::string password);
    bool fnDelete (std::string login);
    bool init(std::string);
};

#endif
