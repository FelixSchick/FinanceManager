//
// Created by schic on 12/12/2024.
//

#ifndef FINANCEMANAGER_USER_H
#define FINANCEMANAGER_USER_H

using namespace std;

#include "IBan.h"
#include "Transaction.h"

enum class PermissionLevel : int { user = 0, advisor = 1, support = 2, auditor = 3, manager = 4, admin = 5 };

class User {

private:
    PermissionLevel permissionLevel; //checks how cool the user is

    int pin[5];
    double balance;

    //account information
    int accountNumber; //upcounting
    IBan iBan;

    //personal information
    char name[32];
    char firstname[64];
    char email[256];

    //check every transaction from and to user to prove the current balance is up-to-date,
    //if not it change the balance to the correct balance
    bool proveBalance();

public:
    User(const PermissionLevel permissionLevel, int accountNumber, IBan iBan , char name, char firstname, char email, int pin)
    : permissionLevel(permissionLevel), accountNumber(accountNumber), iBan(iBan), name(name), firstname(firstname), email(email), pin(pin), balance(0) {}

    bool hasPermission(PermissionLevel _permissionLevel) { return (_permissionLevel <= permissionLevel); }

    bool updateBalance(Transaction transaction);

};


#endif //FINANCEMANAGER_USER_H
