#pragma once

class BankAccount {
public:
	BankAccount() : balance(0) {}
	BankAccount(int balance) : balance(balance) {}

	int balance;
};