#include <iostream>
#include <fstream>
#include <cstring>
#include "saveFile.h"

#include "createHTML.h"
#include "saveFile.h"

int main(int argc, char const *argv[]) {
  std::cout << "/* message */" << '\n';
  std::string ctx;
  createPage (ctx,"test title","BODY BODY BODY");
  std::cout << "ctx:\n" << ctx << "\n___________________\n\n" << '\n';
  saveFile("/tmp/asd/asdasd/./11/./22/asdcq11","gluck2","kkkkkkkk");

  /* code */
  return 0;
}
