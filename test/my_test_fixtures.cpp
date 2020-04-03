#include "gtest/gtest.h"
#include "alis_classes.h"

struct BankAccountTest : testing::Test {
	BankAccountTest() {
		account = new BankAccount;
	}

	~BankAccountTest() {
		delete account;
	}

	BankAccount* account;
};

TEST_F(BankAccountTest, ctor) {
	ASSERT_EQ(account->getBalance(), 0);
}

TEST_F(BankAccountTest, deposit) {
	account->deposit(100);
	ASSERT_EQ(account->getBalance(), 100);
}