#include "gtest/gtest.h"
#include "my_classes.h"

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