#include <string>
using std::string;

#include <boost/lexical_cast.hpp>
using boost::lexical_cast;

#include <boost/uuid/uuid.hpp>
using boost::uuids::uuid;

#include <boost/uuid/uuid_generators.hpp>
using boost::uuids::random_generator;

#include <boost/uuid/uuid_io.hpp>

string make_uuid()
{
    return lexical_cast<string>((random_generator())());
}

#include <iostream>

int main(int argc, char const *argv[]) {
  std::cout << make_uuid() << std::endl;
  return 0;
}
