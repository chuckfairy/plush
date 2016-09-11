/**
 * JSON api
 *
 */
#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#pragma comment(lib, "cpprest110_1_1")

#include <iostream>

#include <boost/bind.hpp>

#include "Http.h"
#include "DB.h"

class API {

public:

    API(){};

    DB *dbh;

    void setMethods( Http * server );

    const char * getAllStocks( http_request request );

};

const char * get_it( http_request request ) {

    TRACE(L"GET IT");

    return "{ \"test\": \"TEST\" }";

};

const char * API::getAllStocks( http_request request ) {



};

void API::setMethods( Http * server ) {

    //request_callback callback;
    //callback = getAllStocks;

    //boost::function<void (int)> f2( boost::bind( &API::setMethods, this, _1 ) );

    server->SetMethod( "/get_all_stocks", get_it );
    //server->SetMethod( "/get_all_stocks2",  boost::bind(&API::getAllStocks));

};
