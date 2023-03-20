#include "Customer.h"
#include <string>
#include <iostream>

using namespace std;
public:



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
