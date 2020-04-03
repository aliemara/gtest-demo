#include "gtest/gtest.h"
#include "alis_classes.h"

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