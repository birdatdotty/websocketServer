#include <iostream>
#include <pqxx/pqxx> 

using namespace std;
using namespace pqxx;

int main(int argc, char* argv[]) {
   char * sql;
   
   try {
      connection C("dbname = testdb user = postgres password = fgtkmcby \
      hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open()) {
         cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         return 1;
      }

      /* Create SQL statement */
      sql = "INSERT INTO posts(section,title,post)"
            "VALUES ('main','TEST2',"
            "'{\"ctx\":\"<p><strong>foius2da2f oiu2sdaoi f sadf l2k</strong></p><p>kla2sdfjslkdk sfad xckj lkj 2adflkj aklasjdkjl skajk lk 2lkj lkj lkjsdalkf22222jlsdkafjdsalkfj</p><h2>l kjlksj alkjds aflkdsajf lkjdsf asdf osaiduf 222oiuodsiauf osdiaf222 osai uweoiruewoi22 usoidfuoasdiufoisadu oidsau foiasdu</h2> <p>asd</p> <p>222asd</p><p><br></p>\"}');";
      cout << "sql: " << sql << endl;
      /* Create a transactional object. */
      work W(C);
      
      /* Execute SQL query */
      W.exec( sql );
      W.commit();
      cout << "Records created successfully" << endl;
      C.disconnect ();
   } catch (const std::exception &e) {
      cerr << e.what() << std::endl;
      return 1;
   }

   return 0;
}



SELECT json_agg(post) result FROM posts WHERE section='main';
SELECT CONCAT('{"id":',id,',"data":',post,'}') FROM posts;
SELECT json_agg('{"id":',id,',"data":',post,'}') result FROM posts WHERE section='main';

SELECT json_build_object('id',id,'data',post) result FROM posts WHERE section='main';

SELECT json_agg(json_build_object('id',id,'data',post)) result FROM posts WHERE section='main';


SELECT json_agg(post::jsonb || jsonb_build_object('id',id)) result FROM posts WHERE section='main';
