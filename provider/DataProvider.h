//
// Created by schic on 24/05/2024.
//

#ifndef FINANCEMANAGER_DATAPROVIDER_H
#define FINANCEMANAGER_DATAPROVIDER_H


#include <vector>
#include "../objects/Expense.h"

class DataProvider {
private:
    vector<string> split(const string& str, char delimiter);

public:
    string inputFileName = "expenses.txt";

    vector<Expense> loadExpenses();
    void saveExpenses(vector<Expense> &expenses) const;
};


#endif //FINANCEMANAGER_DATAPROVIDER_H
