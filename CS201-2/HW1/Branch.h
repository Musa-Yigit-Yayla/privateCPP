/*
*Musa Yiğit Yayla
*22003108
*CS201-1
*HW1
*/
#ifndef BRANCH_H
#define BRANCH_H
#pragma once

#include <string>

using namespace std;
class Branch{
public:
    Branch(const int branchId, const string branchName);
    int getBranchId() const;
    string getBranchName() const;
    int getBranchCount() const;
    void setBranchId(int branchId);
    void setBranchName(string branchName) const;
    //Utility methods

    //Doubles the size of the Account array when necessary
    void addAccount(Account& acc);
    //Deletes the account with the given ID
    //Returns accountId if deletion is successful, else returns -1
    int deleteAccount(const int accountId);
    string to_string() const;
private:
    int branchId;
    string branchName;
    Account* accounts = new Account[8];
    int accountsLength = 8;
    static int branchCount = 0;
};
#endif // BRANCH_H
