#include "BankingSystem.h"
#include "Branch.h"
#include "Customer.h"
#include "Account.h"
#include <string>
#include <iostream>

using namespace std;

public:
    BankingSystem(){
        for(int i = 0; i < branchLength; i++){
            this->branch[i] = nullptr;
        }
        for(int i = 0; i < customerLength; i++){
            this->customer[i] = nullptr;
        }
    }
    ~BankingSystem(){
        delete[] this->branches;
        delete[] this->customers;
    }
    void addBranch ( const int branchId , const string branchName ){
        Branch branch(BranchId, branchName);

        int currLength = 0;
        Branch* ptr = this->branches[0];
        while(ptr != nullptr){
            ptr++;
        }
        if(ptr == this->branchLength){
            //double the array size and copy the elements into the new array
            Branch* newBranches = new Branch(this->branchLength * 2);
            for(int i = 0; i < this->branchLength; i++){
                newBranches[i] = this->branches[i];
            }
        }
        else{
            this->branches[ptr - this->branches] = branch;
        }
    }
    void deleteBranch ( const int branchId );
    void addCustomer ( const int customerId , const string customerName ) ;
    void deleteCustomer ( const int customerId ) ;
    int addAccount ( const int branchId , const int customerId , const double amount ) ;
    void deleteAccount ( const int accountId ) ;
    void showAllAccounts () ;
    void showBranch ( const int branchId ) ;
    void showCustomer ( const int customerId ) ;
/*
private:
    int branchLength = 8;
    int customerLength = 8;
    Branch* branches = new Branch[branchLength];
    Customer* customers = new Customer[customerLength];*/
