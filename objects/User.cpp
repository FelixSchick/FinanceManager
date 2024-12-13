//
// Created by schic on 12/12/2024.
//

#include "User.h"

bool User::proveBalance() {
    return false;
}

/*
 * Update the balance via transaction
 * Return: if success (there is only success - Mindset)
 */
bool User::updateBalance(Transaction transaction) {
    if (transaction.senderIban == transaction.receiverIban) return false;

    if (transaction.transactionType == TransactionType::expense) {
        balance -= transaction.amount;
    } else {
        balance += transaction.amount;
    }
    return true;
}

