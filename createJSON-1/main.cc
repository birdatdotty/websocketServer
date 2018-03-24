#include <iostream>
#include <boost/filesystem.hpp>
#include <vector>
#include <string>
#include <jsoncpp/json/json.h>

#include "config.h"
#include "sqlite.h"
#include "toSQL.h"
#include "pathFinder.h"

#include <fstream>

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
  std::string file = "tmp2.json";
  if (argc < 2)
  {
    cout << "Usage: tut3 path\n";
    return 1;
  }
  reIndexDir (argv[1],file);

  // std::vector<pathName> v;
  //
  // path p (argv[1]);
  // list (p,(p.leaf()).string(),v,"file.json");
  std::fstream a(file, std::ios::in);
  const int c = 100000000;
  static char buf[c];
  // open;
  // a >> buf;
  a.read(buf,c);
  cout << buf << endl;
  a.close();

  return 0;
}
