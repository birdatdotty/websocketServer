#include "actions.h"
#include "../reducers.h"

#include <iostream>
using namespace std;

inline string
getValue(Json::Value& obj, string val) {
  return obj[val].asString();
}


int main () {
  Auth t("users.json");
  Reducers reducers;
  reducers.setAuth(t);
  string ctx = "{\"action\":\"auth\",\"data\":{\"login\":\"gluck\",\"password\":\"fgtkmcby\"}}";
  std::cout << "ctx: " << ctx << std::endl;
  Json::Reader reader;
  Json::Value obj;
  reader.parse(ctx, obj);
  Json::Value tmp;
  Json::Value root;
  Json::FastWriter fastWriter;


  std::string action = getValue(obj,"action");
  std::cout << "Action: <" << action << ">" << std::endl;

  if (action == "auth")
    actionAuth(obj["data"],reducers);

  return 0;
}
