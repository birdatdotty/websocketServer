#ifndef _PROXY_H_
#define _PROXY_H_

#include <string>
#include "Callback.h"

class proxy: public Callback {
  private:

  public:
    std::string getMessage (std::string);
};

#endif
