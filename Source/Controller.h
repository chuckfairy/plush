/**
 * Controller base
 *
 */
#pragma once
#include <map>
#include <vector>
#include <string>
//#include <driver.h>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

using namespace std;

class Controller {

public:

    Controller() {};

    ~Controller() {};

    operator bool() const { return false; }

    const char* _name = "BAD";

    virtual const char* Action( http_request request ) const { return "BAD"; }

};
