/*
*Musa Yiğit Yayla
*22003108
*CS201-1
*HW1
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H
#pragma once

using namespace std;
class Customer{
public:
    Customer(const int customerId, const string customerName);
    int getId() const;
    string getCustomerName() const;
    void setId(int customerId);
    void setCustomerName(string customerName);
    void addAccount(Account& acc);
    int deleteAccount(const int accountId);
    string to_string() const;
private:
    int customerId;
    string customerName;
    int accountsLength = 8;
    Account* accounts = new Account(accountsLength);
    static int customerCount = 0;
};

#endif // CUSTOMER_H
