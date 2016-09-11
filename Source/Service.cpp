/**
 * Main service actions
 *
 */
#include "Request.cpp"

class Service {

public:

    Service();


    //Will return of stock

    float Quote(char username, char password, char code);


    //Will return amount sold

    float Sell(char username, char password, float quantity);


    //Buy for a user

    float Buy(char username, char password, int quantity);


    //Register a new trader

    bool RegisterTrader(char username, char password);


    //List transactions

    bool Transactions(char username, char password);


    //Portfolio list

    bool PortfolioList(char username, char password);


private:

    Request request();

    bool CheckLogin();


}
