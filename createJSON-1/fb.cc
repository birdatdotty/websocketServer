#include <string>
#include <iostream>
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

int main()
{
    std::string path = "./";
    for (auto & p : fs::directory_iterator(path))
        std::cout << p << std::endl;
}
