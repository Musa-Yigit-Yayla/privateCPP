/*
*Musa Yiğit Yayla
*22003108
*CS201-1
*HW1
*/
#ifndef BRANCH_H
#define BRANCH_H
#pragma once

//class Customer;
class Account;
#include <string>
//#include "Account.h"

using namespace std;
class Branch{
public:
    Branch(const int branchId, const string branchName);
    Branch();
    int getBranchId() const;
    string getBranchName() const;
    int getBranchCount() const;
    void setBranchId(int branchId);
    void setBranchName(string branchName);
    //Utility methods

    //Doubles the size of the Account array when necessary
    void addAccount(Account& acc);
    //Deletes the account with the given ID
    //Returns accountId if deletion is successful, else returns -1
    int deleteAccount(const int accountId);
    Account* getAccount(int accountId) const;
    Account* getAllAccounts() const;
    int getAccountCount() const;
    string to_string() const;
private:
    int branchId;
    string branchName;
    Account* accounts;
    int accountsLength = 8;
    int accountsCount = 0;
    static int branchCount;
    bool isBranchCreated = false;
};
#endif // BRANCH_H
