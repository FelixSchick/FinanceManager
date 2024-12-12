//
// Created by schic on 12/12/2024.
//

#ifndef FINANCEMANAGER_IBAN_H
#define FINANCEMANAGER_IBAN_H
#include <string>
#include <utility>

using namespace std;

class IBan {
public:
    IBan(char countrycode, int checkdigit, int bankcode, int accountnumber)
    : countrycode(countrycode), checkdigit(checkdigit), bankcode(bankcode), accountnumber(accountnumber) {}

    string getIBan(char countrycode, int checkdigit, int bankcode, int accountnumber);
    string getIBan(IBan& iBan);

    char countrycode;
    int checkdigit;
    int bankcode;
    int accountnumber;
};



#endif //FINANCEMANAGER_IBAN_H
