#include "actions.h"
// #include "../auth/auth.h"
#include "../reducers.h"
#include "../b64/b64.h"
#include "saveFile.h"
#include "../postgres/helperJson.h"
#include "createHTML.h"
#include "../../config.h"


#include <iostream>

#include <boost/filesystem.hpp>
using namespace boost::filesystem;

using namespace std;

std::string keyToUser(Json::Value data,Reducers& t) {
  string key = data["key"].asString();
  return (*t.auth).getUser(key);
}

std::string keyToUserReconnect(Json::Value data,Reducers& t) {
  std::cout << "/* keyToUserReconnect */" << '\n';
  std::cout << data << '\n';
  string key = data["key"].asString();
  std::cout << "(*t.auth).getUser(key):" << (*t.auth).getUser(key)  << '\n';
  return (*t.auth).getUser(key);
}

std::string getGallery () {
  std::cout << "/* message */" << list_dir("Gallary") << '\n';
  Json::Value pre;
  pre["action"] = "GALLERY_SET";
  pre["data"] = list_dir("Gallary");
  return jsonToStr(pre);
}

std::string getLoadSchedule (Cpg *db) {
  Json::Value pre;
  pre["action"] = "LOAD_SCHEDULE";
  pre["data"] = strToJSON(db->getMisc("schedule"));
  return jsonToStr(pre);
}

std::string getLoadInfo (Cpg *db) {
  Json::Value pre;
  pre["action"] = "LOAD_INFO";
  pre["data"] = db->getInfoPosts();
  return jsonToStr(pre);
}

std::string getAchivements(Cpg *db) {
  Json::Value pre;
  pre["action"] = "LOAD_ACHIEVEVEMENTS";
  pre["data"] = db->getAchivements();
  return jsonToStr(pre);
}

std::string getLibrary () {
  std::cout << "/* message */" << list_dir("Gallary") << '\n';
  Json::Value pre;
  pre["action"] = "LIBRARY_SET";
  pre["data"] = list_dir("Library");
  return jsonToStr(pre);
}

std::string getTeachers(Cpg *db) {
  Json::Value pre;
  pre["action"] = "TEACHERS_SET";
  pre["data"] = db->getTeachers();
  // std::cout << "getTeachers: "  << pre << '\n';
  // std::cout << "----------------------" << '\n';
  // std::cout << "jsonToStr(pre): " << jsonToStr(pre) << '\n';
  return jsonToStr(pre);
}

void fileUpload(Json::Value &obj) {
  std::cout << "FILE_UPLOAD" << '\n';
  std::cout << "++++++++++++++" << '\n';
  std::cout << obj["data"] << '\n';
  std::cout << "++++++++++++++" << '\n';
  std::string fileName = obj["data"]["name"].asString();
  std::string preData = obj["data"]["file"].asString();
  std::string data = base64_decode(preData);
  std::string path = obj["data"]["target"].asString() + "/" + obj["data"]["path"].asString();
  saveFile (path, obj["data"]["name"].asString(), data);
}

void fileCreateHTML(Json::Value &obj) {
  // createHTML()
  // std::cout << obj["data"] << '\n';
  std::string ctx;
  if (
    createPage (ctx,obj["data"]["title"].asString(),obj["data"]["ctx"].asString())
  ) {
    std::cout << "\n\n\tfile ctx:" << '\n';
    std::cout << ctx << '\n';
    std::cout << "/* message */" << '\n';
    std::string fileName = obj["data"]["page"].asString();
    saveFile (SITE "/crowler", fileName, ctx);

    fileName.erase( fileName.end() - 1 );
    fileName.erase( fileName.end() - 1 );
    fileName.erase( fileName.end() - 1 );
    fileName.erase( fileName.end() - 1 );
    fileName += std::string("json");
    // Json::Value tmp;
    // tmp["ctx"] = obj["data"]["html"];
    // tmp["title"] = obj["data"]["title"];
    saveFile (SITE "/json", fileName, jsonToStr(obj["data"]));
  }
}

void savePageList (Json::Value &obj) {
  std::cout << "&obj" << obj << '\n';
  std::cout << "&obj[data]" << obj["data"] << '\n';
  saveFile (SITE "/json/", "list.json", jsonToStr(obj));
}

void fileUpload2(Json::Value &obj) {
  std::cout << "FILE_UPLOAD" << '\n';
  std::cout << "++++++++++++++" << '\n';
  // std::cout << obj << '\n';
  std::cout << "++++++++++++++" << '\n';
  std::string fileName = obj["name"].asString();
  std::string preData = obj["file"].asString();
  std::string data = base64_decode(preData);
  // std::string path = obj["data"]["target"].asString() + "/" + obj["data"]["path"].asString();
  std::string path = obj["target"].asString() + "/" + obj["path"].asString();
  cout << obj["target"].asString() + "/" + obj["path"].asString() << endl;
  std::cout << "path" << '\n';
  saveFile (path, obj["name"].asString(), data);
}

// {"name":"вход.jpg","target":"Library","path":"Гимназия","file":"/9
void filesUpload(Json::Value &obj) {
  std::cout << "obj: " << obj << '\n';
  for (Json::Value::ArrayIndex i = 0; i != obj.size(); i++){
    // std::cout << "obj[data][i]: " << obj["data"][i] << '\n';
    fileUpload2(obj["data"][i]);
  }
    // if (obj[i].isMember("attr1"))
    //     values.push_back(root[i]["attr1"].asString());


  // std::string fileName = obj["data"]["name"].asString();
  // std::string preData = obj["data"]["file"].asString();
  // std::string data = base64_decode(preData);
  // std::string path = obj["data"]["target"].asString() + "/" + obj["data"]["path"].asString();
  // saveFile (path, obj["data"]["name"].asString(), data);
}


bool actionAuth(Json::Value &data,Reducers& t) {
  string key, login, password, tmp;
  Json::Value answ, answData;
  answ ["action"] = "auth";
  Json::FastWriter fastWriter;

  login = data["login"].asString();
  password = data["password"].asString();
  std::cout << "login,password" << login << ", " << password << '\n';
  bool isTrue = (*t.auth).validPassord(login,password);
  if (isTrue) {
    key = (*t.auth).addUser(login);
    std::cout << "password is correct!" << '\n';
    answData ["login"] = true;
    answData ["user"] = login;
    answData ["key"] = key;
    answ["data"] = answData;
    tmp = fastWriter.write(answ);
    t.retClient(tmp);
    data["UserName"] = key;
    t.acc->setName(t.auth->getUser(key));
  }
  else
    t.retClient("{\"action\":\"auth\",\"data\":{\"status\":false}}");
    // std::cout << "BAD PASSWORD" << '\n';

  return isTrue;
}

bool actionAuthReconnect(Json::Value &data,Reducers& t) {
  string key, login, password, tmp;
  Json::Value answ, answData;
  answ ["action"] = "auth";
  Json::FastWriter fastWriter;

  login = keyToUserReconnect(data,t);
  std::cout << "actionAuthReconnect>login:" << login << '\n';
  // data["login"].asString();
  password = data["password"].asString();
  std::cout << "login,password" << login << ", " << password << '\n';
  // bool isTrue = (*t.auth).validPassord(login,password);
  bool isTrue = login.size()>0;
std::cout << "bool isTrue = login.size()>0"  << '\n';
  if (isTrue) {
    key = (*t.auth).addUser(login);
    std::cout << "password is correct!" << '\n';
    answData ["status"] = true;
    answData ["login"] = login;
    answData ["key"] = key;
    answ["data"] = answData;
    cout << answ << endl;
    tmp = fastWriter.write(answ);
    cout << tmp << endl;
    t.retClient(tmp);
    data["UserName"] = key;
    std::cout << ">>> key" << key << '\n';
    t.acc->setName(t.auth->getUser(key));
  }
  else
    t.retClient("{\"action\":\"auth\",\"data\":{\"status\":false}}");
    // std::cout << "BAD PASSWORD" << '\n';

  return isTrue;
}
