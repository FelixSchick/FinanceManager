//
// Created by schic on 24/05/2024.
//

#include <fstream>
#include <iostream>
#include "DataProvider.h"



vector<Expense> DataProvider::loadExpenses() const {
    vector<Expense> expenses;

    ifstream inFile(inputFileName);
    if (!inFile){
        cout << "Error while loading the expenses from file" << endl;
        return {};
    }

    string date, category, description, amountStr;
    while (getline(inFile, date, ',') &&
           getline(inFile, category, ',') &&
           getline(inFile, description, ',') &&
           getline(inFile, amountStr)) {
        Expense expense(date, category, description, stod(amountStr));
        expenses.push_back(expense);
    }

    inFile.close();

    return expenses;
}

void DataProvider::saveExpenses(vector<Expense> &expenses) const {
    ofstream outFile(inputFileName);

    for (const auto& expense : expenses) {
        outFile << expense.date << "," << expense.category << "," << expense.description << "," << expense.amount << endl;
    }

    outFile.close();
}
