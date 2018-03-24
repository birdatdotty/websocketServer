#include "boost/filesystem.hpp"
#include <jsoncpp/json/json.h>

using namespace std;
using namespace boost::filesystem;

int list_file(Json::Value& dir, std::string selDir)
{
    Json::Value dir2 = Json::Value(Json::arrayValue);
    path p (selDir);
    directory_iterator end_itr;

    for (directory_iterator itr(p); itr != end_itr; ++itr)
    {
        if (is_regular_file(itr->path())) {
            string current_file = itr->path().string();
            Json::Value file;
            file["url"] = "/" + itr->path().parent_path().parent_path().leaf().string() +
                          "/" + itr->path().parent_path().leaf().string() +
                          "/" + itr->path().leaf().string();
            file["title"] = itr->path().leaf().string();
            dir2.append (file);
        }
    }
    dir[p.leaf().string()] = dir2;
}


Json::Value list_dir(std::string selDir)
{
    // list all files in current directory.
    //You could put any file path in here, e.g. "/home/me/mwah" to list that directory
    path p (selDir);
    Json::Value dir = Json::objectValue;

    directory_iterator end_itr;

    // cycle through the directory
    for (directory_iterator itr(p); itr != end_itr; ++itr)
    {
        if (is_directory(itr->path())) {
            // assign current file name to current_file and echo it out to the console.
            string current_file = itr->path().string();
            list_file(dir, current_file);
            dir["listIMG"].append(itr->path().leaf().string());
        }
    }
    return dir;
}
