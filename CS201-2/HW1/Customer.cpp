#include "Customer.h"
#include <string>
#include <iostream>

using namespace std;
public:

    Customer::Customer(const int customerId, const string customerName){
        this->customerId = customerId;
        this->customerName = customerName;
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

    }
    //Is not a standalone function, invoked from Branch::deleteAccount
    //Removes the given account from the array by shifting elements by left once. Does not delete the account
    //Returns the accountId if deletion successful, else returns -1
    int Customer::deleteAccount(const int accountId){
        Account* account = this->accounts[0];
        int result = -1;
        int i = 1;
        while(i < this->accountsLength && account != nullptr){
            if(account->getId() == accountId){
                result = accountId;
                break;
            }
            i++;
            account = this->accounts[i];
        }
        if(result != -1){
            while(i < this->accountsLength - 1){
                this->accounts[i] = this->accounts[i + 1];
                i++;
            }
            this->accounts[i] = nullptr;
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

    }
/*private:
    int customerId;
    string customerName;
    int accountsLength = 8;
    Account* accounts = new Account(accountsLength);
    static int customerCount = 0;*/
