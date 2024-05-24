//
// Created by schic on 24/05/2024.
//

#ifndef FINANCEMANAGER_EXPENSEPROVIDER_H
#define FINANCEMANAGER_EXPENSEPROVIDER_H


#include <vector>
#include "../objects/Expense.h"

class ExpenseProvider {
public:
    Expense addExpense(vector<Expense> &expenses);
    void viewExpenses(vector<Expense> &expenses);
};


#endif //FINANCEMANAGER_EXPENSEPROVIDER_H
