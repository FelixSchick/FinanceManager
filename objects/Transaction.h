//
// Created by schic on 24/05/2024.
//

#ifndef FINANCEMANAGER_TRANSACTION_H
#define FINANCEMANAGER_TRANSACTION_H
#include <string>
#include <utility>
#include "IBan.h"

using namespace std;

enum class TransactionType : int { income = 0, expense = 1};

class Transaction {

private:
    IBan senderIban;
    IBan receiverIban;
    string date;
    string category;
    string description;
    double amount;
    TransactionType transactionType;

public:
    Transaction(IBan senderIban, IBan receiverIban, string  date, string  category, string  description, double amount, const TransactionType& transactionType)
            :
            senderIban(senderIban),
            receiverIban(receiverIban),
            date(std::move(date)),
            category(std::move(category)),
            description(std::move(description)),
            amount(amount),
            transactionType(transactionType)
            {};

    const IBan &getSenderIban() const {
        return senderIban;
    }

    void setSenderIban(const IBan &senderIban) {
        Transaction::senderIban = senderIban;
    }

    const IBan &getReceiverIban() const {
        return receiverIban;
    }

    void setReceiverIban(const IBan &receiverIban) {
        Transaction::receiverIban = receiverIban;
    }

    const string &getDate() const {
        return date;
    }

    void setDate(const string &date) {
        Transaction::date = date;
    }

    const string &getCategory() const {
        return category;
    }

    void setCategory(const string &category) {
        Transaction::category = category;
    }

    const string &getDescription() const {
        return description;
    }

    void setDescription(const string &description) {
        Transaction::description = description;
    }

    double getAmount() const {
        return amount;
    }

    void setAmount(double amount) {
        Transaction::amount = amount;
    }

    TransactionType getTransactionType() const {
        return transactionType;
    }

    void setTransactionType(TransactionType transactionType) {
        Transaction::transactionType = transactionType;
    }

};


#endif //FINANCEMANAGER_TRANSACTION_H
