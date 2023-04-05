/*
*Musa Yiğit Yayla
*22003108
*CS201-1
*HW1
*/
#include <string>
#include <iostream>
//#include "Branch.h"
//#include "Customer.h"

using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H
#pragma once

class Customer;
class Branch;

//#include "Branch.h"
//#include "Customer.h"
#include <string>

class Account{
public:
    Account();
    Account(double amount);
    Account(double amount, Branch& branch, Customer& customer);
    Account(Branch* branch);
    ~Account();
    Branch* getBranch() const;
    Customer* getCustomer() const;
    void setBranch(Branch* branch);
    void setCustomer(Customer* customer);
    double getBalance() const;
    int getId() const;
    int getAccountCount() const;
    void deposit(double amount);
    double withdraw(double amount);
    int partition(Account* accounts, Account** accountPointers, int low, int high);
    void sortAllAccounts(Account* accounts, Account** accountPointers, int low, int high);
    void sortAllAccounts(Account accounts[], Account* accountPointers[], int n);
    string to_string() const;
    int compareTo(Account& givenAccount);
private:
    double balance = 0.0;
    int id = 0;
    Branch* branch = nullptr;
    Customer* customer = nullptr;
    static int accountCount;
    static int accountsCreated; //static variable representing accounts that have been created so far (do not decrement)
    //bool isAccountCreated = false; // represents whether an account has been instantiated or not, will be useful in constructors
};


#endif // ACCOUNT_H
