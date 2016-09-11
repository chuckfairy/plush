/**
 * Server setup
 *
 */
#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#pragma comment(lib, "cpprest110_1_1")

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

#include "Http.h"

#include "Controller.h"

using namespace std;

Http::Http() {


}

void Http::HandleGetRequest( http_request request ) {

    TRACE(L"\nhandle GET\n");

    string path = request.relative_uri().to_string();

    const char* cpath = path.c_str();

    TRACE( cpath );

    if( methods.count( cpath) ) {//{methods[ cpath ] ) {

        TRACE(L"\nhandle Method found\n");

        auto con = methods[ cpath ];

        const char* json;

        TRACE( con->_name );

        json = methods[ cpath ]->Action( request );

        request.reply( status_codes::OK, json );

    } else {

        TRACE(L"\nNO handle Method found\n");

        request.reply(status_codes::OK, NOT_FOUND);

    }

}

void Http::Start() {

    std::ostringstream formatter;

    formatter << host << ':' << port << path;

    string url = formatter.str();

    http_listener listener( url );

    //void h = std::bind(&Http::HandleGetRequest, this, std::placeholders::_1);

    listener.support(methods::GET, std::bind(&Http::HandleGetRequest, this, std::placeholders::_1));

    //listener.support(methods::POST, handle_post);
    //listener.support(methods::PUT, handle_put);
    //listener.support(methods::DEL, handle_del);

    try
    {
        listener
            .open()
            .then([&listener](){TRACE(L"\nstarting to listen\n");})
            .wait();

        while (true);
    }
    catch (exception const & e)
    {
        wcout << e.what() << endl;
    }

}

void Http::SetMethod( const char* methodName, const Controller * con ) {

    methods[ methodName ] = con;

}
