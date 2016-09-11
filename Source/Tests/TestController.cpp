/**
 * Test Controller
 *
 */
#pragma once
#include <map>
#include <vector>
#include <string>
//#include <driver.h>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>

#include "TestController.h"

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

using namespace std;


TestController::TestController() {

    _name = "TEST CONTROLLER";

}

//virtual const char* TestController::Action( http_request request ) {

    //return "Successful Transfer";

//};
