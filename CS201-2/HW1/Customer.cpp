#include "Customer.h"
#include "Account.h"
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;
//public:

    Customer::Customer(const int customerId, const string customerName){
        this->accounts = new Account(accountsLength);
        if(!this->isCustomerCreated){
            this->customerCount = 0;
            this->isCustomerCreated = true;
        }
        this->customerId = customerId;
        this->customerName = customerName;
        this->customerCount++;
    }
    Customer::Customer(){
        this->accounts = new Account(accountsLength);
        if(!this->isCustomerCreated){
            this->customerCount = 0;
            this->isCustomerCreated = true;
        }
        this->customerCount++;
    }
    int Customer::getId() const{
        return this->customerId;
    }
    string Customer::getCustomerName() const{
        return this->customerName;
    }
    void Customer::setId(int customerId){
        this->customerId = customerId;
    }
    void Customer::setCustomerName(string customerName){
        this->customerName = customerName;
    }
    void Customer::addAccount(Account& acc){
        this->accounts[this->accountCount++] = acc;
    }
    //Is not a standalone function, invoked from Branch::deleteAccount
    //Removes the given account from the array by shifting elements by left once. Does not delete the account
    //Returns the accountId if deletion successful, else returns -1
    int Customer::deleteAccount(const int accountId){
        Account* account = &this->accounts[0];
        int result = -1;
        int i = 1;
        while(i < this->accountsLength && account != nullptr){
            if(account->getId() == accountId){
                result = accountId;
                break;
            }
            i++;
            account = &this->accounts[i];
        }
        if(result != -1){
            while(i < this->accountsLength - 1){
                this->accounts[i] = this->accounts[i + 1];
                i++;
            }
            this->accounts[i] = nullptr;
            this->accountCount--;
        }
        return result;
    }
    Account* Customer::getAllAccounts() const{
        return this->accounts;
    }
    int Customer::getAccountCount() const{
        return this->accountsLength;
    }
    string Customer::to_string() const{
        string s = "%-13s%-7d%-15s%-19sNumber of accounts: ";
        sprintf(s, "Customer id:", "" + this->customerId, "Customer name:", this->customerName);
        s += "" + this->accountCount + "\n";
        if(this->accountCount != 0){
            s += "Accounts of this customer:\n";
            for(int i = 0; i < this->accountCount; i++){
                string line;
                if(i == 0){
                    line = "%-12s%-16s%-20sBalance\n";
                    sprintf(line, "Account id", "Branch id", "Branch name");
                    s += line;
                }
                line = "%-12d%-16d%-20s" + this->accounts[i]->getBalance() + "\n";
                sprintf(line, this->accounts[i]->getId(), this->accounts[i]->getBranch()->getBranchId(), this->accounts[i]->getBranch()->getBranchName());
                s += line;
            }
        }
        return s;
    }
/*private:
    int customerId;
    string customerName;
    int accountsLength = 8;
    Account* accounts = new Account(accountsLength);
    static int customerCount = 0;*/
