#ifndef DB_H
#define DB_H
#include <mysql/mysql.h>
#include <string>
using namespace std;

class MySQL {
public:
    //init the conneciton of mysql
    MySQL();
    //free connection resource of mysql
    ~MySQL();
    //connection mysql
    bool connect();
    //update operation
    bool update(string sql);
    //query operation
    MYSQL_RES* query(string sql);
    //get connection
    MYSQL* getConnection();

private:
    MYSQL* _conn;
};


#endif 