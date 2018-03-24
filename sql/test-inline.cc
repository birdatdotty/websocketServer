// #include <string>
//
// using std::string;
//
inline 
string insertAuth (string login, string password)
{
  string tmp = ("INSERT INTO AUTH (login, password) VALUES ('" +
    login+"', '"+password+"'); ");
  return tmp;
}
