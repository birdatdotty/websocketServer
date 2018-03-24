#ifndef _SQLHELPER_H_
#define _SQLHELPER_H_

#define _CREATE_TABLE_  "CREATE TABLE AUTH ("  \
                        "login CHAR(250)     NOT NULL," \
                        "password CHAR(250) NOT NULL );"

#define _SELECT_PASSWORD1_ "SELECT PASSWORD from AUTH WHERE LOGIN='"
#define _SELECT_PASSWORD2_ "'"

#define _SELECT_PASSWORD_(i) "SELECT PASSWORD from AUTH WHERE LOGIN='"+#i+"''"


#define _INSERT_AUTH_(l,p) ("INSERT INTO AUTH (login, password) "\
                            "VALUES ('"#l"', '"#p"'); ")

inline
std::string insertAuth (std::string login, std::string password)
{
  return ("INSERT INTO AUTH (login, password) VALUES ('" +
    login+"', '"+password+"'); ");
}



#endif
