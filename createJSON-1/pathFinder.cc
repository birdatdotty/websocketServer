#include <iostream>
#include <boost/filesystem.hpp>
#include <vector>
#include <string>
#include <jsoncpp/json/json.h>

#include "../config.h"
#include "sqlite.h"
#include "toSQL.h"

using std::vector;
using std::cout;
using std::endl;
using std::string;
using namespace boost::filesystem;

static toSQL* SQL;
// =new toSQL("any.db");


struct pathName {
  string path;
  string name;
  string type;
  pathName(string p, string n, string t) {
    path = p;
    name = n;
    type = t;
  }
};

Json::Value getOptins (std::string str) {
  Json::Value obj = Json::objectValue;// obj("aaa");
  Json::Value arr = Json::arrayValue;
  //////////////////////////////////////////////ssssssssssssssssssssssssssssss
  // arr.append("Any text");
  // arr.append("Text 2");
  vector <string> tmpOptions = SQL -> getOptins(str);
  for (auto item : tmpOptions) {
    arr.append(item);
  }
  // arr.push_back("Json::Value")
  obj["drivers"] = arr;
  return Json::Value(obj);
}

string getDesc (string fullFileName) {
  return fullFileName;
}

// Пример входящего сообщения
// {"id":2,"name":"file2","desc":"Description","options":{"drivers":["vasya2","petya2"]}},
template <typename Iterable>
Json::Value iterable2json(Iterable const& cont) {
  int id = 0;
  Json::Value v;
  for (auto&& element: cont) {
    Json::Value el;
    el [ "id" ] = id;
    el [ "name" ] = element.name;
    el [ "path" ] = element.path;
    el [ "type" ] = element.type;
    // el [ "desc" ] = "без описания";
    el [ "fullName" ] = getDesc (element.path+SLASH+element.name);
    if (element.type == "file")
      el [ "options"] = getOptins(element.path+SLASH+element.name);

    v.append(el);
    ++id;
   }
   return v;
}


bool list (path p, string pre, std::vector<pathName>& v, string fileName="NULL") {
  try
  {
    if (exists(p))
    {
      if (is_regular_file(p))
        cout << p << " size is " << file_size(p) << '\n';

      else if (is_directory(p))
      {
        for (directory_entry& x : directory_iterator(p)) {
          if (is_directory(x.path())) {
            v.push_back(pathName(pre,
                                 x.path().filename().string(),
                                 "dir" ));

            list (x.path(),
                  pre+SLASH+x.path().leaf().string(),
                  v );
          }
          else
            v.push_back(pathName( pre,
                                   x.path().filename().string(),
                                   "file" ));
        }
      }
      else
      {
        cout << p << " exists, but is not a regular file or directory\n";
      }
    }
    else
      cout << p << " does not exist\n";
  }
  catch (const filesystem_error& ex)
  {
    cout << ex.what() << '\n';
    return false;
  }

  Json::Value json = iterable2json(v);
  // Json::FastWriter fastWriter;
  // std::string tmp = fastWriter.write(json);


  if (fileName!="NULL") {
    Json::FastWriter writer;
    std::ofstream outFile;
    outFile.open(fileName.c_str());
    outFile << writer.write(json);
    outFile.close();
  }

  return true;
}

bool reIndexDir ( string dir,
                  string fileName="file.json",
                  string fileDB=DB_FILE) {
  SQL=new toSQL(fileDB);
  std::vector<pathName> v;

  path p (dir);
  list (p,(p.leaf()).string(),v, fileName);

  return true;
}
