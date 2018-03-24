#include "zip.h"

#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main () {
  vector<string> v = {"./testFile.txt","./zipper.cpp","./zipper.h","./zlib1.cc","./zlib-example.cpp","/etc/fstab"};

  createZip ("test.zip", v, "../zip/");
  return 0;
}
