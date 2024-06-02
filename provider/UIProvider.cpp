//
// Created by schic on 24/05/2024.
//

#include "UIProvider.h"
#include "../objects/Transaction.h"
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
        cout << endl;
        switch (choice) {
            case 1:
                transactionProvider.addTransaction(transactions);
                break;
            case 2:
                transactionProvider.viewTransactions(transactions);
                break;
            case 3:
                transactionProvider.viewSummary(transactions);
                break;
            case 4:
                dataProvider.saveExpenses(transactions);
                cout << "Transaction saved successfully!" << endl;
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);
}

void UIProvider::showMainUI() {
    cout << "\nFinance Manager:\n";
    cout << "1. Add Transaction\n";
    cout << "2. View Transactios\n";
    cout << "3. View Summary\n";
    cout << "4. Save Transactios\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}


