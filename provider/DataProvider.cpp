//
// Created by schic on 24/05/2024.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "DataProvider.h"



vector<Transaction> DataProvider::loadExpenses() {
    vector<Transaction> expenses;
    string line;

    ifstream inFile(inputFileName);
    if (!inFile) return {};

    while (getline(inFile, line)) {
        vector<string> parts = split(line, '^');
        if (parts.size() == 5) {
            string date = parts[0];
            string category = parts[1];
            string description = parts[2];
            string amountStr = parts[3];
            string typeStr = parts[4];

            TransactionType type;

            if (std::equal(typeStr.begin(), typeStr.end(),"1")) {
                type = TransactionType::expense;
            } else type = TransactionType::income;

            double amount = stod(amountStr);

            expenses.emplace_back(date, category, description, amount, type);
        } else {
            cerr << "Invalid line format: " << line << endl;
        }
        parts.clear();
    }

    inFile.close();

    return expenses;
}

void DataProvider::saveExpenses(vector<Transaction> &expenses) const {
    ofstream outFile(inputFileName);

    for (const auto& expense : expenses) {
        outFile << expense.date << "^" << expense.category << "^" << expense.description << "^" << expense.amount << "^" << static_cast<int>(expense.transactionType) <<  endl;
    }

    outFile.close();
}

vector<string> DataProvider::split(const string &str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}