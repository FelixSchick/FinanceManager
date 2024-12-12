//
// Created by schic on 12/12/2024.
//

#ifndef FINANCEMANAGER_USER_H
#define FINANCEMANAGER_USER_H

using namespace std;

#include "IBan.h"

enum class PermissionLevel : int { user = 0, advisor = 1, support = 2, auditor = 3, manager = 4, admin = 5 };

class User {

private:
    PermissionLevel permissionLevel; //checks how cool the user is

    int password[5];


public:
    User(const PermissionLevel permissionLevel, int accountnumber, IBan iBan , char name, char lastname, char email, char password)
    : permissionLevel(permissionLevel), accountnumber(accountnumber), iBan(iBan), name(name), lastname(lastname), email(email), password(password) {}

    bool hasPermission(PermissionLevel _permissionLevel) { return (_permissionLevel <= permissionLevel); }

    //account information
    int accountnumber; //upcounting
    IBan iBan;

    //personal information
    char name[64];
    char lastname[32];
    char email[256];
};


#endif //FINANCEMANAGER_USER_H
