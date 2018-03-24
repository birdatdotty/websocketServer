#include <iostream>
#include "pg.h"
#include <vector>
#include "helperJson.h"

using namespace std;

int main() {

  Cpg a("testdb", "postgres", "fgtkmcby", "127.0.0.1",  5432);
  a.open();
  std::vector<string> v = a.getProjects();

  Json::Value preAnswer;
  for (auto i: v)
      preAnswer[i] = strToJSON(a.getPostsFromSection(i));

  std::cout << "getLoadPrj: " << getLoadPrj(v) << '\n';
  std::cout << "getLoadTask: " << getLoadTask(preAnswer,v[0]) << '\n';

  return 0;
}
