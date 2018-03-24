#include <string>
#include <vector>

#include <iostream>
#include <cstdlib>

using namespace std;


inline string vectorToString(vector<string> v, string pre) {
  string res = "";
  string tmp;
  for (auto i: v) {
    if (i.substr(0,2) == "./")
      tmp = " '" + pre + "/" + i.substr(2) + "'";
    else
      tmp = " '" + pre + "/" + i + "'";
    res += tmp;
  }
  return res;
}


bool createZip (string toFileName, vector<string> files, string pre="") {
  cout << "createZip!" << endl;
  string cmd = "7z a";
  cmd += " ";
  cmd += toFileName;
  cmd += vectorToString(files, pre);
  system (cmd.c_str());
  cout << cmd << endl;
}
