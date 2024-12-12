#include <iostream>
#include "provider/UIProvider.h"
#include "provider/DataProvider.h"

void printLogo();

int main() {
    DataProvider dataProvider;
    TransactionProvider expenseProvider;
    UIProvider uiProvider(dataProvider, expenseProvider);

    printLogo();

    uiProvider.showUI();
    return 0;
}

void printLogo() {
    std::cout << R"(
$$$$$$$$\        $$\ $$\                  $$$$$$\            $$\       $$\           $$\
$$  _____|       $$ |\__|                $$  __$$\           $$ |      \__|          $$ |
$$ |    $$$$$$\  $$ |$$\ $$\   $$\       $$ /  \__| $$$$$$$\ $$$$$$$\  $$\  $$$$$$$\ $$ |  $$\
$$$$$\ $$  __$$\ $$ |$$ |\$$\ $$  |      \$$$$$$\  $$  _____|$$  __$$\ $$ |$$  _____|$$ | $$  |
$$  __|$$$$$$$$ |$$ |$$ | \$$$$  /        \____$$\ $$ /      $$ |  $$ |$$ |$$ /      $$$$$$  /
$$ |   $$   ____|$$ |$$ | $$  $$<        $$\   $$ |$$ |      $$ |  $$ |$$ |$$ |      $$  _$$<
$$ |   \$$$$$$$\ $$ |$$ |$$  /\$$\       \$$$$$$  |\$$$$$$$\ $$ |  $$ |$$ |\$$$$$$$\ $$ | \$$\
\__|    \_______|\__|\__|\__/  \__|       \______/  \_______|\__|  \__|\__| \_______|\__|  \__|


    )" << std::endl;
}
