
#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(const std::string& accountNumber, const std::string& accountHolder, double balance)
    : accountNumber(accountNumber), accountHolder(accountHolder), balance(balance) {}

void BankAccount::Deposit(double amount) {
    balance += amount;
}

void BankAccount::Withdraw(double amount) {
    if (amount > balance) {
        std::cout << "Error. Incussicient funds in the bank account." << std::endl;
    } else {
        balance -= amount;
    }
}

double BankAccount::GetBalance() const {
    return balance;
}

std::string BankAccount::GetAccountHolder() const {
    return accountHolder;
}

std::string BankAccount::GetAccountNumber() const {
    return accountNumber;
}

void BankAccount::PrintAccountInfo() const {
    std::cout << "Account number: " << accountNumber << std::endl;
    std::cout << "Account holder: " << accountHolder << std::endl;
    std::cout << "Balance: " << balance << std::endl;
}

void Bank::AddAccount(const BankAccount& account) {
    accounts.push_back(account);
}

double Bank::GetTotalBalance() const {
    double totalBalance = 0;
    for (const auto& account : accounts) {
        totalBalance += account.GetBalance();
    }
    return totalBalance;
}

void Bank::PrintAllAccounts() const {
    for (const auto& account : accounts) {
        account.PrintAccountInfo();
        std::cout << "--------------------------" << std::endl;
    }
}
