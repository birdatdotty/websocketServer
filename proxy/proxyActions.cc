#define ADD_INFO_POST \
  if (action == "ADD_INFO_POST") {\
    std::string creater = getCreater(obj["data"]["msg"]);\
    db->insertInfoPost(creater, jsonToStr(obj["data"]["msg"]));\
    Json::Value pre;\
    pre["action"] = "LOAD_INFO";\
    pre["data"] = db->getInfoPosts();\
    retClient( jsonToStr(pre) );\
  }

#define SET_SCHEDULE \
  if (action == "SET_SCHEDULE") {\
    std::string creater = getCreater(obj["data"]["msg"]);\
    db->insertMisc("schedule", jsonToStr(obj["data"]["msg"]));\
    Json::Value pre;\
    pre["action"] = "LOAD_SCHEDULE";\
    pre["data"] = strToJSON(db->getMisc("schedule"));\
    retClient( jsonToStr(pre) );\
  }


#define ADD_INFO_POST_LINE \
  if (action == "ADD_INFO_POST_LINE") {\
    std::string creater = getCreater(obj["data"]["msg"]);\
    db->appendInfoPost(obj["data"]["msg"]["id"].asString(), jsonToStr(obj["data"]["msg"]["data"]));\
    Json::Value pre;\
    pre["action"] = "LOAD_INFO";\
    pre["data"] = db->getInfoPosts();\
    retClient( jsonToStr(pre) );\
  }
