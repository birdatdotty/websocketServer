#ifndef _PROXY_H_
#define _PROXY_H_

#include <string>
#include "../include/Callback.h"
#include <functional>
#include "postgres/pg.h"

class proxy: public Callback {
  private:
    void ADD_INFO_POST(std::string action);
    // my_auth* m_auth;
    // SQLite* fileDB;
    Cpg *db;
    std::function<void(std::string)> retSendAll;


  public:
    void getMessage (std::string,std::function<void(std::string)> retClient,Account* account);
    void setMessageAll (std::function<void(std::string)> retSendAll);
    std::string xhr (std::string url, std::string body);
    // void setDB (my_auth*);
    // void setFileDB (SQLite* sql);
    proxy ();
};

#endif
