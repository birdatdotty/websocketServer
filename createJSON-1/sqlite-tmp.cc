/*
create
CREATE TABLE file(x INTEGER, y, z, PRIMARY KEY(x ASC));
*/

#define _CREATE_TABLE_files_  "CREATE TABLE DRIVERS ("  \
                              "File CHAR(250)     NOT NULL," \
                              "ID INTEGER PRIMARY KEY AUTOINCREMENT, );"

#define _CREATE_TABLE_drivers_  "CREATE TABLE DRIVERS ("  \
                                "FIO CHAR(250)     NOT NULL," \
                                "id INTEGER );"
