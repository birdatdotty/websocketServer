#include <iostream>

#include "proxy.h"

using namespace std;

int main() {
  proxy* test = new proxy();
  cout << "Hello, world!" << endl;

  test->getMessage ("{\"action\":\"auth\",\"login\":\"gluck\",\"password\":\"password\"}");
  return 0;
}
