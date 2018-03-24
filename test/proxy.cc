#include "proxy.h"

#include <iostream>
#include <string>

#include <jsoncpp/json/json.h>

using namespace std;

inline
string getValue(Json::Value& obj, string val) {
  return obj[val].asString();
}

std::string proxy::getMessage (std::string ctx) {
  Json::Reader reader;
  Json::Value obj;
  reader.parse(ctx, obj); // reader can also read strings

  string action = getValue(obj,"action");//obj["action"].asString();
  cout << "Action: <" << action << ">" << endl;

  if (action == "auth") {
    std::cout << "action == auth" << '\n';
    string user = getValue(obj,"login");
    cout << "User: " << user << endl;

    string password = getValue(obj,"password");
    cout << "Password: " << password << endl;
  }

  std::cout << "callback: " << ctx << std::endl;
  return "Final test";
}
