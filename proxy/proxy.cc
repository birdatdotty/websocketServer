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
#include <fstream>
#include <iostream>

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

std::string proxy::xhr (std::string url, std::string body) {
  if (url == "/index.html")
    return "<h2>пробное содежимое:)</h2>";
  return "It's test from proxy!\n url:" + url+"\n body:"+body+ "\n-----------------\n";
}

void proxy::getMessage (std::string ctx,std::function<void(std::string)> retClient, Account* account) {
  static Auth t("/users.json");
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

  try {
    std::string action = getValue(obj,"action");
    std::cout << "Action: <" << action << ">" << std::endl;
    std::string key = getValue(obj,"key");
    std::cout << "key: <" << key << ">" << std::endl;
    std::string user = keyToUser(obj,reducers);
    std::cout << "key: <" << user << ">" << std::endl;


    if (action == "auth")
      if (actionAuth(obj["data"],reducers)) {
          // retClient(getLoadInfo(db));
          // retClient(getLoadSchedule(db));
          // retClient(getGallery());
          // retClient(getLibrary());
          // retClient(getAchivements(db));
          // retClient(getTeachers(db));
      }

    // if (action == "reconnect") {
    //   if(actionAuthReconnect(obj,reducers))
    //   {
    //     std::cout << "user: " << user << '\n';
    //     Json::Value pre;
    //     pre["action"] = "LOAD_INFO";
    //     pre["data"] = db->getInfoPosts();
    //     std::cout << "LOAD_INFO: " << pre << '\n';
    //     retClient( jsonToStr(pre) );
    //
    //     pre["action"] = "LOAD_SCHEDULE";
    //     pre["data"] = strToJSON(db->getMisc("schedule"));
    //     std::cout << "LOAD_SCHEDULE: " << pre<< '\n';
    //     retClient( jsonToStr(pre) );
    //     std::cout << "/* message */  actionAuth : " << obj << '\n';
    //     std::cout << "accout->getName(): " << account->getName() << '\n';
    //     retClient(getGallery());
    //     retClient(getLibrary());
    //     retClient(getAchivements(db));
    //     retClient(getTeachers(db));
    //   }
    // }


    if (user.size()>0) {
      std::cout << "    if (user.size()>0) " << action << '\n';
      if (action == "CHAT_GET")
        retSendAll(jsonToStr(obj));

      if (action == "SET_CONTENT_ON_PAGE")
        fileCreateHTML(obj);

      // if (action == "SET_CONTENT_ON_PAGE") {
      //   std::cout << "/* message */" << obj << '\n';
      //   std::string page = obj["data"]["page"].asString();
      //   std::string html = obj["data"]["html"].asString();
      //   std::cout << "/* message kkkkkkkkkkkkkkkkk*/" << '\n';
      //   std::cout << page << "|" << html << '\n';
      //   std::cout << "/* message */" << '\n';
      //   // db->insertInfoPost(creater, jsonToStr(obj["data"]["msg"]));
      //   // Json::Value pre;
      //   // pre["action"] = "LOAD_INFO";
      //   // pre["data"] = db->getInfoPosts();
      //   // retSendAll( jsonToStr(pre) );
      // }

      if (action == "SET_PAGE_LIST") {
        savePageList(obj["data"]);
      }

      if (action == "SET_SCHEDULE")
      {
        std::cout << "testGroup: " << t.testGroup(user,"SCHEDULE") << '\n';
        if (t.testGroup(user,"SCHEDULE")) {
        std::string creater = getCreater(obj["data"]["msg"]);
        db->insertMisc("schedule", jsonToStr(obj["data"]["msg"]));
        Json::Value pre;
        pre["action"] = "LOAD_SCHEDULE";
        pre["data"] = strToJSON(db->getMisc("schedule"));
        retSendAll( jsonToStr(pre) );
      }}

      if (action == "ADD_INFO_POST_LINE")
      if (t.testGroup(user,"INFO_POST")) {
        std::string creater = getCreater(obj["data"]["msg"]);
        db->appendInfoPost(obj["data"]["msg"]["id"].asString(), jsonToStr(obj["data"]["msg"]["data"]));

        Json::Value pre;
        pre["action"] = "LOAD_INFO";
        pre["data"] = db->getInfoPosts();
        retSendAll( jsonToStr(pre) );
      }
      if (action == "FILE_UPLOAD") {
        fileUpload (obj);
        retSendAll(getGallery());
        retSendAll(getLibrary());
        std::cout << "getLibrary(): " << getLibrary() << '\n';
      }
      if (action == "FILES_UPLOAD") {
        filesUpload (obj);
        retSendAll(getGallery());
        retSendAll(getLibrary());
        std::cout << "getLibrary(): " << getLibrary() << '\n';
      }
      if (action == "SET_ACHIEVEVEMENTS") {
        std::cout << "SET_ACHIEVEVEMENTS: " << user << obj << obj["data"] << '\n';
        db->insertAchivements(user,jsonToStr(obj["data"]));
        Json::Value pre;
        pre["action"] = "ADD_ACHIEVEVEMENT";
        pre["data"] = strToJSON(jsonToStr(obj["data"]));
        retSendAll( jsonToStr(pre) );
      }
    }
  } catch (...) {return;}
}

proxy::proxy () {
  db = new Cpg("testdb", "postgres", "fgtkmcby", "127.0.0.1",  5432);
  db->open();
  db->createTable();
}
