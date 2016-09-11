/**
 * DB helper
 *
 */
#include <map>
#include <vector>
#include <string>
#include <mysql.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "DB.h"

using namespace std;
using namespace sql;

DB::DB() {

    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "");

    con->setSchema("database");

}


string* DB::GetAllStocks( void ) {

    stmt = con->createStatement();

    res = stmt->executeQuery("SELECT * FROM stock");

    cout << "list of data:" << endl;

    int i = 0;

    string* rows = new string[ res->rowsCount() ];

    while(res->next()) {

        rows[i] = res->getString(1);

        i++;

        cout << "stock: " << res->getString(1) << endl;
        cout << "lastsaleprice: " << res->getDouble(2) << endl;

    }

    return rows;

}
