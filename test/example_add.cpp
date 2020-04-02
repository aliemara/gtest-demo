#include "gtest/gtest.h"
#include "example.h"

#include "my_classes.h"

TEST(example, add)
{
    double res;
    res = add_numbers(1.0, 2.0);
    ASSERT_NEAR(res, 3.0, 1.0e-11);
}

TEST(example, simple)
{
    double res;
    res = add_numbers(1.0, 2.0);
    ASSERT_EQ(res, 3.0);
}

TEST(bank, defaultCtor)
{
	BankAccount b;
	ASSERT_EQ(b.balance, 0);
}

TEST(bank, paramCtor)
{
	BankAccount b(5);
	ASSERT_EQ(b.balance, 5);
}