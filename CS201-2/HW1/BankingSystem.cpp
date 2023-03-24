#include "BankingSystem.h"
#include "Branch.h"
#include "Customer.h"
#include "Account.h"
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

//public:
    BankingSystem::BankingSystem(){
        this->branches = new Branch[this->branchLength];
        for(int i = 0; i < branchLength; i++){
            this->branches[i] = nullptr;
        }

        this->customers = new Customer[this->customerLength];
        for(int i = 0; i < customerLength; i++){
            this->customers[i] = nullptr;
        }
    }
    BankingSystem::~BankingSystem(){
        delete[] this->branches;
        delete[] this->customers;
    }
    void BankingSystem::addBranch ( const int branchId , const string branchName ){

        //First check if a branch with the given ID already exists
        for(int i = 0; i < this->branchLength; i++){
            Branch* curr = &this->branches[i];
            if(curr == nullptr){
                break;
            }
            else if(curr->getBranchId() == branchId){
                cout << "Branch " << branchId << " already exists" << endl;
                return;
            }
            delete curr;
        }

        Branch branch(branchId, branchName);

        Branch* ptr = &this->branches[0];
        while(ptr != nullptr){
            ptr++;
        }
        if(ptr - &this->branches[0] == this->branchLength){
            //double the array size and copy the elements into the new array
            Branch* newBranches = new Branch[this->branchLength * 2];
            for(int i = 0; i < this->branchLength; i++){
                newBranches[i] = this->branches[i];
            }
            //Make the addition then set the rest to nullptr
            newBranches[branchLength] = branch;
            cout << "Branch " << branchId << " has been added" << endl;

            for(int i = this->branchLength + 1; i < this->branchLength * 2; i++){
                 newBranches + i = nullptr;
            }
            this->branches = newBranches;
            this->branchLength *= 2;
        }
        else{
            this->branches[ptr - this->branches] = branch;
            cout << "Branch " << branchId << " has been added" << endl;
        }
    }
    void BankingSystem::deleteBranch ( const int branchId ){
        bool isDeleted = false;
        for(int i = 0; i < this->branchLength; i++){
            Branch* currBranch = &this->branches[i];
            if(currBranch->getBranchId() == branchId){
                delete &this->branches[i];
                isDeleted = true;
                cout << "Branch " << branchId << " has been deleted" << endl;
            }
            if(isDeleted && i < this->branchLength - 1){
                this->branches[i] = this->branches[i + 1];
            }
            else if(isDeleted && i == this->branchLength - 1){
                this->branches[i] = nullptr;
            }
        }
        if(!isDeleted){
            cout << "Branch " << branchId << " does not exist" << endl;
        }
    }
    void BankingSystem::addCustomer ( const int customerId , const string customerName ){

        //Initially check whether a customer with the given Id exists
        for(int i = 0; i < this->customerLength; i++){
            Customer* curr = &this->customers[i];
            if(curr == nullptr){
                break;
            }
            else if(curr->getId() == customerId){
                cout << "Customer " << customerId << " already exists" << endl;
                return;
            }
            delete curr;
        }

        Customer* customer = new Customer(customerId, customerName);
        Customer* ptr = &this->customers[0];
        while(ptr != nullptr){
            ptr++;
        }
        if(ptr - &this->customers[0] == this->customerLength){
            //Double the array size and use the pointers to point to the elements of the array
            Customer* newCustomers = new Customer[this->customerLength * 2];
            for(int i = 0; i < this->customerLength; i++){
                newCustomers[i] = this->customers[i];
            }
            newCustomers[this->customerLength] = *customer;
            cout << "Customer " << customerId << " has been added" << endl;
            for(int i = this->customerLength + 1; i < this->customerLength * 2; i++){
                this->customers[i] = nullptr;
            }
            this->customers = newCustomers;
            this->customerLength *= 2;
        }
        else{
            this->customers[ptr - this->customers] = *customer;
            cout << "Customer " << customerId << " has been added" << endl;
        }

    }
    void BankingSystem::deleteCustomer ( const int customerId ){
        bool isDeleted = false;
        for(int i = 0; i < this->customerLength; i++){
            Customer currCustomer = this->customers[i];
            if(currCustomer.getId() == customerId){
                delete &this->customers[i];
                cout << "Customer " << customerId << " has been deleted" << endl;
                isDeleted = true;
            }
            if(isDeleted && i < this->customerLength - 1){
                this->customers[i] = this->customers[i + 1];
            }
            else if(isDeleted && i == this->customerLength - 1){
                this->customers[i] = nullptr;
            }
        }
        if(!isDeleted){
            cout << "Customer " << customerId << " does not exist" << endl;
        }
    }
    int BankingSystem::addAccount ( const int branchId , const int customerId , const double amount ){
        //check whether a branch with given ID exists
        Branch* branch;
        Customer* customer;
        bool branchExists = false;
        for(int i = 0; i < this->branchLength; i++){
            Branch* currBranch = &this->branches[i];
            if(currBranch ==  nullptr){
                break;
            }
            else if(currBranch->getBranchId() == branchId){
                branchExists = true;
                branch = currBranch;
                break;
            }
        }
        if(!branchExists){
            cout << "Branch " << branchId << " does not exist" << endl;
            return -1;
        }
        bool customerExists = false;
        for(int i = 0; i < this->customerLength; i++){
            Customer* currCustomer = &this->customers[i];
            if(currCustomer == nullptr){
                break;
            }
            else if(currCustomer->getId() == customerId){
                customerExists = true;
                customer = currCustomer;
                break;
            }
        }
        if(!customerExists){
            cout << "Customer " << customerId << " does not exist" << endl;
            return -1;
        }

        //Both the customer and the branch exists, proceed accordingly.
        Account account(amount, *branch, *customer);
        branch->addAccount(account);
        customer->addAccount(account);
        cout << "Account " << account.getId() << " added for customer " << account.getCustomer()->getId() << " at branch " << branch->getBranchId() << endl;
        return accountId;
    }
    void BankingSystem::deleteAccount ( const int accountId ){
        Account* account;
        Branch* branch = &this->branches[0];
        int i = 0;
        while(i < this->branchLength && branch != nullptr){
            Account* account = branch->getAccount(accountId);
            if(account->getId() == accountId){
                branch->deleteAccount(accountId);
                break;
            }
            branch = &this->branches[i];
            i++;
        }
        //Get the branch and the customer of the account if exists
    }
    void BankingSystem::showAllAccounts() {
        //Account id Branch id Branch name Customer id Customer name Balance
        printf("%-12s%-12s%-16s%-16s%-27sBalance\n", "Account id", "Branch id", "Branch name", "Customer id", "Customer name" );
        for(int i = 0; i < this->customerLength; i++){
            Customer* currCustomer = this->customers[i];
            if(currCustomer != nullptr){
                Account* accounts = currCustomer->getAllAccounts();
                int accountLength = currCustomer->getAccountCount();
                Account* currAccount = accounts[j];
                for(int j = 0; j < accountLength && currAccount != nullptr; j++){
                    currAccount = accounts[j];

                    if(currAccount != nullptr){
                        Branch* currBranch = currAccount->getBranch();
                        //print out the line
                        printf("%-12d%-12d%-16s%-16d%-27s" + "" + currAccount->getBalance(), currAccount->getId(), currBranch->getBranchId(), currBranch->getName(), currCustomer->getId(), currCustomer->getCustomerName());
                    }
                }
            }
        }
    }
    void BankingSystem::showBranch ( const int branchId ){
        //search for the branch with the given id
        Branch* branch = &this->branches[0];
        for(int i = 0; i < this->branchesLength && branch != nullptr; i++){
            branch = this->branches[i];
            if(branch->getBranchId() == branchId){
                break;
            }
        }
        if(branch == nullptr){
            cout << "Branch " << branchId << " does not exist" << endl;
            return;
        }
        cout << branch->to_string() << endl;
    }
    void BankingSystem::showCustomer ( const int customerId ){
        //search whether the customer exists with the given id
        Customer* customer = this->customers[0];
        for(int i = 0; i < this->customersLength && customer != nullptr; i++){
            customer = this->customers[i];
            if(customer->getId() == customerId){
                break;
            }
        }
        if(customer == nullptr){
            cout << "Customer " << customerId << " does not exist" << endl;
            return;
        }
        cout << customer->to_string() << endl;
    }
/*
private:
    int branchLength = 8;
    int customerLength = 8;
    Branch* branches = new Branch[branchLength];
    Customer* customers = new Customer[customerLength];*/
