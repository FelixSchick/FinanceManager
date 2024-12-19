//
// Created by schic on 12/12/2024.
//

#include "User.h"

bool User::proveBalance() {
    return false;
}

/*
 * Update the balance via transaction
 * Return: if success
 */
bool User::updateBalance(const Transaction& transaction) {
    //TODO: might be useless soon
    if (transaction.getSenderIban() == transaction.getReceiverIban()
        && (transaction.getSenderIban() == iBan || transaction.getSenderIban() == iBan)) return false;

    if (transaction.getReceiverIban() == iBan) {
        balance += transaction.getAmount();
    } else {
        balance -= transaction.getAmount();
    }


    return true;
}

