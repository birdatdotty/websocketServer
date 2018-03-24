#include <iostream>
#include <boost/filesystem.hpp>
#include <vector>
#include <string>
#include <jsoncpp/json/json.h>

Json::Value setAction (Json::Value json, std::string action) {
  // std::cout << "setAction" << std::endl;
  Json::Value obj = Json::objectValue;

  // std::cout << json << std::endl;

  obj["action"] = action;
  obj["data"] = json;

// std::cout << obj << std::endl;
  return obj;
}
