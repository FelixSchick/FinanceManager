//
// Created by schic on 24/05/2024.
//

#include "DateProvider.h"
#include <regex>

bool DateProvider::isValidDate(const string &dateStr) {
    regex dateRegex(R"(^\d{4}-\d{2}-\d{2}$)");

    if (!regex_match(dateStr, dateRegex)) {
        return false;
    }

    int year = stoi(dateStr.substr(0, 4));
    int month = stoi(dateStr.substr(5, 2));
    int day = stoi(dateStr.substr(8, 2));

    if (month < 1 || month > 12) {
        return false;
    }

    if (day < 1 || day > 31) {
        return false;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }

    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29) {
                return false;
            }
        } else {
            if (day > 28) {
                return false;
            }
        }
    }

    return true;
}
