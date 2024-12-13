//
// Created by schic on 12/12/2024.
//

#ifndef FINANCEMANAGER_IBAN_H
#define FINANCEMANAGER_IBAN_H
#include <string>
#include <utility>
#include <typeinfo>
#include <typeindex>

using namespace std;

class IBan {

private:
    char countrycode;
    int checkdigit;
    int bankcode;
    int accountnumber;

protected:
    virtual bool _equals(IBan const & other) const;

public:
    IBan(char countrycode, int checkdigit, int bankcode, int accountnumber)
    : countrycode(countrycode), checkdigit(checkdigit), bankcode(bankcode), accountnumber(accountnumber) {}

    string getIBan(char countrycode, int checkdigit, int bankcode, int accountnumber);
    string getIBan(IBan& iBan);



    bool operator==(IBan const & other) const { return this->_equals(other); }

    bool operator!=(IBan const & other) const { return !(*this == other); }

};

#endif //FINANCEMANAGER_IBAN_H
