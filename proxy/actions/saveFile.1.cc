#include <fstream>

#include <boost/filesystem.hpp>
using namespace boost::filesystem;

#include <boost/locale.hpp>



bool saveFile (std::string myPath, std::string fileName, std::string data) {
  using namespace boost::locale;
  using namespace std;
  generator gen;
  locale loc=gen("");
  // Create system default locale

  locale::global(loc);
  // Make it system global

  cout.imbue(loc);
  // Set as default locale for output


  myPath = boost::locale::to_title(myPath);
  int i;
  std::replace( myPath.begin(), myPath.end(), ' ', '_');
  // while((i = myPath.find(' '))!=std::string::npos)
    // myPath.erase(i, 1);

  std::cout << "myPath: " << myPath << '\n';
  path p =  path(myPath);
  p/=path(fileName);
  try {
    boost::filesystem::create_directory(path(myPath));

    std::ofstream fd(p.string());
    fd.open (p.string());
    fd << data;
    fd.close();

    return true;
  }
  catch (...) {return false;};
}
