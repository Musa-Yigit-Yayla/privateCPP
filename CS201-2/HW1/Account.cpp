#include <string>
#include <iostream>
#include "Branch.h"
#include "Customer.h"
#include "Account.h"

static void sortAllAccounts(Account* accounts, Account** accountPointers, int low, int high);
static int partition(Account* accounts, Account** accountPointers, int low, int high);

//public:
    Account::Account(){
        /*if(0 == this->accountsCreated){
            this->accountCount = 0;
            this->accountsCreated = 0;
            //this->isAccountCreated = true;
        }*/
        //this->branch = &branch;
        //this->accountCount++;
        //this->accountsCreated++;
        //this->id = this->accountsCreated;
        //cout << "Default account constructor invoked. Account ID:" << this->id << endl;
    }
    Account::Account(double amount){
        if(this->accountsCreated == 0){
            this->accountCount = 0;
            this->accountsCreated = 0;
            //this->isAccountCreated = true;
        }
        this->balance = amount;
        //this->accountCount++;
        //this->accountsCreated++;
        this->id = this->accountsCreated;
    }
    Account::Account(double amount, Branch& branch, Customer& customer){
        if(this->accountsCreated == 0){
            this->accountCount = 0;
            this->accountsCreated = 0;
            //this->isAccountCreated = true;
        }

        this->balance = amount;
        this->branch = &branch;
        this->customer = &customer;
        this->accountCount++;
        this->accountsCreated++;
        this->id = this->accountsCreated;
    }
    //Just to create temporary Account objects, will not be used for literal Accounts
    Account::Account(Branch* branch){
        this->branch = branch;
    }
    Account::~Account(){
        this->accountCount--;
    }
    Branch* Account::getBranch() const{
        return this->branch;
    }
    Customer* Account::getCustomer() const{
        return this->customer;
    }
    void Account::setBranch(Branch* branch){
        this->branch = branch;
        this->branch->addAccount(*this);
    }
    void Account::setCustomer(Customer* customer){
        this->customer = customer;
        this->customer->addAccount(*this);
    }
    double Account::getBalance() const{
        return this->balance;
    }
    int Account::getId() const{
        return this->id;
    }
    int Account::getAccountCount() const{
        return this->accountCount;
    }
    void Account::deposit(double amount){
        this->balance += amount;
    }
    double Account::withdraw(double amount){
        if(this->balance >= amount){
            this->balance -= amount;
            return amount;
        }
        else if(this->balance >= 0){
            return this->balance;
        }
        else{
            return 0;
        }
    }
    string Account::to_string() const{
        //ToDo
        return "";
    }
    int Account::compareTo(Account& givenAccount){
        return this->id - givenAccount.id;
    }
    //Sorts all accounts by id, by using their compareTo method
    //Will be used to showAllAccounts
    //Uses quick sort
    void Account::sortAllAccounts(Account* accounts, Account** accountPointers, int low, int high){
        // base case
        if (low >= high)
            return;

        int p = partition(accounts, accountPointers, low, high);

        quickSort(accounts, accountPointers, low, p - 1);
        quickSort(accounts, accountPointers, p + 1, high);
    }
    /*int Account::partition(Account* accounts, Account** accountPointers, int low, int high){
        int pivot; //= accounts[low].getId();
        int initialLow = low;
        Account* pivotPointer = accountPointers[low];
        if(pivotPointer != nullptr){
            pivot = accounts[low].getId();
        }
        while(low < high){
            int currLowId = accounts[low].getId();
            int currHighId = accounts[high].getId();
            while(currLowId < pivot && low < high){
                low++;
                currLowId = accounts[low].getId();
            }
            while(currHighId > pivot && high > low){
                high--;
                currHighId = accounts[high].getId();
            }
            if(high >= low){
                //swap the low and high
                Account* temp = &accounts[low];
                accounts[low] = accounts[high];
                accounts[high] = *temp;

                temp = accountPointers[low];
                accountPointers[low] = accountPointers[high];
                accountPointers[high] = temp;

                low++;
                high--;
            }
        }
        /*Account* temp = &accounts[high];
        accounts[high] = pivot;
        accounts[initialLow] = *temp;

        temp = accountPointers[high];
        accountPointers[high] = pivotPointer;
        accountPointers[high] = temp;*/

     //   return high;
    //}
    int Account::partition(Account* accounts, Account** accountPointers, int start, int end){
        int pivot = accounts[start].getId();

        int count = 0;
        for (int i = start + 1; i <= end; i++) {
            if (accounts[i].getId() <= pivot)
                count++;
        }

        // Giving pivot element its correct position
        int pivotIndex = start + count;

        int low = start;
        int high = pivotIndex;

        Account* temp = &accounts[low];
        accounts[low] = accounts[high];
        accounts[high] = *temp;

        temp = accountPointers[low];
        accountPointers[low] = accountPointers[high];
        accountPointers[high] = temp;

        // Sorting left and right parts of the pivot element
        int i = start, j = end;

        while(i < pivotIndex && j > pivotIndex){

            while(accounts[i].getId() <= pivot){
                i++;
            }

            while(accounts[j].getId() > pivot){
                j--;
            }

            if(i < pivotIndex && j > pivotIndex){
                //swap(arr[i++], arr[j--]);

                int low = i;
                int high = j;

                Account* temp = &accounts[low];
                accounts[low] = accounts[high];
                accounts[high] = *temp;

                temp = accountPointers[low];
                accountPointers[low] = accountPointers[high];
                accountPointers[high] = temp;

                i++;
                j--;
            }
        }

        return pivotIndex;
    }
    int Account::accountCount = 0;
    int Account::accountsCreated =  0;
/*
private:
    double balance;
    int id;
    Branch* branch;
    Customer* customer;
    static int accountCount = 0;*/
