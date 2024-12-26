
#include "BankAccount.h"
#include <gtest/gtest.h>

// Test fixture for BankAccount
class BankAccountTest : public ::testing::Test {
protected:
    BankAccount account{"123456", "John Doe", 1000.0};
};

TEST_F(BankAccountTest, InitialBalanceTest) {
    EXPECT_EQ(account.GetBalance(), 1000.0);
}

TEST_F(BankAccountTest, DepositTest) {
    account.Deposit(500.0);
    EXPECT_EQ(account.GetBalance(), 1500.0);
}

TEST_F(BankAccountTest, WithdrawSufficientFundsTest) {
    account.Withdraw(200.0);
    EXPECT_EQ(account.GetBalance(), 800.0);
}

TEST_F(BankAccountTest, WithdrawInsufficientFundsTest) {
    account.Withdraw(2000.0);
    EXPECT_EQ(account.GetBalance(), 1000.0);
}

TEST_F(BankAccountTest, AccountHolderInfoTest) {
    EXPECT_EQ(account.GetAccountHolder(), "John Doe");
    EXPECT_EQ(account.GetAccountNumber(), "123456");
}

// Test fixture for Bank
class BankTest : public ::testing::Test {
protected:
    Bank bank;
    BankAccount account1{"123456", "John Doe", 1000.0};
    BankAccount account2{"789012", "Jane Smith", 2000.0};

    void SetUp() override {
        bank.AddAccount(account1);
        bank.AddAccount(account2);
    }
};

TEST_F(BankTest, AddAccountTest) {
    BankAccount account3{"345678", "Alice Brown", 1500.0};
    bank.AddAccount(account3);
    EXPECT_EQ(bank.GetTotalBalance(), 4500.0);
}

TEST_F(BankTest, GetTotalBalanceTest) {
    EXPECT_EQ(bank.GetTotalBalance(), 3000.0);
}

TEST_F(BankTest, PrintAllAccountsTest) {
    ASSERT_NO_THROW(bank.PrintAllAccounts());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
