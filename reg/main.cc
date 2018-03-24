#include "my_auth.h"
#include "../log/log.h"

#include "config.h"

#include <iostream>

using namespace std;

bool testInner (ACAuth* m_auth) {
  if(m_auth->fnCheck("Anatoliy","secret1"))
  {
    cout << "\tOK" << endl;
  };

}

int main () {
  my_auth* m_auth = new my_auth();

  if (m_auth->init(DB_FILE)) {
    // m_auth->fnInsert("Anatoliy","secret1");
    log("Check login");

    if(m_auth->fnCheck("Anatoliy","secret1"))
    {
      cout << "\tOK" << endl;
    };
    testInner(m_auth);
  }
  // else {}
  delete m_auth;

  return 0;
}
