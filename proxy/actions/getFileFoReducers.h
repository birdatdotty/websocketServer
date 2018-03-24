#ifndef _GETFILEFOREDUCERS_H_
#define _GETFILEFOREDUCERS_H_
#include <string>
#include <jsoncpp/json/json.h>

Json::Value list_file(Json::Value& dir, std::string selDir);
Json::Value list_dir(std::string selDir);
#endif
