#include <iostream>
#include "provider/UIProvider.h"
#include "provider/DataProvider.h"

int main() {
    DataProvider dataProvider;
    ExpenseProvider expenseProvider;
    UIProvider uiProvider(dataProvider, expenseProvider);

    uiProvider.showUI();
    return 0;
}
