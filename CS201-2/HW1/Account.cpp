#include <string>
#include <iostream>
#include "Branch.h"
#include "Customer.h"
#include "Account.h"


//public:
    Account::Account(){
        if(!this->isAccountCreated){
            this->accountCount = 0;
            this->accountsCreated = 0;
            this->isAccountCreated = true;
        }
        this->accountCount++;
        this->accountsCreated++;
        this->id = this->accountsCreated;
    }
    Account::Account(double amount){
        if(!this->isAccountCreated){
            this->accountCount = 0;
            this->accountsCreated = 0;
            this->isAccountCreated = true;
        }
        this->balance = amount;
        this->accountCount++;
        this->accountsCreated++;
        this->id = this->accountsCreated;
    }
    Account::Account(double amount, Branch& branch, Customer& customer){
        if(!this->isAccountCreated){
            this->accountCount = 0;
            this->accountsCreated = 0;
            this->isAccountCreated = true;
        }

        this->balance = amount;
        this->branch = &branch;
        this->customer = &customer;
        this->accountCount++;
        this->accountsCreated++;
        this->id = this->accountsCreated;
    }
    Account::~Account(){
        this->accountCount--;
    }
    Branch* Account::getBranch() const{
        return this->branch;
    }
    Customer* Account::getCustomer() const{
        return this->customer;
    }
    void Account::setBranch(Branch* branch){
        this->branch = branch;
        this->branch->addAccount(*this);
    }
    void Account::setCustomer(Customer* customer){
        this->customer = customer;
        this->customer->addAccount(*this);
    }
    double Account::getBalance() const{
        return this->balance;
    }
    int Account::getId() const{
        return this->id;
    }
    int Account::getAccountCount() const{
        return this->accountCount;
    }
    void Account::deposit(double amount){
        this->balance += amount;
    }
    double Account::withdraw(double amount){
        if(this->balance >= amount){
            this->balance -= amount;
            return amount;
        }
        else if(this->balance >= 0){
            return this->balance;
        }
        else{
            return 0;
        }
    }

/*
private:
    double balance;
    int id;
    Branch* branch;
    Customer* customer;
    static int accountCount = 0;*/
