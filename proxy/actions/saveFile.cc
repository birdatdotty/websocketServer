#include <fstream>

#include <boost/filesystem.hpp>
using namespace boost::filesystem;

#include <boost/locale.hpp>

#include <iostream>

bool saveFile (std::string myPath, std::string fileName, std::string data) {
  using namespace boost::locale;
  using namespace std;
  generator gen;
  locale loc=gen("");
  // Create system default locale

  // locale::global(loc);
  // // Make it system global
  //
  // cout.imbue(loc);
  // // Set as default locale for output
  //
  //
  // myPath = boost::locale::to_title(myPath);
  int i;
  std::replace( myPath.begin(), myPath.end(), ' ', '_');

  path p =  path(myPath);
  path dirP = p;
  dirP/=path(fileName);
  path tmpDir;
std::cout << "path: " << dirP << '\n';
  for (path::iterator it = dirP.begin(); it != dirP.end(); ++it) {
    tmpDir /= *it;
    cout << "\tit: " << *it << "|" << tmpDir << endl;
    std::cout << "create_directory0" << '\n';
    if (*it == "..") return false;
    std::cout << "create_directory1" << '\n';
    std::cout << "tmpDir:" << tmpDir << '\n';
    if (path(tmpDir) != dirP)
      boost::filesystem::create_directory(path(tmpDir));
    std::cout << "create_directory2" << '\n';
  }
  std::cout << "myPath: " << myPath << '\n';
  std::cout << "["<< p  << "]"<< '\n';
  p/=path(fileName);
  // try {
    // boost::filesystem::create_directory(path(myPath));
std::cout << "path: " << p << '\n';
std::cout << "path: " << p.string() << '\n';

std::cout << "ctx:" << data << '\n';
std::cout << "-------------" << '\n';
    std::ofstream fd(p.string());
    // fd.open (p.string());
std::cout << "is open: " << fd.is_open() << '\n';
    fd << data << std::endl;
//
// std::ofstream myfile (p.string());
// if (myfile.is_open())
// {
//   myfile << "This is a line.\n";
//   myfile << "This is another line.\n";
//   myfile.close();
// }
// else cout << "Unable to open file";
//
    // fd.flush();
    // fd.close();

    return true;
}
