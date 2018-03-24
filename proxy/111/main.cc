#include <iostream>
#include <string>

#include <jsoncpp/json/json.h>

using namespace std;



int main () {
  string ctx = "{\"action\":\"do\",\"data\":{\"text\":\"saaa\"},\"key\":{\"login\":\"gluck\",\"password\":\"asdasd\"}}";
  Json::Reader reader;
  Json::Value obj, obj2;
  reader.parse(ctx.c_str(), obj);

  cout << obj["action"] << endl;
  cout << obj["data"]["text"] << endl;
  cout << "--------------1" << endl;
  cout << obj["key"] << endl;
  cout << "--------------2" << endl;
  cout << obj["key"].isObject() << endl;
  cout << "--------------3" << endl;
  if (obj["key"].isObject())
  cout << obj["key"]["login"] << endl;
  cout << "--------------4" << endl;

  Json::Value array;
  array.append("hello");
  array.append("world");
  obj["test"]=array;

  Json::Value q;
  q["one"] = 1;
  q["two"] = 2;

  obj["data"] = q;



  Json::FastWriter fastWriter;
  std::string jsonMessage = fastWriter.write(obj);
  cout << "jsonMessage:\n" << jsonMessage << endl;



  return 0;
}
