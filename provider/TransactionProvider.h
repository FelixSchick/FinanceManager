//
// Created by schic on 24/05/2024.
//

#ifndef FINANCEMANAGER_TRANSACTIONPROVIDER_H
#define FINANCEMANAGER_TRANSACTIONPROVIDER_H


#include <vector>
#include "../objects/Transaction.h"

class TransactionProvider {
private:
    std::string getTransactionString(const Transaction& transaction);
public:
    Transaction addTransaction(vector<Transaction> &transactions);
    void viewTransactions(vector<Transaction> &transactions);
    void viewSummary(vector<Transaction> &transactions);
};


#endif //FINANCEMANAGER_TRANSACTIONPROVIDER_H
