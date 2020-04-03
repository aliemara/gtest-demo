#pragma once

class BankAccount {
public:
	BankAccount() : balance(0) {}
	BankAccount(int balance) : balance(balance) {}

	void deposit(int d) {
		balance += d;
	}

	const int& getBalance() { return balance; }

private: 
	int balance;
};