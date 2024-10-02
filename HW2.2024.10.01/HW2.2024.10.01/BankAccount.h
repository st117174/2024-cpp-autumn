#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <vector>

class BankAccount {
private:
    std::string accountNumber;
    double balance;
    std::string accountHolder;

public:    BankAccount(const std::string& accountNumber, const std::string& accountHolder, double balance);

    void Deposit(double amount);
    void Withdraw(double amount);
    double GetBalance() const;
    std::string GetAccountHolder() const;
    std::string GetAccountNumber() const;
    void PrintAccountInfo() const;
};

class Bank {
private:
    std::vector<BankAccount> accounts;

public:
    void AddAccount(const BankAccount& account);
    double GetTotalBalance() const;
    void PrintAllAccounts() const;
};

#endif
