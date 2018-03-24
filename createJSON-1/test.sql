createTable_files:
  CREATE TABLE FILES (
              File CHAR(1000)    NOT NULL,
              ID INTEGER PRIMARY KEY AUTOINCREMENT );

createTable_drivers:
  CREATE TABLE DRIVERS (
              id_FIO  INTEGER    NOT NULL,
              id_FILE INTEGER    NOT NULL);

createTable_people:
  CREATE TABLE PEOPLE (
              FIO CHAR(250)      NOT NULL,
              ID INTEGER PRIMARY KEY AUTOINCREMENT);

insert_file:
  INSERT INTO FILES ('File') VALUES ('/any.file');

insert_driver:
  INSERT INTO DRIVERS ('id_FIO',id_FILE) VALUES (1,1);
  INSERT INTO DRIVERS ('id_FIO',id_FILE) VALUES (
    (select ID from people where FIO="Anatoliy"),
    (select ID from FILES where File="file1")
    );

insert_people:
  INSERT INTO PEOPLE ('FIO') VALUES ('Vasya');


getDriver:
  file1->Anatoliy
  select id from files where File="file1";
  select id_FIO from drivers where id_FILE=(select id from files where File="file1");
  select FIO from people where id=(select id_FIO from drivers where id_FILE=(select id from files where File="file1"));

clearDriver:
  DELETE FROM DRIVERS WHERE id_File=(select id from files where File="file1");
