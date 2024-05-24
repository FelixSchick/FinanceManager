//
// Created by schic on 24/05/2024.
//

#include "Expense.h"

Expense::Expense(string &date, string &category, string &description, double inamount) {
    amount = inamount;
    date = date;
    category = category;
    description = description;
}
