//
// Created by schic on 24/05/2024.
//

#ifndef FINANCEMANAGER_UIPROVIDER_H
#define FINANCEMANAGER_UIPROVIDER_H

#include <vector>
#include "../objects/Expense.h"
#include "DataProvider.h"
#include "ExpenseProvider.h"

using namespace std;

class UIProvider {

private:
    vector<Expense> expenses;
    DataProvider dataProvider;
    ExpenseProvider expenseProvider;

    void showMainUI();

public:
    explicit UIProvider(DataProvider dataProvider, ExpenseProvider expenseProvider) {
        dataProvider = dataProvider;
        expenseProvider = expenseProvider;
        expenses = dataProvider.loadExpenses();
    }

    void showUI();
};


#endif //FINANCEMANAGER_UIPROVIDER_H
