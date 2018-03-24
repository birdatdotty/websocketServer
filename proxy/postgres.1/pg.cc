#include "pg.h"

// #include <iostream>
using namespace std;

Cpg::Cpg (std::string base, std::string user, std::string password,
  std::string host, int port):
  dbName(base),
  login(user),
  password(password),
  host(host),
  port(port),
  status(false)
{
  // cout << "dbName: " << this->dbName << endl;
  // cout << "login: " << this->login << endl;
  // cout << "password: " << this->password << endl;
  // cout << "host: " << this->host << endl;
  // cout << "port: " << this->port << endl;
}

void Cpg::open () {
  string connStr = "dbname = '" + dbName +
                   "' user = '" + login +
                   "' password = '" + password +
                   "' hostaddr = '" + host +
                   "' port = " + to_string(port);
  try {
    conn = new pqxx::connection(connStr);
    if (conn->is_open()) {
      //  cout << "Opened database successfully: " << conn->dbname() << endl;
       status = true;
    } else {
      //  cout << "Can't open database" << endl;
    }
  } catch (const std::exception &e) {
    status = false;
    //  cerr << e.what() << std::endl;
  }
}

void Cpg::exec (std::string sql) {
  W = new pqxx::work(*conn);
  try {
    W->exec( sql );
    W->commit();
  } catch (const std::exception &e) {
    // cerr << e.what() << std::endl;
  }
}


void Cpg::createTable() {
  string sql;
  sql = "CREATE TABLE IF NOT EXISTS posts ("
         "id SERIAL PRIMARY KEY ,"
         "title VARCHAR(50),"
         "section VARCHAR(50),"
         "post JSONB"
        ");";
  exec (sql);
  sql = "CREATE TABLE IF NOT EXISTS projects ("
         "id SERIAL PRIMARY KEY ,"
         "section VARCHAR(50),"
         "CONSTRAINT production UNIQUE(section)"
        ");";
  exec (sql);
}

void    Cpg::insertPost(std::string section, std::string title, std::string post, std::string status ) {
// void Cpg::insertPost(std::string section,                      std::string title,                                std::string post) {
  string sql = "INSERT INTO posts(section,title,post)"
        "VALUES ('" +section + "','" + title + "',"
        "'" + post + "'::jsonb || jsonb_build_object('id',currval('posts_id_seq')) "
        " || jsonb_build_object('title','" + title + "') "
        " || jsonb_build_object('status','" + status + "') "
        " );";
  exec (sql);
}


std::vector<string> Cpg::getProjects() {
  std::vector<string> projects;
  string project;
  string sql = "SELECT * FROM projects;";
  pqxx::nontransaction N(*conn);
  pqxx::result R( N.exec( sql ));
  for (pqxx::result::const_iterator c = R.begin(); c != R.end(); ++c) {
    project = c[1].as<string>();
    // cout << "ID = " << project << endl;
    projects.push_back (project);
  }
  // for (auto i: projects)
    // std::cout << "\t> " << i << '\n';

  return projects;
}


void Cpg::insertProject(std::string section) {
  string sql = "INSERT INTO projects(section)"
        "VALUES ('" +section + "');";
  exec (sql);
}

void Cpg::updatePost(int id, std::string post) {
  string sql = "UPDATE posts SET post = '" + post + "'::jsonb || jsonb_build_object('id',"+to_string(id)+") WHERE id = "+to_string(id)+";";
  // string sql = "INSERT INTO posts(section,title,post)"
  //       "VALUES ('" +section + "','" + title + "',"
  //       "'" + post + "'::jsonb|| jsonb_build_object('id',currval('posts_id_seq')));";
  exec (sql);
}

// DELETE FROM POSTS WHERE id=6;
void Cpg::deletePost(int id) {
  string sql = "DELETE FROM POSTS WHERE id="+to_string(id);
  exec (sql);
}

std::string Cpg::getPostsFromSection(std::string section) {
  // SELECT json_agg(post::jsonb || jsonb_build_object('id',id)) result FROM posts WHERE section='main';
  string sql = "SELECT json_agg(post) result FROM posts WHERE section='" + section + "';";
  // string sql = "SELECT json_agg(post) result FROM posts WHERE section='" + section + "';";
  // cout << "getSQL: " << sql << endl;
  pqxx::nontransaction N(*conn);
  pqxx::result R( N.exec( sql ));
  pqxx::result::const_iterator c = R.begin();
  // cout << ">> " << c[0].size() << endl;
  if (c[0].size() > 0)
    return c[0].as<string>();
  else
    return "[]";
}

Cpg::~Cpg () {
  conn->disconnect ();
  delete conn;
  // cout << "delete conn" << endl;
}
