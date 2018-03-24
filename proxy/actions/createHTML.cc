#include "createHTML.h"
#include <cstring>

#include <iostream>

bool createPage (std::string& ctx, std::string title, std::string body) {
  char*ctxTmp;
  try {
    const char* HTML = "<!DOCTYPE html><html lang='ru-RU'><head>"
      "<meta charset='UTF-8'>"
      "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
      "<meta http-equiv='X-UA-Compatible' content='ie=edge'>"
      "<title>%s</title></head><body>%s</body></html>";
    ctxTmp = (char*)malloc (strlen(HTML)+title.size()+body.size()+1);
    sprintf (ctxTmp, HTML, title.c_str(), body.c_str());
std::cout << "title: " << title.c_str() << '\n';
std::cout << "body: " << body.c_str() << '\n';
    ctx = ctxTmp;
    std::cout << "\n\tfrom createPage:" << ctx << '\n';
  } catch (...) {
    free(ctxTmp);
    return false;
  }

  free(ctxTmp);
  return true;
}
