#include "BankingSystem.h"
#include "Branch.h"
#include "Customer.h"
#include "Account.h"
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

//public:
    BankingSystem::BankingSystem(){
        this->branches = new Branch[this->branchLength];
        this->branchPointers = new Branch*[this->branchLength];
        for(int i = 0; i < branchLength; i++){
            (this->branchPointers[i]) = nullptr;
        }

        this->customers = new Customer[this->customerLength];
        this->customerPointers = new Customer*[this->customerLength];
        for(int i = 0; i < customerLength; i++){
            (this->customerPointers[i]) = nullptr;
        }
    }
    BankingSystem::~BankingSystem(){
        delete[] this->branches;
        delete[] this->branchPointers;
        delete[] this->customers;
        delete[] this->customerPointers;
    }
    void BankingSystem::addBranch ( const int branchId , const string branchName ){

        //First check if a branch with the given ID already exists
        //bool isBranchFound = false;
        for(int i = 0; i < this->branchLength; i++){
            Branch* curr = this->branchPointers[i];
            int currBranchId;
            if(curr == nullptr){
                //delete curr;
                break;
            }
            else{
                currBranchId = curr->getBranchId();
            }
            if(currBranchId == branchId){
                cout << "Branch " << branchId << " already exists" << endl;
                return;
            }
            //delete curr;
        }

        Branch* branch = new Branch(branchId, branchName);
        Branch* ptr = this->branchPointers[0];

        while(ptr != nullptr && ptr - this->branchPointers[0] < this->branchLength){
            ptr++;
        }
        if(this->branchLength == 1 && ptr == nullptr && this->branchCount == 0){ // ptr == nullptr yap branchCount u
            //We are adding the first Account to the branch :)
            this->branches[0] = *branch;
            this->branchPointers[0] = branch;
            this->branchCount = 0;
            cout << "Branch " << branchId << " has been added" << endl;
            //this->branchLength += 1;
        }
        //MIGHT BE PROBLEMATIC !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! BELOW CODE Put the if else back maybe
        //else{
        //if(ptr - this->branchPointers[0] == this->branchLength){
        else{
            //double the array size and copy the elements into the new array
            Branch* newBranches = new Branch[this->branchLength + 1];
            Branch** newBranchPointers = new Branch*[this->branchLength + 1];
            for(int i = 0; i < this->branchLength; i++){
                newBranches[i] = this->branches[i];
                newBranchPointers[i] = this->branchPointers[i];
            }
            //Make the addition then set the rest to nullptr
            newBranches[branchLength] = *branch;
            newBranchPointers[branchLength] = branch;
            this->branchCount = 0;
            cout << "Branch " << branchId << " has been added" << endl;

            /*for(int i = this->branchLength + 1; i < this->branchLength * 2; i++){
                 (newBranchPointers[i]) = nullptr;
            }*/
            this->branches = newBranches;
            this->branchPointers = newBranchPointers;
            this->branchLength += 1;
        }
        //}
        //else{
            //this->branches[ptr - this->branches] = branch;
            //this->branchPointers[ptr - this->branches] = &branch;
            //cout << "Branch " << branchId << " has been added" << endl;
        //}
    }
    void BankingSystem::deleteBranch ( const int branchId ){
        bool isDeleted = false;
        Branch* newBranches = new Branch[this->branchLength - 1];
        Branch** newBranchPointers = new Branch*[this->branchLength - 1];
        int counter = 0; // counter representing newBranches index
        for(int i = 0; i < this->branchLength; i++){
            Branch* currBranch = this->branchPointers[i];
            if(currBranch->getBranchId() == branchId){
                //delete currBranch;
                //delete (&this->branches[i]); // might be problematic but it should work fine
                isDeleted = true;
                this->branchCount--;
                cout << "Branch " << branchId << " has been deleted" << endl;
            }
            // !!!!!!!!!!!!!!!!!!!! If problem occurs remove the below else and get the if else if statements out from the comments
            else{
                //Add the branch to the newBranches
                newBranches[counter] = this->branches[i];
                newBranchPointers[counter++] = this->branchPointers[i];
            }
            /*if(isDeleted && i < this->branchLength - 1){
                this->branches[i] = this->branches[i + 1];
                this->branchPointers[i] = this->branchPointers[i + 1];
            }
            else if(isDeleted && i == this->branchLength - 1){
                //this->branches[i] = nullptr;
                this->branchPointers[i] = nullptr;
            }*/

        }
        if(!isDeleted){
            cout << "Branch " << branchId << " does not exist" << endl;
        }
        else{
            if(this->branchLength > 1)
                this->branchLength -= 1;
        }
    }
    void BankingSystem::addCustomer ( const int customerId , const string customerName ){

        //Initially check whether a customer with the given Id exists
        for(int i = 0; i < this->customerLength; i++){
            Customer* curr = this->customerPointers[i];
            if(curr == nullptr){
                break;
            }
            else if(curr->getId() == customerId){
                cout << "Customer " << customerId << " already exists" << endl;
                return;
            }
            //delete curr;
        }

        Customer* customer = new Customer(customerId, customerName);
        Customer* ptr = this->customerPointers[0] + this->customerCount;
        /*while(ptr != nullptr){
            ptr++;
        }*/
        if(this->customerLength == 1 && this->customerCount == 0){
            //We are adding the first Customer to the customers :)
            this->customers[0] = *customer;
            this->customerPointers[0] = customer;
            this->customerCount++;
            cout << "Customer " << customerId << " has been added" << endl;
        }

        else{
            Customer* newCustomers = new Customer[this->customerLength + 1];
            Customer** newCustomerPointers = new Customer*[this->customerLength + 1];
            for(int i = 0; i < this->customerLength; i++){
                newCustomers[i] = this->customers[i];
                newCustomerPointers[i] = this->customerPointers[i];
            }
            //Make the addition then set the rest to nullptr
            newCustomers[customerLength] = *customer;
            newCustomerPointers[customerLength] = customer;

            this->customerCount++;
            this->customers = newCustomers;
            this->customerPointers = newCustomerPointers;
            this->customerLength += 1;

            cout << "Customer " << customerId << " has been added" << endl;
        }


        /*if(ptr - this->customerPointers[0] == this->customerLength){
            //Double the array size and use the pointers to point to the elements of the array
            Customer* newCustomers = new Customer[this->customerLength + 1];
            Customer** newCustomerPointers = new Customer*[this->customerLength + 1];
            for(int i = 0; i < this->customerLength; i++){
                newCustomers[i] = this->customers[i];
                newCustomerPointers[i] = this->customerPointers[i];
            }
            newCustomers[this->customerLength] = *customer;
            newCustomerPointers[this->customerLength] = customer;
            cout << "Customer " << customerId << " has been added" << endl;
            /*for(int i = this->customerLength + 1; i < this->customerLength * 2; i++){
                //this->customers[i] = nullptr;
                this->customerPointers[i] = nullptr;
            }
            this->customers = newCustomers;
            this->customerPointers = newCustomerPointers;
            this->customerLength += 1;
        }
        //else{
            //this->customers[ptr - this->customers] = *customer;
            //this->customerPointers[ptr - this->customers] = customer;
            cout << "Customer " << customerId << " has been added" << endl;
        //}
        */
    }
    void BankingSystem::deleteCustomer ( const int customerId ){
        bool isDeleted = false;
        Customer* newCustomers = new Customer[this->customerLength - 1];
        Customer** newCustomerPointers = new Customer*[this->customerLength - 1];
        int counter = 0;
        for(int i = 0; i < this->customerLength; i++){
            Customer currCustomer = this->customers[i];
            if(currCustomer.getId() == customerId){
                //delete &this->customers[i];
                //delete this->customerPointers[i];
                this->customerCount--;
                cout << "Customer " << customerId << " has been deleted" << endl;
                isDeleted = true;
            }
            else{
                newCustomers[counter] = currCustomer;
                newCustomerPointers[counter++] = &currCustomer;
            }
            /*if(isDeleted && i < this->customerLength - 1){
                this->customers[i] = this->customers[i + 1];
                this->customerPointers[i] = this->customerPointers[i + 1];
            }
            else if(isDeleted && i == this->customerLength - 1){
                //this->customers[i] = nullptr;
                this->customerPointers[i] = nullptr;
            }*/
        }
        if(!isDeleted){
            cout << "Customer " << customerId << " does not exist" << endl;
        }
        else{
            if(this->customerLength > 1)
            this->customerLength -= 1;
        }
    }
    int BankingSystem::addAccount ( const int branchId , const int customerId , const double amount ){
        //check whether a branch with given ID exists
        Branch* branch;
        Customer* customer;
        bool branchExists = false;
        for(int i = 0; i < this->branchLength; i++){
            Branch* currBranch = &this->branches[i];
            if(currBranch ==  nullptr){
                break;
            }
            else if(currBranch->getBranchId() == branchId){
                branchExists = true;
                branch = currBranch;
                break;
            }
        }
        if(!branchExists){
            cout << "Branch " << branchId << " does not exist" << endl;
            return -1;
        }
        bool customerExists = false;
        for(int i = 0; i < this->customerLength; i++){
            Customer* currCustomer = &this->customers[i];
            if(currCustomer == nullptr){
                break;
            }
            else if(currCustomer->getId() == customerId){
                customerExists = true;
                customer = currCustomer;
                break;
            }
        }
        if(!customerExists){
            cout << "Customer " << customerId << " does not exist" << endl;
            return -1;
        }

        //Both the customer and the branch exists, proceed accordingly.
        Account account(amount, *branch, *customer);
        branch->addAccount(account);
        customer->addAccount(account);
        cout << "Account " << account.getId() << " added for customer " << account.getCustomer()->getId() << " at branch " << branch->getBranchId() << endl;
        return account.getId();
    }
    void BankingSystem::deleteAccount ( const int accountId ){
        //Account* account;
        Branch* branch = &this->branches[0];
        int i = 0;
        while(i < this->branchLength && branch != nullptr){
            Account* account = branch->getAccount(accountId);
            if(account->getId() == accountId){
                branch->deleteAccount(accountId);
                break;
            }
            branch = &this->branches[i];
            i++;
        }
        //Get the branch and the customer of the account if exists
    }
    void BankingSystem::showAllAccounts() {
        //Account id Branch id Branch name Customer id Customer name Balance
        //printf("%-12s%-12s%-16s%-16s%-27sBalance\n", "Account id", "Branch id", "Branch name", "Customer id", "Customer name" );
        cout << "Account id " << "Branch id " << "Branch name " << "Customer id " << "Customer name " << "Balance" << endl;
        for(int i = 0; i < this->customerLength; i++){
            Customer* currCustomer = &this->customers[i];
            if(currCustomer != nullptr){
                Account* accounts = currCustomer->getAllAccounts();
                int accountLength = currCustomer->getAccountCount();
                Account* currAccount = &accounts[0];
                for(int j = 0; j < accountLength && currAccount != nullptr; j++){
                    currAccount = &accounts[j];

                    if(currAccount != nullptr){
                        Branch* currBranch = currAccount->getBranch();
                        string balanceString = " " + std::to_string(currAccount->getBalance());
                        string accountIdString = "" + currAccount->getId();
                        string branchIdString = " " + currBranch->getBranchId();
                        string customerIdString = " " + currCustomer->getId();
                        //print out the line
                        /*string formatString = "%-12s%-12d%-16s%-16d%-27s";
                        char format[formatString.size() + balanceString.size()];
                        for(int k = 0; k < formatString.size(); k++){
                            if(k < formatString.size()){
                                format[k] = formatString.at(k);
                            }
                            else{
                                format[k] =balanceString.at(k - formatString.size());
                            }
                        }
                        printf( format, accountIdString, branchIdString, currBranch->getBranchName(), customerIdString, currCustomer->getCustomerName());*/
                        cout << accountIdString << branchIdString << " " << currBranch->getBranchName() << " " << customerIdString << " " << currCustomer->getCustomerName() << endl;
                    }
                }
            }
        }
    }
    void BankingSystem::showBranch ( const int branchId ){
        //search for the branch with the given id
        Branch* branch = &this->branches[0];
        for(int i = 0; i < this->branchLength && branch != nullptr; i++){
            branch = &this->branches[i];
            if(branch->getBranchId() == branchId){
                break;
            }
        }
        if(branch == nullptr){
            cout << "Branch " << branchId << " does not exist" << endl;
            return;
        }
        cout << branch->to_string() << endl;
    }
    void BankingSystem::showCustomer ( const int customerId ){
        //search whether the customer exists with the given id
        Customer* customer = &this->customers[0];
        for(int i = 0; i < this->customerLength && customer != nullptr; i++){
            customer = &this->customers[i];
            if(customer->getId() == customerId){
                break;
            }
        }
        if(customer == nullptr){
            cout << "Customer " << customerId << " does not exist" << endl;
            return;
        }
        cout << customer->to_string() << endl;
    }
    int BankingSystem::customerCount = 0;
    int BankingSystem::branchCount = 0;
/*
private:
    int branchLength = 8;
    int customerLength = 8;
    Branch* branches = new Branch[branchLength];
    Customer* customers = new Customer[customerLength];*/
