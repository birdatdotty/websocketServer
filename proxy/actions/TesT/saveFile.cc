#include <iostream>
#include <string>
#include <cstring>

#include <fstream>

void saveFile (std::string fileName, std::string ctx) {
	static const char* templateHTML = "<!DOCTYPE html><html><head><meta charset=\"utf-8\"><title>выбрана: "
		"%s</title></head><body>"
  	"%s</body></html>";

	char *newCtx = (char*)malloc(ctx.size() + fileName.size() + strlen(templateHTML) + 1);
	sprintf (newCtx,templateHTML,fileName.c_str(),ctx.c_str());
	std::ofstream myfile;
	myfile.open (fileName);
	myfile << newCtx;
	myfile.close();
	free(newCtx);
	return;
}

int main () {
	std::string file = "wiki/nested_parent.html";
	std::string ctx = "<p>as;lkdl;askd;asldk</p>"
		"<p>aksd;lsfksa</p>"
		"<p>vk</p>"
		"<p>;lkas</p>"
		"<p>dflksadfladskfsa;ldkf</p>"
		"<h1>l;k;lk;lk;lkl;k</h1>";

	std::cout << "file: " << file << std::endl;
	std::cout << "ctx: " << ctx << std::endl;

	saveFile (file, ctx);
	return 0;
}
