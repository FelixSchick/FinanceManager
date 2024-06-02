//
// Created by schic on 24/05/2024.
//

#ifndef FINANCEMANAGER_UIPROVIDER_H
#define FINANCEMANAGER_UIPROVIDER_H

#include <vector>
#include "../objects/Transaction.h"
#include "DataProvider.h"
#include "TransactionProvider.h"

using namespace std;

class UIProvider {

private:
    vector<Transaction> transactions;
    DataProvider dataProvider;
    TransactionProvider transactionProvider;

    static void showMainUI();

public:
    explicit UIProvider(DataProvider dataProvider, TransactionProvider transactionProvider) {
        dataProvider = dataProvider;
        transactionProvider = transactionProvider;
        transactions = dataProvider.loadExpenses();
    }

    void showUI();
};


#endif //FINANCEMANAGER_UIPROVIDER_H
