#pragma once
#include <string>
#include <iostream>

class BankAccount {
public:
	BankAccount() : balance(0) {}
	BankAccount(int balance) : balance(balance) {}

	void deposit(int d) {
		balance += d;
	}

	bool withdraw(int amount) {
		if (balance >= amount) {
			balance -= amount;
			return true;
		}
		
		return false;
	}

	const int& getBalance() { return balance; }

private: 
	int balance;
};


// ----------------------------------------------------------------

// DataBase is an external library that talks to a big database/network.
// Imagine that I only have its interface, and no implementation details. 
class DataBase {
public:

	// returns true on success
	virtual bool login(std::string username, std::string password);

	// returns true on success
	virtual bool logout(std::string username);

	// returns -1 on failure
	virtual int fetchRecord();
};

// ----------------------------------------------------------------

class MyComponent {
	DataBase& db;
	bool failedOnce = false;

public:
	MyComponent(DataBase& _db) : db(_db) {}

	int init(std::string username, std::string password) {
		if (db.login(username, password)) {
			std::cout << "DB Success\n";
			return 1;
		} else {	// failure
			if (failedOnce) {
				std::cout << "DB Failure 2nd time. Won't retry\n";
			} else {
				// code to fix the issue before re-trying
				std::cout << "DB Failure 1st time. Will retry\n";
				failedOnce = true;
				init(username, password);
			}
			return -1;
		}
	}
};
