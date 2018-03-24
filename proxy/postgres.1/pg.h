#ifndef _PG_H_
#define _PG_H_

#include <string>
#include <pqxx/pqxx>

class Cpg {
  private:
    std::string dbName;
    std::string login;
    std::string password;
    std::string host;
    int port;
    bool status;

    pqxx::connection* conn;
    pqxx::work* W;

    void exec (std::string sql);

  public:
    Cpg (std::string base, std::string user, std::string password,
      std::string host, int port);
    void open();
    void createTable();
    void insertProject(std::string section);
    std::vector<std::string> getProjects();
    void insertPost(std::string section, // std::string section,
      std::string title, //sectionName std::string title,
      std::string post,
      std::string status = "new");
    void updatePost(int id, std::string post);
    void deletePost(int id);
    std::string getPostsFromSection(std::string section);
    ~Cpg();
};

#endif
