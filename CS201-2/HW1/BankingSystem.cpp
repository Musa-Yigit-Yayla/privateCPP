/*
*Musa Yiğit Yayla
*22003108
*CS201-1
*HW1
*/
#include "BankingSystem.h"
#include "Branch.h"
#include "Customer.h"
#include "Account.h"
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>

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
        if(this->branches != NULL && this->branchPointers != NULL){
            delete[] this->branches;
            delete[] this->branchPointers;
        }
        if(this->customers != NULL && this->customerPointers != NULL){
            delete[] this->customers;
            delete[] this->customerPointers;
        }
        this->branches = nullptr;
        this->branchPointers = nullptr;
        this->customers = nullptr;
        this->customerPointers = nullptr;
    }
    void BankingSystem::addBranch ( const int branchId , const string branchName ){

        //First check if a branch with the given ID already exists
        //bool isBranchFound = false;
        Branch* curr = nullptr;
        for(int i = 0; i < this->branchLength; i++){
            curr = &this->branches[i];
            Branch* branchPtr = this->branchPointers[i];
            int currBranchId;
            if(curr == NULL || branchPtr == NULL || this->branchCount == 0){
                //delete curr;
                break;
            }
            currBranchId = curr->getBranchId();
            int branchCount = this->branchCount;
            int branchLength = this->branchLength;
            if(!((this->branchCount == 1 && this->branchLength == 2) || !(currBranchId == branchId))){//if(currBranchId == branchId){
                //curr = nullptr; // REMOVE FROM THE COMMENT IF PROBLEM OCCURS !!!!!!!!!!!!!!!!!!!!!!!!!
                cout << "Branch " << branchId << " already exists" << endl;
                return;
            }
            //delete curr;
        }
        //curr = nullptr; //remove curr pointer

        Branch* branch = new Branch(branchId, branchName);
        Branch* ptr = this->branchPointers[0];

        while(ptr != NULL && ptr - this->branchPointers[0] < this->branchCount && ptr - this->branchPointers[0] < this->branchLength){
            ptr++;
        }
        if(this->branchLength == 1 && ptr == NULL){ // CHANGE TO branch == nullptr the second loop continuation condition ptr == nullptr yap branchCount u
            //We are adding the first Account to the branch :)
            this->branches[0] = *branch;
            this->branchPointers[0] = branch;
            this->branchCount++;
            //this->branchCount = 0;
            cout << "Branch " << branchId << " has been added" << endl;

            //Remove below line if problem occurs !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            //branch = nullptr;
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
                newBranchPointers[i] = &newBranches[i];
            }
            //Make the addition then set the rest to nullptr
            newBranches[branchLength] = *branch;
            newBranchPointers[branchLength] = branch;
            this->branchCount++;            //this->branchCount = 0;
            cout << "Branch " << branchId << " has been added" << endl;

            /*for(int i = this->branchLength + 1; i < this->branchLength * 2; i++){
                 (newBranchPointers[i]) = nullptr;
            }*/
            branch = nullptr;
            ptr = nullptr;

            this->branches = nullptr;
            delete[] this->branchPointers;

            this->branches = newBranches;
            this->branchPointers = newBranchPointers;
            this->branchLength += 1;

            newBranches = nullptr;
            newBranchPointers = nullptr;
        }
        //delete ptr;
        //}
        //else{
            //this->branches[ptr - this->branches] = branch;
            //this->branchPointers[ptr - this->branches] = &branch;
            //cout << "Branch " << branchId << " has been added" << endl;
        //}
    }
    void BankingSystem::deleteBranch ( const int branchId ){
        bool isDeleted = false;
        /*bool branchExists = false;
        //initially check whether we don't have the given branch
        for(int i = 0; i < this->branchLength; i++){
            Branch currBranch = this->branches[i];
            if(currBranch.getBranchId() == branchId){
                branchExists = true;
                break;
            }
        }
        if(!branchExists){
            cout << "Branch " << branchId << " does not exist" << endl;
            return;
        }*/

        //Initially we handle the case where our branchLength is 1, hence we have only 1 branch or no branches
        if(this->branchLength == 1){
            int branchCount = this->branchCount;
            if(this->branchCount <= 0){ //CHANGE BACK TO == 0 IF PROBLEM OCCURS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                cout << "Branch " << branchId << " does not exist" << endl;
            }

            else{
                Branch* currBranch = &this->branches[0];
                    if(currBranch->getBranchId() == branchId){
                        //delete currBranch;
                        //delete (&this->branches[i]); // might be problematic but it should work fine
                        isDeleted = true;
                        //this->branchCount--;
                        Account* accounts = currBranch->getAllAccounts();
                        int accountLength = currBranch->getAccountCount();
                        for(int i = 0; i < accountLength && currBranch->getAccountCount() > 0; i++){
                            int accountId = accounts[i].getId();
                            this->deleteAccount(accountId, true);
                        }
                        cout << "Branch " << branchId << " has been deleted" << endl;
                        if(this->branchLength > 1)
                         this->branchLength -= 1;
                        this->branchCount--;
                        currBranch = nullptr;
                        accounts = nullptr;
                    }
                    else
                        cout << "Branch " << branchId << " does not exist" << endl;
            }
            return;
        }


        Branch* newBranches = new Branch[this->branchLength - 1];
        Branch** newBranchPointers = new Branch*[this->branchLength - 1];
        Branch* currBranch = &this->branches[0];
        int counter = 0; // counter representing newBranches index
        // add this to loop continuation condition if problem occurs counter < this->branchLength - 1  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        for(int i = 0; i < this->branchLength && counter <= this->branchLength - 1 && currBranch != NULL; i++){
            currBranch = &this->branches[i];
            //int id = currBranch->getBranchId();
            if(currBranch->getBranchId() == branchId){
                //delete currBranch;
                //delete (&this->branches[i]); // might be problematic but it should work fine
                isDeleted = true;
                //this->branchCount--;
                Account* accounts = currBranch->getAllAccounts();
                int accountLength = currBranch->getAccountCount();
                for(int i = 0; i < accountLength && currBranch->getAccountCount() > 0; i++){
                    int accountId = accounts[i].getId();
                    this->deleteAccount(accountId, true);
                }
                cout << "Branch " << branchId << " has been deleted" << endl;
            }
            else if(counter < this->branchLength - 1){
                //Add the branch to the newBranches
                newBranches[counter] = this->branches[i];
                newBranchPointers[counter++] = &this->branches[i];
                //cout << "Branch with id " << this->branches[i].getBranchId() << " added to the newBranches xddddddddddd" << endl;
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
        currBranch = nullptr; //remove the pointer of currBranch
        if(!isDeleted){
            cout << "Branch " << branchId << " does not exist" << endl;
            delete[] newBranchPointers;
            newBranches = nullptr;
        }
        else{
            this->branches = nullptr;
            delete[] this->branchPointers;
            //REMOVE BELOW TWO LINES FOR PROGRAM TO EXECUTE FURTHER!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            this->branches = newBranches;
            this->branchPointers = newBranchPointers;

            newBranches = nullptr;
            newBranchPointers = nullptr;

            if(this->branchLength > 1)
                this->branchLength -= 1;
            this->branchCount--;
        }

    }
    void BankingSystem::addCustomer ( const int customerId , const string customerName ){
        //Initially check whether a customer with the given Id exists
        for(int i = 0; i < this->customerLength; i++){
            Customer* curr = this->customerPointers[i];
            if(curr == NULL){
                break;
            }
            else if(curr->getId() == customerId){
                curr = nullptr;
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

            customer = nullptr;
            ptr = nullptr;
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

            this->customers = nullptr;
            delete[] this->customerPointers;

            this->customerCount++;
            this->customers = newCustomers;
            this->customerPointers = newCustomerPointers;
            this->customerLength += 1;

            newCustomers = nullptr;
            newCustomerPointers = nullptr;
            customer = nullptr;
            ptr = nullptr;
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

        //Initially we handle the case where our customerLength is 1, hence we have only 1 customer or no customers
        if(this->customerLength == 1){
            if(this->customerCount == 0){
                cout << "Customer " << customerId << " does not exist" << endl;
            }
            else{
                Customer* currCustomer = &this->customers[0];
                    if(currCustomer->getId() == customerId){
                        //delete currBranch;
                        //delete (&this->branches[i]); // might be problematic but it should work fine
                        isDeleted = true;
                        //this->branchCount--;
                        Account* accounts = currCustomer->getAllAccounts();
                        int accountLength = currCustomer->getAccountCount();
                        for(int i = 0; i < accountLength && currCustomer->getAccountCount() > 0; i++){
                            int accountId = accounts[i].getId();
                            //this->deleteAccount(accountId, true); REMOVE THIS LINE IF YOU FACE ANY PROBLEMS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                        }
                        cout << "Customer " << customerId << " has been deleted" << endl;
                        if(this->customerLength > 1)
                         this->customerLength -= 1;
                        this->customerCount--;
                        currCustomer = nullptr;
                        accounts = nullptr;
                        //check whether we have to reset the customers array
                        if(this->customerCount == 0){
                            delete[] this->customers;
                            delete[] this->customerPointers; //might be problematic!!!!!

                            this->customers = new Customer[this->customerLength];
                            this->customerPointers = new Customer*[this->customerLength];
                            for(int i = 0; i < customerLength; i++){
                                (this->customerPointers[i]) = nullptr;
                            }
                        }
                    }
                    else{
                        cout << "Customer " << customerId << " does not exist" << endl;
                    }
            }
            return;
        }

        Customer* newCustomers = nullptr; //= new Customer[this->customerLength - 1];
        Customer** newCustomerPointers = nullptr; //= new Customer*[this->customerLength - 1];


        newCustomers = new Customer[this->customerLength - 1];
        newCustomerPointers = new Customer*[this->customerLength - 1];

        int counter = 0;
        //int iValue; // value to hold i
        for(int i = 0; i < this->customerLength && counter < this->customerLength - 1; i++){ // switch counter <= this->cusLen - 1 to < this->cusLen - 1 !!!!!!!!!!!!!!!!!!!!!!!!!!
            Customer* currCustomer = &this->customers[i];
            Customer* currCustomerPointer = this->customerPointers[i];
            //iValue = i;
            //int id = currCustomer->getId();
            int currId = currCustomer->getId();
            if(currCustomerPointer != NULL && currCustomer->getId() == customerId){
                //delete &this->customers[i];
                //delete this->customerPointers[i];
                //this->customerCount--;
                /*Account* accounts = currCustomer->getAllAccounts();
                int accountLength = currCustomer->getAccountCount();
                for(int i = 0; i < accountLength; i++){
                    int accountId = accounts[i].getId();
                    this->deleteAccount(accountId);
                }*/

                cout << "Customer " << customerId << " has been deleted" << endl;
                isDeleted = true;
            }
            else if(currCustomerPointer != NULL){
                newCustomers[counter] = this->customers[i];
                newCustomerPointers[counter++] = &this->customers[i];
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
        if(counter == this->customerLength - 1 && !isDeleted){
            //that means that we have either disregarded the customer with the given id or it does not exist
            Customer* lastCustomer = &this->customers[counter];
            if(lastCustomer->getId() == customerId){
                cout << "Customer " << customerId << " has been deleted" << endl;
                isDeleted = true;
            }
            else{
                isDeleted = false;
            }
        }
        if(!isDeleted){
            newCustomers = nullptr;
            delete[] newCustomerPointers;
            cout << "Customer " << customerId << " does not exist" << endl;
        }
        else{
            this->customers = nullptr;
            delete[] this->customerPointers;

            this->customers = newCustomers;
            this->customerPointers = newCustomerPointers;

            newCustomers = nullptr;
            newCustomerPointers = nullptr;

            if(this->customerLength > 1)
                this->customerLength -= 1;

            this->customerCount--;
        }
    }
    int BankingSystem::addAccount ( const int branchId , const int customerId , const double amount ){
        Branch* branch = nullptr;
        Customer* customer = nullptr;
        bool branchExists = false;
        for(int i = 0; i < this->branchLength; i++){
            Branch* currBranch = &this->branches[i];
            Branch* currBranchPointer = this->branchPointers[i];
            if(currBranchPointer ==  NULL){
                break;
            }
            if(currBranch->getBranchId() == branchId){
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
            //if(currCustomer == nullptr){
                //break;
            //}
            if(currCustomer->getId() == customerId){
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
        Account* account = new Account(amount, *branch, *customer); // revert to normal account declaration if problem occurs !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        branch->addAccount(*account);
        customer->addAccount(*account);
        cout << "Account " << account->getId() << " added for customer " << account->getCustomer()->getId() << " at branch " << branch->getBranchId() << endl;
        return account->getId();
    }
    void BankingSystem::deleteAccount ( const int accountId, bool isBranchOrCustomerDeleted){
        //Account* account;
        bool isDeleted = false;
        Branch* branch = &this->branches[0];
        Branch* branchPointer = this->branchPointers[0];
        int i = 0;
        while(i < this->branchLength && branchPointer != NULL){
            branch = &this->branches[i];
            branchPointer = this->branchPointers[i];
            Account* account = branch->getAccount(accountId);
            Account* accountPointer = branch->getAccountPointer(accountId);
            bool isAccountNull = (accountPointer == NULL);
            //cout << "Branch id is " << branch->getBranchId() << endl;
            if(!isAccountNull && account->getId() == accountId){
                isDeleted = true;
                branch->deleteAccount(accountId, isBranchOrCustomerDeleted);
                break;
            }

            i++;
        }
        if(!isDeleted && !isBranchOrCustomerDeleted){
            cout << "Account " << accountId << " does not exist" << endl;
        }
        //Get the branch and the customer of the account if exists
        branch = nullptr;
        branchPointer = nullptr;
    }
    void BankingSystem::showAllAccounts() {
        //Account id Branch id Branch name Customer id Customer name Balance
        //printf("%-12s%-12s%-16s%-16s%-27sBalance\n", "Account id", "Branch id", "Branch name", "Customer id", "Customer name" );
        cout << "Account id " << "Branch id " << "Branch name " << "Customer id " << "Customer name " << "Balance" << endl;
        Account* accounts = nullptr;
        Account** accountPointers = nullptr;
        int totalAccountLength = 0;
        Customer* currCustomer = &this->customers[0];
        Customer* currCustomerPointer = this->customerPointers[0];

        //Loop through customers to retrieve all accounts so we can sort them in ascending order
        for(int i = 0; i < this->customerLength && i < this->customerCount; i++){
            currCustomer = &this->customers[i];
            if(i == 0){
                accounts = currCustomer->getAllAccounts();
                accountPointers = currCustomer->getAllAccountPointers();
                int currAccountLength = currCustomer->getAccountCount();
                totalAccountLength += currAccountLength;
                continue;
            }
            int currAccountLength = currCustomer->getAccountCount();
            Account* newAccounts = currCustomer->getAllAccounts();
            Account** newAccountPointers = currCustomer->getAllAccountPointers();
            int initialTotalAccountLength = totalAccountLength;
            totalAccountLength += currAccountLength;

            Account* prevAccounts; //= nullptr;
            prevAccounts = accounts;
            Account** prevAccountPointers; //= nullptr;
            prevAccountPointers = accountPointers;

            accounts = new Account[totalAccountLength];
            accountPointers = new Account*[totalAccountLength];
            int j = 0;
            while(j < totalAccountLength - currAccountLength){
                accounts[j] = prevAccounts[j];
                accountPointers[j] = prevAccountPointers[j];
                j++;
            }
            while(j < totalAccountLength){
                accounts[j] = newAccounts[j - (totalAccountLength - currAccountLength)]; //+ totalAccountLength - initialTotalAccountLength]; // might be problematic
                accountPointers[j] = newAccountPointers[j - (totalAccountLength - currAccountLength)]; //+ totalAccountLength - initialTotalAccountLength];
                j++;
            }

        }
        //display accounts for testing
        /*for(int i = 0; i < totalAccountLength; i++){
            cout << "Account id: " << accounts[i].getId() << endl;
        }*/
        //sort each account before displaying
        accounts[0].sortAllAccounts(accounts, accountPointers, totalAccountLength);

        //display each account

        Account* currAccount = &accounts[0];
        //Account* currAccountPointer = accountPointers[0];
            for(int j = 0; j < totalAccountLength && currAccount != NULL; j++){
                currAccount = &accounts[j];
                Account* currAccountPointer = accountPointers[j];
                Branch* currBranch = nullptr;
                Branch* currBranchPointer = nullptr;
                //Branch* currBranchPointer = currCustomer->
                if(currAccountPointer != NULL){
                    currBranch = currAccount->getBranch();
                    currCustomer = currAccount->getCustomer();
                    //find currBranchPointer
                }
                if(currAccountPointer != NULL && currBranch != NULL){
                    //Branch* currBranch = currAccount->getBranch();
                    int accountId = currAccount->getId();
                    //Branch* currBranch = currAccount->getBranch();
                    /*if(accountId <= 0){ //IF YOU FACE ANY PROBLEMS REMOVE THIS IF !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                        continue;
                    }*/
                    if(accountId <= 0){ // YOU MAY HAVE TO REMOVE THIS !!!!!!!!!!!!!!!!!!
                        continue;
                    }
                    double balance = currAccount->getBalance();
                    string balanceString = "" + Branch::getBalanceString(balance);
                    string accountIdString = "" + std::to_string(currAccount->getId());
                    string branchIdString = "" + std::to_string(currBranch->getBranchId());
                    string customerIdString = "" + std::to_string(currCustomer->getId());
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
                    cout << accountIdString << " " << branchIdString << " " << currBranch->getBranchName() << " " << customerIdString << " " << currCustomer->getCustomerName() << " " << balanceString << endl;
                }
            }


        /*for(int i = 0; i < this->customerLength && i < this->customerCount; i++){
            Customer* currCustomer = &this->customers[i];
            Customer* currCustomerPointer = this->customerPointers[i];
            if(currCustomer != nullptr){
                Account* accounts = currCustomer->getAllAccounts();
                Account** accountPointers = currCustomer->getAllAccountPointers();
                int accountLength = currCustomer->getAccountCount();
                Account* currAccount = &accounts[0];
                for(int j = 0; j < accountLength && currAccount != nullptr; j++){
                    currAccount = &accounts[j];
                    Account* currAccountPointer = accountPointers[j];
                    Branch* currBranch;
                    //Branch* currBranchPointer = currCustomer->
                    if(currAccountPointer != nullptr){
                        currBranch = currAccount->getBranch();
                        //currBranchPointer
                    }
                    if(currAccountPointer != nullptr && currBranch != nullptr){
                        //Branch* currBranch = currAccount->getBranch();
                        int accountId = currAccount->getId();
                        //Branch* currBranch = currAccount->getBranch();
                        string balanceString = "" + std::to_string(currAccount->getBalance());
                        string accountIdString = "" + std::to_string(currAccount->getId());
                        string branchIdString = "" + std::to_string(currBranch->getBranchId());
                        string customerIdString = "" + std::to_string(currCustomer->getId());
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
                        printf( format, accountIdString, branchIdString, currBranch->getBranchName(), customerIdString, currCustomer->getCustomerName());
                        cout << accountIdString << " " << branchIdString << " " << currBranch->getBranchName() << " " << customerIdString << " " << currCustomer->getCustomerName() << " " << balanceString << endl;
                    }
                }
            }
        }*/
    }
    //If problem occurs change branchPointers to branches !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    void BankingSystem::showBranch ( const int branchId ){
        //search for the branch with the given id
        Branch* branch = this->branchPointers[0];
        //int bl = this->branchLength;
        //int bc = this->branchCount;

        bool branchFound = false;
        if(branch != NULL){
            this->branchCount = branch->getBranchCount();
        }
        for(int i = 0; i < this->branchLength && i <= this->branchCount && branch != NULL; i++){
            branch = &this->branches[i];
            if(branch->getBranchId() == branchId){
                branchFound = true;
                break;
            }
        }
        if(!branchFound){
            cout << "Branch " << branchId << " does not exist" << endl;
            return;
        }
        cout << branch->to_string();
    }
    void BankingSystem::showCustomer ( const int customerId ){
        //search whether the customer exists with the given id
        Customer* customerPointer = this->customerPointers[0];
        Customer* customer = &this->customers[0];
        bool customerFound = false;
        if(customerPointer != NULL){
            int customerCounter = customer->getCustomerCount();
            this->customerCount = customerCounter;
        }
        for(int i = 0; i < this->customerLength && i <= this->customerCount && customer != NULL; i++){
            customer = &this->customers[i];
            if(customer->getId() == customerId){
                customerFound = true;
                break;
            }
        }
        if(!customerFound){
            cout << "Customer " << customerId << " does not exist" << endl;
            return;
        }
        cout << customer->to_string();
    }

    int BankingSystem::customerCount = 0;
    int BankingSystem::branchCount = 0;
/*
private:
    int branchLength = 8;
    int customerLength = 8;
    Branch* branches = new Branch[branchLength];
    Customer* customers = new Customer[customerLength];*/
