/**
 * Controller base
 *
 */
#include <map>
#include <vector>
#include <string>
//#include <driver.h>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;
#pragma once

using namespace std;

class TestController : public Controller {

public:

    TestController();

    virtual const char* Action( http_request request ) const {

        return "Successful Transfer";

    }

};
