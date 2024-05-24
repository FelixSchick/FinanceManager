//
// Created by schic on 24/05/2024.
//

#include <iostream>
#include <iomanip>
#include <regex>
#include "ExpenseProvider.h"
#include "DateProvider.h"



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
    Expense expense("", "", "", 0);
    regex numberRegex("^[-+]?[0-9]*\\.?[0-9]+$");

    string inputDate;
    bool dateValidation = true;
    do {
        cout << "Enter date (YYYY-MM-DD): ";
        cin >> inputDate;
        dateValidation = DateProvider::isValidDate(inputDate);
    } while (!dateValidation);
    expense.date = inputDate;


    cout << "Enter category: ";
    cin.ignore();
    getline(cin, expense.category);

    cout << "Enter description: ";
    getline(cin, expense.description);


    string inputAmount;
    bool amountValidation = true;
    do {
        cout << "Enter amount: ";
        cin >> inputAmount;
        replace(inputAmount.begin(), inputAmount.end(), ',', '.');
        amountValidation = regex_match(inputAmount, numberRegex);
    } while (!amountValidation);
    expense.amount = stod(inputAmount);

    expenses.push_back(expense);
    return expense;
}
