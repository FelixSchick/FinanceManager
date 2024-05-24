//
// Created by schic on 24/05/2024.
//

#include "UIProvider.h"
#include "../objects/Expense.h"
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;


void UIProvider::showUI() {
    int choice;
    do {
        showMainUI();
        cin >> choice;

        switch (choice) {
            case 1:
                expenseProvider.addExpense(expenses);
                break;
            case 2:
                expenseProvider.viewExpenses(expenses);
                break;
            case 3:
                dataProvider.saveExpenses(expenses);
                cout << "Expenses saved successfully!" << endl;
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);
}

void UIProvider::showMainUI() {
    cout << "\nFinance Manager:\n";
    cout << "1. Add Expense\n";
    cout << "2. View Expenses\n";
    cout << "3. Save Expenses\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}


