//
// Created by schic on 24/05/2024.
//

#ifndef FINANCEMANAGER_TRANSACTION_H
#define FINANCEMANAGER_TRANSACTION_H
#include <string>

using namespace std;

enum class TransactionType : int { income = 0, expense = 1};

class Transaction {
public:

    Transaction(const string& date, const string& category, const string& description, double amount, const TransactionType& transactionType)
            : date(date), category(category), description(description), amount(amount), transactionType(transactionType) {};

    string date;
    string category;
    string description;
    double amount;
    TransactionType transactionType;
};


#endif //FINANCEMANAGER_TRANSACTION_H
