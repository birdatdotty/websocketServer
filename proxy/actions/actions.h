#ifndef _ACTIONS_H_
#define _ACTIONS_H_

#include "saveFile.h"
#include "getFileFoReducers.h"
#include "createHTML.h"

#include <jsoncpp/json/json.h>
#include "../reducers.h"
#include <string.h>
#include "../postgres/pg.h"
// #include "../auth/auth.h"

bool actionAuth(Json::Value& data, Reducers& t);
bool actionAuthReconnect(Json::Value &data,Reducers& t);
std::string keyToUser(Json::Value data,Reducers& t);
std::string keyToUserReconnect(Json::Value data,Reducers& t);
void fileUpload(Json::Value &obj);
void filesUpload(Json::Value &obj);
void fileCreateHTML(Json::Value &obj);
void savePageList (Json::Value &obj);
std::string getGallery ();
std::string getLibrary ();
std::string getAchivements(Cpg *db);
std::string getTeachers(Cpg *db);
std::string getLoadInfo (Cpg *db);
std::string getLoadSchedule (Cpg *db);

#endif
