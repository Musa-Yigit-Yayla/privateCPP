#include <string>
#include <iostream>
#include "Account.h"

public:
    Account::Account(){

    }
    Account::Account(double amount){
        this->amount = amount;
    }
    Account::Account(double amount, Branch& branch, Customer& customer){
        this->Account(amount);
        this->branch = branch;
        this->customer = customer;
    }
    //Use this constructor generally
    Account::Account(int branchId, int customerId, double amount){
        //Retrieve the customer and the branch by their ids from the BankingSystem


        this->amount = amount;
    }
    Branch* Account::getBranch() const{
        return &this->branch;
    }
    Customer* Account::getCustomer() const{
        return &this->customer;
    }
    void Account::setBranch(Branch* branch){
        this->branch = branch;
        this->branch.addAccount(this);
    }
    void Account::setCustomer(Customer* customer){
        this->customer = customer;
        this->customer.addAccount(this);
    }
    void Account::deposit(double amount){
        this->amount += amount;
    }
    double Account::withdraw(double amount){
        if(this->amount >= amount){
            this->amount -= amount;
            return amount;
        }
        else if(this->amount >= 0){
            return this->amount;
        }
        else{
            return 0;
        }
    }

/*
private:
    double balance;
    int id;
    Branch branch;
    Customer customer;
    static int accountCount = 0;*/
