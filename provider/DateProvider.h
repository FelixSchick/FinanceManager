//
// Created by schic on 24/05/2024.
//

#ifndef FINANCEMANAGER_DATEPROVIDER_H
#define FINANCEMANAGER_DATEPROVIDER_H

#include <string>
#include <regex>

using namespace std;

class DateProvider {

public:
    static bool isValidDate(const string& dateStr);
};


#endif //FINANCEMANAGER_DATEPROVIDER_H
