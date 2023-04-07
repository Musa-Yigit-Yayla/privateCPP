/*
*Musa Yiğit Yayla
*22003108
*CS201-1
*HW1
*/
#include "Customer.h"
#include "Account.h"
#include "Branch.h"
#include <string>
#include <iostream>
#include <cstdio>
#include <string_view>



using namespace std;
//public:

    Customer::Customer(const int customerId, const string customerName){
        this->accounts = new Account[this->accountsLength];
        this->accountPointers = new Account*[this->accountsLength];
        if(!this->isCustomerCreated){
            this->customerCount = 0;
            this->isCustomerCreated = true;
        }
        this->customerId = customerId;
        this->customerName = customerName;
        this->customerCount++;
    }
    Customer::Customer(){
        /*this->accounts = new Account[this->accountsLength];
        this->accountPointers = new Account*[this->accountsLength];
        if(!this->isCustomerCreated){
            this->customerCount = 0;
            this->isCustomerCreated = true;
        }*/
        this->customerCount++;
    }
    Customer::~Customer(){
        //You may have to remove the below for loop if an error occurs !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        /*for(int i = 0; i < this->accountsLength; i++){
            Account* currAccount = &this->accounts[i];
            Account* currAccountPointer = this->accountPointers[i];
            Branch* currBranch = nullptr;
            if(currAccountPointer != nullptr){
                currBranch = currAccount->getBranch();
            }
            if(currBranch != nullptr){
                currBranch->deleteAccount(currAccount->getId());
            }
        }*/
        delete[] this->accounts;
        delete[] this->accountPointers;
        this->accounts = nullptr;
        this->accountPointers = nullptr;
        //this->customerCount--;
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
        //this->accounts[this->accountCount++] = acc;

        //check whether we have an empty Account array in this customer
        if(this->accountCount == 0){
            delete[] this->accounts;
            delete[] this->accountPointers;

            //we have got no previous account so just  add this account and return
            Account* accounts = new Account[1]{acc};
            Account** accountPointers = new Account*[1]{&acc};
            this->accounts = accounts;
            this->accountPointers = accountPointers;
            this->accountCount++;
            return;
        }

        Account* newAccounts = new Account[this->accountsLength + 1];
            Account** newAccountPointers = new Account*[this->accountsLength + 1];
            for(int i = 0; i < this->accountsLength; i++){
                newAccounts[i] = this->accounts[i];
                newAccountPointers[i] = this->accountPointers[i];
            }
            //add to the end
            newAccounts[this->accountsLength] = acc;
            newAccountPointers[this->accountsLength] = &acc;
            //this->accountCount++;
            this->accounts = nullptr;
            delete[] this->accountPointers;

            this->accounts = newAccounts;
            this->accountPointers = newAccountPointers;
            this->accountsLength++;
            this->accountCount++;

            newAccounts = nullptr;
            newAccountPointers = nullptr;
    }
    //Is not a standalone function, invoked from Branch::deleteAccount
    //Removes the given account from the array by shifting elements by left once. Does not delete the account
    //Returns the accountId if deletion successful, else returns -1
    int Customer::deleteAccount(const int accountId){
        /*Account* account = &this->accounts[0];
        int result = -1;
        int i = 0;
        while(i < this->accountsLength && account != nullptr){
            if(account->getId() == accountId){
                result = accountId;
                break;
            }
            i++;
            account = &this->accounts[i];
        }
        if(result != -1){
            while(i < this->accountsLength - 1){
                this->accounts[i] = this->accounts[i + 1];
                this->accountPointers[i] = this->accountPointers[i + 1];
                i++;
            }
            //this->accounts[i] = nullptr;
            this->accountPointers[i] = nullptr;
            this->accountCount--;
        }
        return result;*/


        Account* account = &this->accounts[0];
        Account* accountPointer = this->accountPointers[0];
        int result = -1;
        /*for(int i = 1; i < this->accountsLength && account != nullptr; i++){
            //Account* curr = &this->accounts[i];
            Account* curr = this->accountPointers[i];
            if(curr != nullptr && curr->getId() == accountId){
                result = accountId;
                break;
            }
        }*/


        if(accountPointer != nullptr){
            //Then delete the actual account
            Account* newAccounts = new Account[this->accountsLength - 1];
            Account** newAccountPointers = new Account*[this->accountsLength - 1];
            int i = 0;
            int counter = 0;
            while(i < this->accountsLength && counter < this->accountsLength && accountPointer != nullptr){
                account = &this->accounts[i];
                accountPointer = this->accountPointers[i];
                int id = account->getId();
                if(id == accountId){
                    //delete account;
                    //Customer* customer = account->getCustomer();
                    //customer->deleteAccount(accountId);
                    //cout << "Account " << accountId << " has been deleted" << endl;
                    result = accountId;
                }
                else{
                    newAccounts[counter] = this->accounts[i];
                    newAccountPointers[counter++] = this->accountPointers[i];
                }
                i++;
            }
            if(result != -1){
                this->accounts = newAccounts;
                this->accountPointers = newAccountPointers;
                this->accountCount--;
            }
        }
        return result;
    }
    Account* Customer::getAllAccounts() const{
        return this->accounts;
    }
    Account** Customer::getAllAccountPointers() const{
        return this->accountPointers;
    }
    int Customer::getCustomerCount() const{
        return this->customerCount;
    }
    int Customer::getAccountCount() const{
        return this->accountsLength;
    }
    string Customer::to_string(){
        //char buffer1[100];
        string result = "";
        //string s = "%-13s%-7d%-15s%-19sNumber of accounts: ";
        //sprintf(s, "Customer id:", "" + this->customerId, "Customer name:", this->customerName);
        //string s = "%-13s%-7d%-15s%-19sNumber of accounts: "; // 74 chars
        /*for(int i = 0; i < s.size(); i++){
            buffer1[i] = s.at(i);
        }*/
        string s = "Customer id: " + std::to_string(this->customerId) + " Customer name: " + this->customerName + " Number of accounts: " + std::to_string(this->accountCount) + "\n"; //Might be problematic
        //s += std::to_string(this->accountCount);
        result += s;
        /*sprintf(buffer1, "Customer id:", "" + this->customerId, "Customer name:", this->customerName);
        string s1 = "" + std::to_string(this->accountCount) + "\n";
        for(int i = 74; i < s1.size() + 74; i++){// Mıght be problematic, CHANGE THIS IF YOU CHANGE string s
            buffer1[i] += s1.at(i - 74);
        }
        //add the buffer1 to the result
        for(int i = 0; i < s1.size() + 74; i++){
            result += buffer1[i];
        }*/
        /*Account* account = &this->accounts[0];
        Account* accountPointer = this->accountPointers[0];
        if(accountPointer != nullptr){
            int accountCounter = account->getAccountCount();
            //this->accountCount = accountCounter;
        }*/
        if(this->accountCount != 0){
            //s += "Accounts of this customer:\n";
            for(int i = 0; i < this->accountCount; i++){
                string line = " ";
                //char buffer2[100];
                if(i == 0){
                    //line = "%-12s%-16s%-20sBalance\n"; //57 chars
                    line = "Accounts of this customer:\n";
                    line += "Account id Branch id Branch Name Balance\n";
                    /*for(int j = 0; i < line.size(); i++){
                        buffer2[j] = line.at(j);
                    }
                    sprintf(buffer2, "Account id", "Branch id", "Branch name");
                    for(int j = 0; j < 57; j++){
                        result += buffer2[j];
                    }*/
                }
                //CONTINUE FROM HERE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                //char buffer3[100];
                string balanceString = Branch::getBalanceString(this->accounts[i].getBalance());
                /*string formatString = "%-12d%-16d%-20s";
                line = formatString + balanceString + "\n";
                char format[48];
                for(int j = 0; j < 48; j++){
                    format[j] = formatString.at(j);
                }
                char buffer3[100];
                for(int j = 0; j < line.size(); j++){
                    buffer3[j] = line.at(j);
                }*/

                //sprintf(buffer3, format, this->accounts[i].getId(), this->accounts[i].getBranch()->getBranchId(), this->accounts[i].getBranch()->getBranchName());
                //THE ABOVE LINE MIGHT BE PROBLEMATIC BE CAUTIOUS
                if(line != " "){
                    s += line;
                }
                string accountIdString = std::to_string(this->accounts[i].getId());
                string branchIdString = std::to_string(this->accounts[i].getBranch()->getBranchId());
                s += accountIdString + " " + branchIdString + " " + this->accounts[i].getBranch()->getBranchName() + " " + balanceString + "\n";
            }
        }
        return s;
    }
    int Customer::customerCount = 0;
    bool Customer::isCustomerCreated = false;
    //int Account::accountsCreated = 0;
    //bool Account::isAccountCreated = false;
    //int Account::accountCount = 0;
/*private:
    int customerId;
    string customerName;
    int accountsLength = 8;
    Account* accounts = new Account(accountsLength);
    static int customerCount = 0;*/
