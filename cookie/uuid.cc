#include <string>

#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

std::string getUUID () {
  boost::uuids::uuid uuid = boost::uuids::random_generator()();
  return to_string(uuid);
}
