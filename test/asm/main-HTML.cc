#include <iostream>
#include <fstream>
#include <cstring>

#include "createHTML.h"

int main(int argc, char const *argv[]) {
  std::cout << "/* message */" << '\n';
  std::string ctx;
  createPage (ctx,"test title","BODY BODY BODY");
  std::cout << "ctx:\n" << ctx << "\n___________________\n\n" << '\n';

  /* code */
  return 0;
}
