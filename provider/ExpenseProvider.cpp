//
// Created by schic on 24/05/2024.
//

#include <iostream>
#include <iomanip>
#include "ExpenseProvider.h"



void ExpenseProvider::viewExpenses(vector<Expense> &expenses) {
    cout << left << setw(12) << "Date" << setw(15) << "Category" << setw(25) << "Description" << setw(10) << "Amount" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (const auto& expense : expenses) {
        cout << left << setw(12) << expense.date
             << setw(15) << expense.category
             << setw(25) << expense.description
             << setw(10) << fixed << setprecision(2) << expense.amount
             << endl;
    }
}

Expense ExpenseProvider::addExpense(vector<Expense> &expenses) {
    Expense expense((string &) "", (string &)"", (string &)"", 0);

    cout << "Enter date (YYYY-MM-DD): ";
    cin >> expense.date;
    cout << "Enter category: ";
    cin.ignore();
    getline(cin, expense.category);
    cout << "Enter description: ";
    getline(cin, expense.description);
    cout << "Enter amount: ";
    cin >> expense.amount;

    expenses.push_back(expense);
    return expense;
}
