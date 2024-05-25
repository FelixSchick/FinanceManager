//
// Created by schic on 24/05/2024.
//

#include <iostream>
#include <iomanip>
#include <regex>
#include <format>
#include "TransactionProvider.h"
#include "DateProvider.h"



void TransactionProvider::viewTransactions(vector<Transaction> &transactions) {
    cout << left << setw(12) << "Date" << setw(15) << "Category" << setw(25) << "Description" << setw(10) << "Amount" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (const auto& transaction : transactions) {
        cout << left << setw(12) << transaction.date
             << setw(15) << transaction.category
             << setw(25) << transaction.description
             << setw(10) << fixed << getTransactionString(transaction)
             << endl;
    }
}

Transaction TransactionProvider::addTransaction(vector<Transaction> &transactions) {
    Transaction transaction("", "", "", 0, TransactionType::expense);
    regex numberRegex("^[-+]?[0-9]*\\.?[0-9]+$");

    string inputDate;
    bool dateValidation = true;
    do {
        cout << "Enter date (YYYY-MM-DD): ";
        cin >> inputDate;
        dateValidation = DateProvider::isValidDate(inputDate);
    } while (!dateValidation);
    transaction.date = inputDate;


    cout << "Enter category: ";
    cin.ignore();
    getline(cin, transaction.category);

    cout << "Enter description: ";
    getline(cin, transaction.description);


    string inputAmount;
    bool amountValidation = true;
    do {
        cout << "Enter amount: ";
        cin >> inputAmount;
        replace(inputAmount.begin(), inputAmount.end(), ',', '.');
        amountValidation = regex_match(inputAmount, numberRegex);
    } while (!amountValidation);
    transaction.amount = stod(inputAmount);

    string typeInput;
    bool typeValidation = true;
    do {
        cout << "Is it a income(+) or a expense(-):";
        cin >> typeInput;

        if (!(std::equal(typeInput.begin(), typeInput.end(), "+") ||
                std::equal(typeInput.begin(), typeInput.end(), "-")))
            typeValidation = false;
    } while (!typeValidation);
    if (std::equal(typeInput.begin(), typeInput.end(),"+")) {
        transaction.transactionType = TransactionType::income;
    } else
        transaction.transactionType = TransactionType::expense;


    transactions.push_back(transaction);
    return transaction;
}


inline std::string TransactionProvider::getTransactionString(const Transaction& transaction) {
    std::ostringstream oss;
    oss << (transaction.transactionType == TransactionType::expense ? "-" : "+")
        << std::fixed << std::setprecision(2) << transaction.amount;
    return oss.str();
}

void TransactionProvider::viewSummary(vector<Transaction> &transactions) {
    cout << left << setw(12) << "Date" << setw(15) << "Category" << setw(25) << "Description" << setw(10) << "Amount" << endl;
    cout << "-------------------------------------------------------------" << endl;

    double totalIncome = 0;
    double totalExpenses = 0;

    for (const auto& transaction : transactions) {
        cout << left << setw(12) << transaction.date
             << setw(15) << transaction.category
             << setw(25) << transaction.description
             << setw(10) << fixed << getTransactionString(transaction)
             << endl;

        if (transaction.transactionType == TransactionType::income) {
            totalIncome += transaction.amount;
        } else
            totalExpenses += transaction.amount;
    }

    cout << "-------------------------------------------------------------" << endl << endl;
    cout <<
        "Income: " << setprecision(2) << totalIncome << endl <<
        "Expenses: " << setprecision(2) << totalExpenses << endl;
    cout << "_____________________________" << endl;
    cout << "Summary: " << setprecision(2) << totalIncome - totalExpenses << endl;
}
