#include "BankAccount.h"
#include <iostream>

int main() {
    BankAccount account1("123456", "Joe Baiden", 1000.0);
    BankAccount account2("789012", "Donald Trump", 5000.0);

    Bank bank;
    bank.AddAccount(account1);
    bank.AddAccount(account2);

    account1.Deposit(200.0);
    account2.Withdraw(1000.0);

    std::cout << "Info about all accounts:" << std::endl;
    bank.PrintAllAccounts();

    std::cout << "Total balance: " << bank.GetTotalBalance() << std::endl;

    return EXIT_SUCCESS;
}
