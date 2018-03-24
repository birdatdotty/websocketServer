#ifndef _SQLHELPER_H_
#define _SQLHELPER_H_
#define _CREATE_TABLE_FILES_    "CREATE TABLE FILES ( "\
                                "File CHAR(1000)  NOT NULL UNIQUE,"\
                                "ID INTEGER PRIMARY KEY AUTOINCREMENT, "\
                                "CONSTRAINT name_unique UNIQUE (File) );"

#define _CREATE_TABLE_DRIVERS_  "CREATE TABLE DRIVERS ( "\
                                "id_FIO  INTEGER    NOT NULL,"\
                                "id_FILE INTEGER    NOT NULL,"\
                                "unique(id_FIO,id_FILE) );"

#define _CREATE_TABLE_PEOPLE_   "CREATE TABLE PEOPLE ( "\
                                "FIO CHAR(250)      NOT NULL,"\
                                "ID INTEGER PRIMARY KEY AUTOINCREMENT,"\
                                "CONSTRAINT name_unique UNIQUE (FIO) );"
#endif
