/*
*Musa Yiğit Yayla
*22003108
*CS201-1
*HW1
*/

#ifndef BANKGING_SYSTEM_H
#define BANKING_SYSTEM_H
#pragma once

#include <string>
#include "Branch.h"
#include "Customer.h"
#include "Account.h"

using namespace std;
class BankingSystem {
public:
    BankingSystem();
    ~BankingSystem();
    void addBranch ( const int branchId , const string branchName ) ;
    void deleteBranch ( const int branchId ) ;
    void addCustomer ( const int customerId , const string customerName ) ;
    void deleteCustomer ( const int customerId ) ;
    int addAccount ( const int branchId , const int customerId , const double amount ) ;
    void deleteAccount ( const int accountId ) ;
    void showAllAccounts () ;
    void showBranch ( const int branchId ) ;
    void showCustomer ( const int customerId ) ;

private:
    int branchLength = 8;
    int customerLength = 8;
    Branch* branches = new Branch[branchLength];
    Customer* customers = new Customer[customerLength];
};
#endif
