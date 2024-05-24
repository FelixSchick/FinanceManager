//
// Created by schic on 24/05/2024.
//

#ifndef FINANCEMANAGER_EXPENSE_H
#define FINANCEMANAGER_EXPENSE_H
#include <string>

using namespace std;
class Expense {
public:
    Expense(const string& date, const string& category, const string& description, double amount)
            : date(date), category(category), description(description), amount(amount) {};

    string date;
    string category;
    string description;
    double amount;
};


#endif //FINANCEMANAGER_EXPENSE_H
