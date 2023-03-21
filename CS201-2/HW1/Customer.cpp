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
    int Customer::deleteAccount(const int accountId){

    }
    string Customer::to_string() const{

    }
/*private:
    int customerId;
    string customerName;
    int accountsLength = 8;
    Account* accounts = new Account(accountsLength);
    static int customerCount = 0;*/
