/**
 * DB helper
 *
 */
#include <map>
#include <vector>
#include <string>
#include <mysql.h>
#include <mysql_connection.h>
//#include <driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#pragma once

using namespace std;
using namespace sql;
class DB {

public:

    DB();

    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;

    bool CreateTrader(char username, char password);

    bool CreateBuy(char username, char password, int quantity);

    string* GetAllStocks( void );

    bool GetTransactions(char username, char password);

    bool getPortfolio(char username, char password);

};
