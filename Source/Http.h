/**
 * Server setup
 *
 */
#pragma once
#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#pragma comment(lib, "cpprest110_1_1")

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

#include <boost/function.hpp>

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "Controller.h"

using namespace std;

#define TRACE(msg)            wcout << msg
#define TRACE_ACTION(a, k, v) wcout << a << L" (" << k << L", " << v << L")\n"
typedef const char* (*request_callback)(http_request);

//typedef boost::function<void, void> fun_t;

typedef boost::function<void> fun_t;

/* handlers implementation */


class Http {

public:

    Http();

    const char* NOT_FOUND = "{ \"error\": \"method not found\" }";

    const char* host = "http://localhost";

    const char* port = "4200";

    const char* path = "/restdemo";

    map<string, const Controller*> methods;

    void SetMethod( const char* methodName, const Controller * callback );

    void HandleGetRequest( http_request request );

    void Start();

};
