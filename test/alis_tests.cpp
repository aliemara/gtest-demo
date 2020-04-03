// https://youtu.be/16FI1-d2P4E
// https://www.youtube.com/watch?v=x5_UxQ9wrH4&list=PLvWTmpiyQGNYTqDr9_BF1hPCtdCr7VHAZ&index=3
#include "gtest/gtest.h"
#include "alis_classes.h"

////////////////////////////////////
///// 	Simple Tests	 ///////////
////////////////////////////////////

// TEST: general test
// First Param: test name
// Second Param: subtest name
TEST(bank, defaultCtor)
{
	BankAccount b;
	ASSERT_EQ(b.getBalance(), 0);
}

TEST(bank, paramCtor)
{
	BankAccount b(5);
	ASSERT_EQ(b.getBalance(), 5);
}

TEST(bank, deposit)
{
	int start = 3;
	BankAccount b(3);
	b.deposit(start);
	ASSERT_EQ(b.getBalance(), start*2);
}

////////////////////////////////////
// Each test consists of 3 steps: //
// 1. Arrange 					  //
// 2. Act 					  	  //
// 3. Assert 					  //
////////////////////////////////////

TEST(unitTestSteps, AAA)
{
	// 1. arrange
	int value = 5;
	int increment = 8;

	// 2. act
	value = value + increment;

	// 3. assert
	ASSERT_EQ(value, 13);
}

////////////////////////////////////
// Main comparison functions	  //
// Note: each assertion should be //
// in a separate/independent test.//
// This big test is just to demo  //
////////////////////////////////////

TEST(comparisonMethods, demo)
{
	std::string x = "ali";
	// string equal
	ASSERT_STREQ(x.c_str(), "ali");
	
	// string not equal
	ASSERT_STRNE("x", "ali");

	// string case-insensitive comparison
	ASSERT_STRCASEEQ("ALI", "ali");

	// not equal
	ASSERT_NE(1, 2);

	// less than
	ASSERT_LT(1, 2);

	// less than or equal
	ASSERT_LE(2, 2);

	// than or equal
	ASSERT_GT(3, 2);

	// greater than or equal
	ASSERT_GE(2, 2);
}

////////////////////////////////////
///// Fatal vs Non-Fatal Fail //////
///// ASSERT | EXPECT 		  //////
////////////////////////////////////

/*
TEST(fatality, fatal_example)
{
	ASSERT_EQ(1, 2);
	std::cout<<"this line won't be printed. 'Assert' failure is fatal.\n";
}


TEST(fatality, non_fatal_example)
{
	EXPECT_EQ(1, 2);
	std::cout<<"this line will be printed. 'Expect' failure is non-fatal.\n";
}

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