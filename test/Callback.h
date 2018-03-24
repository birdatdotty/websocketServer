#ifndef _CALLBACK_H_
#define _CALLBACK_H_

#include <string>

class Callback {
  public:
    virtual std::string getMessage (std::string)=0;
};

#endif
