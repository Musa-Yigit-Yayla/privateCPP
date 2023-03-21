/*
*Musa Yiğit Yayla
*22003108
*CS201-1
*HW1
*/
#include "Branch.h"
#include <string>
#include <iostream>

using namespace std;
public:
    Branch::Branch(const int branchId, const string branchName){
        this->branchId = branchId;
        this->branchName = branchName;

        for(int i = 0; i < this->accountsLength; i++){
            this->accounts[i] = nullptr;
        }
        this->branchCount += 1;
    }
    Branch::int getBranchId() const{
        return this->branchId
    }
    Branch::string getBranchName() const{
        return this->branchName;
    }
    int Branch::getBranchCount() const {
        return branchCount;
    }
    void Branch::setBranchId(int branchId){
        this->branchId = branchId;
    }
    void Branch::setBranchName(string branchName) const{
        this->branchName = branchName;
    }
    //Utility methods

    //Doubles the size of the Account array when necessary
    void Branch::addAccount(Account& acc){
        Account* ptr = this->accounts[0];
        while(ptr != nullptr){
            ptr++;
        }

        if(ptr != nullptr)){ // means the array is full
            Account* newAccounts = new Account[this->accountsLength * 2];
            for(int i = 0; i < this->accountsLength; i++){
                newAccounts[i] = this->accounts[i];
            }
            //add to the end
            newAccounts[this->accountsLength] = acc;
            cout << "Account " << acc->getId() << " added for customer " << acc.getCustomer()->getId() << " at branch " << acc.getBranch()->getBranchId() << endl;

            for(int i = this->accountsLength + 1; i < this->accountsLength * 2; i++){
                newAccounts[i] = nullptr;
            }
            this->accountsLength *= 2;
            this->accounts = newAccounts;
        }
        //Search for the first nullptr
        for(int i = 0; i < this->accountsLength; i++){
            if(this->accounts[i] == nullptr){
                this->accounts[i] = acc;
                cout << "Account " << acc.getId() <<
            }
        }

        //FURTHER ATTENTION REQUIRED FOR THIS METHOD
    }
    //Deletes the account with the given ID
    //Returns accountId if deletion is successful, else returns -1
    //Make sure to delete the account from the corresponding Customer too. i. e. modify the Customer's Account array too.
    int Branch::deleteAccount(const int accountId){

    }
    string Branch::to_string() const{

    }

    /*
private:
    int branchId;
    string branchName;
    Account* accounts = new Account[8];
    static int branchCount = 0;*/
