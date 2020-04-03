// https://youtu.be/16FI1-d2P4E

#include "gtest/gtest.h"
#include "alis_classes.h"

////////////////////////////////////
///// 	Test Fixtures	 ///////////
////////////////////////////////////


struct BankAccountTest : testing::Test {
	BankAccountTest(int amount) : account(new BankAccount(amount)) {}
	BankAccountTest() : BankAccountTest(0) {}

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

////////////////////////////////////
///// Parameterized tests //////////
////////////////////////////////////

struct account_state
{
	int initial_balance;
	int withdraw_amount;
	int final_balance;
	bool success;
};

struct WithdrawAccountTest : BankAccountTest,
							// to pass an account_state as a parameter
							 testing::WithParamInterface<account_state>
{
	WithdrawAccountTest() : BankAccountTest(GetParam().initial_balance) {}
};

TEST_P(WithdrawAccountTest, FinalBalance)
{
	account_state as = GetParam();
	bool success = account->withdraw(as.withdraw_amount);
	EXPECT_EQ(as.success, success);
	EXPECT_EQ(as.final_balance, account->getBalance());
}

/// Run the WithdrawAccountTest_FinalBalance with 3 use cases
INSTANTIATE_TEST_CASE_P(Default,
						WithdrawAccountTest,
						testing::Values(
							account_state{100, 50, 50, true},
							// init: 100. Withdraw 25. Remain: 75. Success = true
							account_state{100, 25, 75, true},
							account_state{100, 200, 100, false}
						));