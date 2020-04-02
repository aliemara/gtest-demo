#include "gtest/gtest.h"
#include "my_classes.h"

TEST(bank, defaultCtor)
{
	BankAccount b;
	ASSERT_EQ(b.balance, 0);
}

TEST(bank, paramCtor)
{
	BankAccount b(5);
	ASSERT_EQ(b.balance, 51);
}