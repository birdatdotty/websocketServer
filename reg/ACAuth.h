#ifndef _ACAuth_H_
#define _ACAuth_H_

#include <string>

class ACAuth {
  public:
    virtual bool fnInsert (std::string login, std::string password)=0;
    virtual bool fnCheck (std::string login, std::string password)=0;
    virtual bool fnDelete (std::string login)=0;

    // virtual bool init(std::string)=0;
    // virtual ~ACAuth() {};
};


#endif
