#include <stdlib.h>
#include <iostream>

#include <mysql.h>
#include <mysql_connection.h>
//#include <driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "DB.cpp"
//#include <cpprest/filestream.h>

using namespace std;
using namespace sql;

int main(void)
{
    try {

        DB* dbh = new DB();

        dbh->GetAllStocks();

    } catch (sql::SQLException &e) {
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    cout << endl;

    return EXIT_SUCCESS;

}
