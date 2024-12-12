//
// Created by schic on 24/05/2024.
//

#ifndef FINANCEMANAGER_TRANSACTION_H
#define FINANCEMANAGER_TRANSACTION_H
#include <string>
#include <utility>

using namespace std;

enum class TransactionType : int { income = 0, expense = 1};

class Transaction {
public:

    Transaction(string  date, string  category, string  description, double amount, const TransactionType& transactionType)
            : date(std::move(date)), category(std::move(category)), description(std::move(description)), amount(amount), transactionType(transactionType) {};


    string date;
    string category;
    string description;
    double amount;
    TransactionType transactionType;
};


#endif //FINANCEMANAGER_TRANSACTION_H
