#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>

#include "alis_classes.h"

/*
Mocks are used for testing the APIs or interface of your components.
I created a class called MyComponent that depends on an interface (e.g. Network downloader: NetworkDownloader).

I want to test my component. So, I will create a MockNetworkDownloader that acks like a network downloader without having a real network.

In summary:
- I mock the interface (the extrnal component I am using), not my component. 
- I test my component.
- Mocks are not Fakes nor stubs
*/

class MockDB : public DataBase {
public:
	MOCK_METHOD0(fetchRecord, int());
	MOCK_METHOD1(logout, bool (std::string uername));
	MOCK_METHOD2(login, bool (std::string uername, std::string password));
};

TEST(MyDBTest, loginTestSuccess) {
	MockDB mockdb;
	MyComponent component(mockdb);

	/// EXPECT_CALL Tells the mock class how to behave.
	// Expect someone to call your login method with those 2 args
	EXPECT_CALL(mockdb,login("ali", "alispassword"))		
	// Call will happen ONCE
	.Times(1)
	// When it happens, return true
	.WillOnce(testing::Return(true));

	// Inside init, db will be called once, with those 2 args
	// and it will mock real db by returning true, so init 
	// will succeed and return 1
	int retVal = component.init("ali", "alispassword");

	EXPECT_EQ(retVal, 1);
}

/*
	Tests failure scenario.
	Read the comments for new changes and things to learn.
*/
TEST(MyDBTest, loginTestFailure) {
	MockDB mockdb;
	MyComponent component(mockdb);

	// _ means you don't care what value you get.
	EXPECT_CALL(mockdb,login(testing::_, testing::_))		
	// AtLeast twice
	.Times(testing::AtLeast(2))
	// WillRepeatedly is better than WillOnce.
	// Means you always keep returning false
	.WillRepeatedly(testing::Return(false));

	// Inside init, db will be called once, with those 2 args
	// and it will mock real db by returning true, so init 
	// will succeed and return 1
	int retVal = component.init("ali", "alispassword");

	EXPECT_EQ(retVal, -1);
}

/*
	Fails once then succeeds because success is the default behavior.
	Read the comments for new changes and things to learn.
*/
TEST(MyDBTest, loginTestFailureThenSuccess) {
	MockDB mockdb;
	MyComponent component(mockdb);

	// If no return is specified, return false
	ON_CALL(mockdb, login(testing::_, testing::_)).WillByDefault(testing::Return(true));

	// _ means you don't care what value you get.
	EXPECT_CALL(mockdb,login(testing::_, testing::_))		
	// AtLeast twice
	.Times(testing::AtLeast(2))
	// WillRepeatedly is better than WillOnce.
	// Means you always keep returning false
	.WillOnce(testing::Return(false));

	// Inside init, db will be called once, with those 2 args
	// and it will mock real db by returning true, so init 
	// will succeed and return 1
	int retVal = component.init("ali", "alispassword");

	EXPECT_EQ(retVal, -1);
}


