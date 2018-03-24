#include <iostream>
#include <fstream>

#include "auth.h"

using namespace std;

int main () {
  cout << "Hello, world!" << endl;
  Auth t("users.json");


  // t.loadFromJSONFile ("users.json");
  cout << "test login: " << t.validPassord("gluck","fgtkmcby") << endl;
  string key = t.addUser("gluck");
  cout << key << endl;
  cout << t.validPassord("gluck","fgtkmcby") << endl;
  cout << t.validPassord("gluck","fgtkmcby") << endl;
  cout << t.validPassord("gluck","aaa") << endl;
  std::cout << "/* message */" << '\n';
  string key1 = t.addUser("gluck");
  string key2 = t.addUser("gluck");
  cout << 1 << t.getUser(key) << key << endl;
  cout << 2 << t.getUser(key1) << key1 << endl;
  cout << 3 << t.getUser(key2) << key2 << endl;
  t.createAccount("aaaa","ppppppp");
  // t.removeAccount("user");
  t.addGroup("user","anyGroup");
  t.addGroup("user","anyGroup2");

  cout << "testGroup: " << t.testGroup("gluck","anyGroup3") << endl;
  // t.updateFileFromJSON("any.json");
  t.updateFileFromJSON();



  std::vector<std::string> v = t.getGroups("user");
  for (auto i: v)
    cout << " " << i;
  cout << endl;
  return 0;
}
