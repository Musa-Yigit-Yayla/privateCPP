/*
*Musa Yiğit Yayla
*22003108
*CS201-1
*HW1
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H
#pragma once

class Account;
//class Branch;
#include <string>
//#include "Account.h"

using namespace std;
class Customer{
public:
    Customer(const int customerId, const string customerName);
    Customer();
    int getId() const;
    string getCustomerName() const;
    void setId(int customerId);
    void setCustomerName(string customerName);
    void addAccount(Account& acc);
    int deleteAccount(const int accountId);
    Account* getAllAccounts() const;
    string to_string() const;
    int getAccountCount() const;
private:
    int customerId;
    string customerName;
    int accountsLength = 8;
    int accountCount = 0;
    Account* accounts;
    static int customerCount;
    bool isCustomerCreated = false;
};

#endif // CUSTOMER_H
