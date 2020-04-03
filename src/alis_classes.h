#pragma once

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