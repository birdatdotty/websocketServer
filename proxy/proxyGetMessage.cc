#include "proxy.h"

#include <iostream>
#include <string>

#include <jsoncpp/json/json.h>
#include "../config.h"
#include "../log/log.h"

#include "../config.h"
#include "actions/actions.h"
#include "reducers.h"
#include "auth/auth.h"
#include "postgres/helperJson.h"

#include <functional>
#include <boost/filesystem.hpp>

#include "proxyActions.h"

// namespace fs = boost::filesystem;
using namespace std;

inline string
getValue(Json::Value& obj, string val) {
  return obj[val].asString();
}

inline
std::vector<string> getArr(Json::Value& obj, string val) {
  Json::Value tmp = obj[val];
  std::vector<string> v;
  for (Json::ValueConstIterator it = tmp.begin(); it != tmp.end(); ++it)
  {
    const Json::Value& item = *it;
    v.push_back(item.asString());
    // rest as before
  }
  return v;
}
void proxy::setMessageAll (std::function<void(std::string)> retSendAll) {
  this->retSendAll = retSendAll;
}


void proxy::getMessage (std::string ctx,std::function<void(std::string)> retClient, Account* account) {
  static Auth t("users.json");
  static Reducers reducers;
  reducers.setAuth(t);
  reducers.setRetClient(retClient);
  reducers.setAccount(account);


  std::cout << "ctx: " << ctx << std::endl;
  Json::Reader reader;
  Json::Value obj;
  bool parsingSuccessful = reader.parse(ctx, obj);
  if ( !parsingSuccessful )
    return;
    
  Json::Value tmp;
  Json::Value root;
  Json::FastWriter fastWriter;


  std::string action = getValue(obj,"action");
  std::cout << "Action: <" << action << ">" << std::endl;
  std::string key = getValue(obj,"key");
  std::cout << "key: <" << key << ">" << std::endl;
  std::string user = keyToUser(obj,reducers);
  std::cout << "key: <" << user << ">" << std::endl;


  if (action == "auth")
    if (actionAuth(obj["data"],reducers)) {
        // Отправить всё что положено
        // example: retClient("TEST");
        Json::Value pre;
        pre["action"] = "LOAD_INFO";
        pre["data"] = db->getInfoPosts();
        retClient( jsonToStr(pre) );


        // Json::Value pre;
        pre["action"] = "LOAD_SCHEDULE";
        pre["data"] = strToJSON(db->getMisc("schedule"));
        retClient( jsonToStr(pre) );
        // account->setName()
        std::cout << "/* message */  actionAuth : " << obj << '\n';
        std::cout << "accout->getName(): " << account->getName() << '\n';

    }
  if (user.size()>0) {
    if (action == "CHAT_GET")
    retSendAll(jsonToStr(obj));


    ADD_INFO_POST
    SET_SCHEDULE
    ADD_INFO_POST_LINE
    // if (action == "ADD_INFO_POST") {
    //   std::string creater = getCreater(obj["data"]["msg"]);
    //   db->insertInfoPost(creater, jsonToStr(obj["data"]["msg"]));
    //   Json::Value pre;
    //   pre["action"] = "LOAD_INFO";
    //   pre["data"] = db->getInfoPosts();
    //   retClient( jsonToStr(pre) );
    // }

    // if (action == "SET_SCHEDULE") {
    //   std::string creater = getCreater(obj["data"]["msg"]);
    //   db->insertMisc("schedule", jsonToStr(obj["data"]["msg"]));
    //   Json::Value pre;
    //   pre["action"] = "LOAD_SCHEDULE";
    //   pre["data"] = strToJSON(db->getMisc("schedule"));
    //   retClient( jsonToStr(pre) );
    // }
    //
    // if (action == "ADD_INFO_POST_LINE") {
    //   std::string creater = getCreater(obj["data"]["msg"]);
    //   db->appendInfoPost(obj["data"]["msg"]["id"].asString(), jsonToStr(obj["data"]["msg"]["data"]));
    //
    //   Json::Value pre;
    //   pre["action"] = "LOAD_INFO";
    //   pre["data"] = db->getInfoPosts();
    //   retClient( jsonToStr(pre) );
    // }
}
  std::cout << "callback: " << ctx << std::endl;
}

proxy::proxy () {
  db = new Cpg("testdb", "postgres", "fgtkmcby", "127.0.0.1",  5432);
  db->open();
  db->createTable();
}
