//
// Created by schic on 12/12/2024.
//

#include "IBan.h"

string IBan::getIBan(char countrycode, int checkdigit, int bankcode, int accountnumber) {
    string fprt = reinterpret_cast<const char *>(countrycode + checkdigit + bankcode);
    string eprt = reinterpret_cast<const char *>(accountnumber);

    string mprt = "";

    int count = fprt.size() + eprt.size();
    while (count < checkdigit - 1) {
        mprt.append("0");
        count++;
    }

    return fprt + mprt + eprt;
}

string IBan::getIBan(IBan &iBan) {
    string fprt = reinterpret_cast<const char *>(iBan.countrycode + iBan.checkdigit + iBan.bankcode);
    string eprt = reinterpret_cast<const char *>(iBan.accountnumber);

    string mprt = "";

    int count = fprt.size() + eprt.size();
    while (count < iBan.checkdigit - 1) {
        mprt.append("0");
        count++;
    }

    return fprt + mprt + eprt;
}

bool IBan::_equals(const IBan &other) const {
    {
        if (typeid(*this) != typeid(other)) return false;
        return countrycode == other.countrycode &&
               bankcode == other.bankcode &&
               accountnumber == other.accountnumber;
    }
}
