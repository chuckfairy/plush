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
//#include "API.cpp"
#include "Http.cpp"
#include "Tests/TestController.cpp"

using namespace std;
using namespace sql;

int main(void)
{
    try {

        DB* dbh = new DB();

        dbh->GetAllStocks();

        Http* server = new Http();

        TestController* tester = new TestController();

        server->SetMethod( "/test", tester );

        //API* api = new API();

        //api->setMethods( server );

        server->Start();

    } catch (sql::SQLException &e) {

        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;

    }

    cout << endl;

    return EXIT_SUCCESS;

}
