/*
*Musa Yiğit Yayla
*22003108
*CS201-1
*HW1
*/
#include "Branch.h"
#include "Account.h"
#include "Customer.h"
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;
//public:
    Branch::Branch(const int branchId, const string branchName){
        this->accounts = new Account[8];
        this->accountPointers = new Account*[8];
        this->branchId = branchId;
        this->branchName = branchName;

        if(!this->isBranchCreated){
            this->branchCount = 0;
            this->isBranchCreated = true;
        }

        for(int i = 0; i < this->accountsLength; i++){
            this->accountPointers[i] = nullptr;
            //&(this->accounts + i) = nullptr;
            this->accountsCount++;
        }
        this->branchCount += 1;
    }
    Branch::Branch(){
        this->accounts = new Account[8];
        this->accountPointers = new Account*[8];
        if(!this->isBranchCreated){
            this->branchCount = 0;
            this->isBranchCreated = true;
        }
        this->branchCount++;
    }
    int Branch::getBranchId() const{
        return this->branchId;
    }
    string Branch::getBranchName() const{
        return this->branchName;
    }
    int Branch::getBranchCount() const {
        return branchCount;
    }
    void Branch::setBranchId(int branchId){
        this->branchId = branchId;
    }
    void Branch::setBranchName(string branchName){
        this->branchName = branchName;
    }
    //Utility methods

    //Doubles the size of the Account array when necessary
    void Branch::addAccount(Account& acc){
        //Account* ptr = &this->accounts[0];
        Account* ptr = this->accountPointers[0];
        int index = 0;
        while(ptr != nullptr){
            ptr++;
            index++;
        }

        if(ptr != nullptr){ // means the array is full
            Account* newAccounts = new Account[this->accountsLength * 2];
            Account** newAccountPointers = new Account*[this->accountsLength * 2];
            for(int i = 0; i < this->accountsLength; i++){
                newAccounts[i] = this->accounts[i];
                newAccountPointers[i] = this->accountPointers[i];
            }
            //add to the end
            newAccounts[this->accountsLength] = acc;
            newAccountPointers[this->accountsLength] = &acc;
            this->accountsCount++;
            cout << "Account " << acc.getId() << " added for customer " << acc.getCustomer()->getId() << " at branch " << acc.getBranch()->getBranchId() << endl;

            for(int i = this->accountsLength + 1; i < this->accountsLength * 2; i++){
                //&(newAccounts + i) = nullptr;
                newAccountPointers[i] = nullptr;
            }
            this->accountsLength *= 2;
            this->accounts = newAccounts;
        }
        else{
            /*//Search for the first nullptr
            for(int i = 0; i < this->accountsLength; i++){
                if(this->accounts[i] == nullptr){
                    this->accounts[i] = acc;
                    this->accountsCount++;
                    cout << "Account " << acc->getId() << " added for customer " << acc.getCustomer()->getId() << " at branch " << acc.getBranch()->getBranchId() << endl;
                    break;
                }
            }*/
            this->accounts[index] = acc;
            this->accountPointers[index] = &acc;
            this->accountsCount++;
            cout << "Account " << acc.getId() << " added for customer " << acc.getCustomer()->getId() << " at branch " << acc.getBranch()->getBranchId() << endl;
        }
        //FURTHER ATTENTION REQUIRED FOR THIS METHOD
        //Done no further attention required apparently
    }
    //Deletes the account with the given ID
    //Returns accountId if deletion is successful, else returns -1
    //Make sure to delete the account from the corresponding Customer too. i. e. modify the Customer's Account array too.
    //Invoke this method to delete an account, not the Customer's method. That method will be invoked from here.
    int Branch::deleteAccount(const int accountId){
        //Account* account = &this->accounts[0]; //account to be deleted
        Account* account = this->accountPointers[0];
        int result = -1;
        for(int i = 1; i < this->accountsLength && account != nullptr; i++){
            //Account* curr = &this->accounts[i];
            Account* curr = this->accountPointers[i];
            if(curr != nullptr && curr->getId() == accountId){
                result = accountId;
                break;
            }
        }


        if(result == - 1){
            cout << "Account " << result << " does not exist" << endl;
        }
        else{
            //First remove the Account from Customer's Account array
            account->getCustomer()->deleteAccount(accountId);
            //Then delete the actual account, and update the array in the Branch accordingly
            int i = 1;
            while(i < this->accountsLength && account != nullptr){
                if(account->getId() == accountId){
                    delete account;
                    cout << "Account " << accountId << "has been deleted" << endl;
                    break;
                }
                i++;
                account = this->accountPointers[i];
            }
            //Shift the remaining elements
            while(i < this->accountsLength - 1){
                this->accounts[i] = this->accounts[i + 1];
                this->accountPointers[i] = this->accountPointers[i + 1];
                i++;
            }
        }
        return result;
    }
    //Returns the account matching the given accountId, returns nullptr otherwise
    Account* Branch::getAccount(int accountId) const{
        Account* result = nullptr;
        int i = 0;

        while(result != nullptr && i <this->accountsLength){
            if(result->getId() == accountId){
                break;
            }
            i++;
            result = &this->accounts[i];
        }
        return result;
    }
    Account* Branch::getAllAccounts() const{
        return this->accounts;
    }
    int Branch::getAccountCount() const{
        return this->accountsLength;
    }
    string Branch::to_string() const{
        string idString = "" + this->branchId;
        string accountsCountString = "" + this->accountsCount;
        string result = "Branch id: " + idString + "    Branch name: " + this->branchName + "      Number of accounts: " + accountsCountString + "\n";
        string accountBalance = "";
        for(int i = 0; i < this->accountsCount; i++){
            if(i == 0){
                result += "Accounts at this branch:\n";
                result += "Account id  Customer id     Customer name         Balance\n";
            }
            Account* currAccount = &this->accounts[i];
            /*char buffer[100];
            string s = "%-12d%-16d%-22s";
            char writeable[s.size()];
            for(int j = 0; j < s.size(); j++){
                buffer[j] = s.at(j);
                writeable[j] = s.at(j);
            }
            sprintf(buffer, writeable, currAccount->getId(), currAccount->getCustomer()->getId(), currAccount->getCustomer()->getCustomerName());
            for(int j = 0; j < 50; j++){
                result += buffer[j];
            }*/
            result += std::to_string(currAccount->getId()) + " " + std::to_string(currAccount->getId()) + " " + std::to_string(currAccount->getCustomer()->getId()) + " " + currAccount->getCustomer()->getCustomerName();
            accountBalance += currAccount->getBalance();
            string s;
            s += accountBalance + "\n";
            result += s;
        }
        return result;
    }
    bool Branch::isBranchCreated = false;
    int Branch::branchCount = 0;
    /*
private:
    int branchId;
    string branchName;
    Account* accounts = new Account[8];
    static int branchCount = 0;*/
