#include <string>
#include <iostream>
#include "Branch.h"
#include "Customer.h"

using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account{
public:
    Account();
    Account(double amount);
    Account::Account(double amount, Branch& branch, Customer& customer)
    Account::~Account();
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
    double balance;
    int id;
    Branch branch;
    Customer customer;
    static int accountCount = 0;
    static int accountsCreated = 0; //static variable representing accounts that have been created so far (do not decrement)
};


#endif // ACCOUNT_H
