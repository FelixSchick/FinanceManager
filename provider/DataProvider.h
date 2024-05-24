//
// Created by schic on 24/05/2024.
//

#ifndef FINANCEMANAGER_DATAPROVIDER_H
#define FINANCEMANAGER_DATAPROVIDER_H


#include <vector>
#include "../objects/Expense.h"

class DataProvider {
public:
    string inputFileName = "expenses.txt";

    vector<Expense> loadExpenses() const;
    void saveExpenses(vector<Expense> &expenses) const;
};


#endif //FINANCEMANAGER_DATAPROVIDER_H
