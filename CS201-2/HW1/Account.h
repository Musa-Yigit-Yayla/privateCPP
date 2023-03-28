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
    string to_string();
private:
    double balance = 0.0;
    int id;
    Branch* branch;
    Customer* customer;
    static int accountCount;
    static int accountsCreated; //static variable representing accounts that have been created so far (do not decrement)
    //bool isAccountCreated = false; // represents whether an account has been instantiated or not, will be useful in constructors
};


#endif // ACCOUNT_H
