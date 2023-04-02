#include <iostream>
using namespace std ;
#include "BankingSystem.h"

void test0(){
    cout << "Hey0" << endl;
    BankingSystem B ;
    cout << "Hey1" << endl;
    B . addBranch ( 1451 , " Bilkent " ) ;
    cout << "Hey2" << endl;
    B . addBranch ( 2435 , " Kizilay " ) ;
    cout << "Hey3" << endl;
    B . addBranch ( 1672 , " Bahcelievler " ) ;
    B . addBranch ( 3216 , " Ulus " ) ;
    B . addBranch ( 2435 , " Kizilay " ) ;
    B . deleteBranch ( 1672 ) ;
    B . deleteBranch ( 1723 ) ;
    B . addBranch ( 9876 , " Umitkoy " ) ;
    cout << endl;
    B . addCustomer ( 1234 , "Ali Ak" ) ;
    B . addCustomer ( 4567 , " Aynur Dayanik " ) ;
    B . addCustomer ( 891234 , " Cihan Erkan " ) ;
    B . addCustomer ( 891234 , " Hakan Karaca " ) ;
    B . addCustomer ( 5678 , " Mustafa Gundogan " ) ;
    B . addCustomer ( 8901 , "Can Kara " ) ;
    B . deleteCustomer ( 5678 ) ;
    B . deleteCustomer ( 1267 ) ;
    cout << endl;
    int account1 = B . addAccount ( 1451 , 4567 , 100.00 ) ;
    int account2 = B . addAccount ( 1451 , 1234 , 200.00 ) ;
    int account3 = B . addAccount ( 3216 , 4567 , 300.00 ) ;
    int account4 = B . addAccount ( 1451 , 4567 , 1000.00 ) ;
    int account5 = B . addAccount ( 1672 , 8901 , 100.00 ) ;
    int account6 = B . addAccount ( 2435 , 5678 , 100.00 ) ;
    int account7 = B . addAccount ( 3216 , 1234 , 500.00 ) ;
    B . deleteAccount ( account2 ) ;
    B . deleteAccount ( account5 ) ;
    B . deleteAccount ( account7 ) ;
    int account8 = B . addAccount ( 2435 , 891234 , 500.00 ) ;
    cout << endl;
    B . showAllAccounts () ;
    B . showBranch ( 1451 ) ;
    B . showBranch ( 1672 ) ;
    B . showBranch ( 9876 ) ;
    B . showCustomer ( 1234 ) ;
    B . showCustomer ( 4567 ) ;
    B . showCustomer ( 1212 ) ;
    B . deleteBranch ( 1451 ) ;
    B . showCustomer ( 4567 ) ;
}

void test1(){
    BankingSystem B;

    B.addBranch(1, "1");
    B.addBranch(2, "2");
    B.addBranch(3, "3");
    B.deleteBranch(1);
    B.deleteBranch(3);
    B.deleteBranch(3);
    B.deleteBranch(2);
    B.deleteBranch(2);
    B.addBranch(1, "1");
    B.addBranch(2, "2");
    B.addBranch(3, "3");
    B.addBranch(1, "1");
    B.addBranch(2, "2");
    B.addBranch(3, "3");

}
void test2(){
    BankingSystem B;
    B.addCustomer(1, "1");
    B.addCustomer(2, "2");
    B.addCustomer(3, "3");
    B.addCustomer(3, "3");
    B.addCustomer(4, "3");
    B.deleteCustomer(4);
    B.deleteCustomer(4);
    B.deleteCustomer(1);
    B.deleteCustomer(2);
    B.deleteCustomer(3);
    B.addCustomer(1, "1");
    B.addCustomer(2, "2");
    B.addCustomer(3, "3");
    B.addCustomer(1, "1");
    B.addCustomer(2, "2");
    B.addCustomer(3, "3");
    B.deleteCustomer(3);
    B.deleteCustomer(2);
    B.deleteCustomer(1);
    B.deleteCustomer(3);
    B.deleteCustomer(2);
    B.deleteCustomer(1);
}
void test3(){
    BankingSystem B;
    B.addCustomer(1, "1");
    B.addBranch(1, "1");
    int acc1 = B.addAccount(1, 1, 100);
    int acc2 = B.addAccount(1, 1, 100);
    int acc3 = B.addAccount(1, 1, 100);
    int acc = B.addAccount(2,2,100);
    B.deleteAccount(acc);
    B.deleteAccount(1);
    B.deleteAccount(2);
    B.deleteAccount(3);
    B.deleteAccount(1);
    B.deleteAccount(2);
    B.deleteAccount(3);
    int acc4 = B.addAccount(1, 1, 100);
    int acc5 = B.addAccount(1, 1, 100);
    int acc6 = B.addAccount(1, 1, 100);
    B.deleteAccount(6);
    B.deleteAccount(5);
    B.deleteAccount(4);
    int acc7 = B.addAccount(1,2,100);
    int acc8 = B.addAccount(2,1,100);

}
void test4(){
    BankingSystem B;
    B.showAllAccounts();
    B.showCustomer(1);
    B.showBranch(1);
    B.addCustomer(1, "c1");
    B.showCustomer(1);
    B.addBranch(10, "b10");
    B.showBranch(10);
    B.addBranch(11, "b11");
    B.addCustomer(2, "c2");
    int acc1 = B.addAccount(11, 1, 100);
    int acc2 = B.addAccount(11, 1, 200);
    int acc3 = B.addAccount(11, 2, 300);
    int acc4 = B.addAccount(11, 2, 400);
    int acc5 = B.addAccount(10, 1, 500);
    int acc6 = B.addAccount(10, 1, 600);
    int acc7 = B.addAccount(10, 2, 700);
    int acc8 = B.addAccount(10, 2, 800);
    B.showAllAccounts();
    B.showBranch(10);
    B.showBranch(11);
    B.showCustomer(1);
    B.showCustomer(2);
    B.deleteBranch(11);
    B.showCustomer(1);
    B.showCustomer(2);
    B.showAllAccounts();

}
int main () {


test0();
return 0;
}
/*Outputs

Test 1
Branch 1 has been added
Branch 2 has been added
Branch 3 has been added
Branch 1 has been deleted
Branch 3 has been deleted
Branch 3 does not exist
Branch 2 has been deleted
Branch 2 does not exist
Branch 1 has been added
Branch 2 has been added
Branch 3 has been added
Branch 1 already exists
Branch 2 already exists
Branch 3 already exists

Test 2
Customer 1 has been added
Customer 2 has been added
Customer 3 has been added
Customer 3 already exists
Customer 4 has been added
Customer 4 has been deleted
Customer 4 does not exist
Customer 1 has been deleted
Customer 2 has been deleted
Customer 3 has been deleted
Customer 1 has been added
Customer 2 has been added
Customer 3 has been added
Customer 1 already exists
Customer 2 already exists
Customer 3 already exists
Customer 3 has been deleted
Customer 2 has been deleted
Customer 1 has been deleted
Customer 3 does not exist
Customer 2 does not exist
Customer 1 does not exist


Test 3
Customer 1 has been added
Branch 1 has been added
Account 1 added for customer 1 at branch 1
Account 2 added for customer 1 at branch 1
Account 3 added for customer 1 at branch 1
Branch 2 does not exist
Account -1 does not exist
Account 1 has been deleted
Account 2 has been deleted
Account 3 has been deleted
Account 1 does not exist
Account 2 does not exist
Account 3 does not exist
Account 4 added for customer 1 at branch 1
Account 5 added for customer 1 at branch 1
Account 6 added for customer 1 at branch 1
Account 6 has been deleted
Account 5 has been deleted
Account 4 has been deleted
Customer 2 does not exist
Branch 2 does not exist

Test 4
Account id Branch id Branch name Customer id Customer name Balance
Customer 1 does not exist
Branch 1 does not exist
Customer 1 has been added
Customer id: 1 Customer name: c1 Number of accounts: 0
Branch 10 has been added
Branch id: 10 Branch name: b10 Number of accounts: 0
Branch 11 has been added
Customer 2 has been added
Account 1 added for customer 1 at branch 11
Account 2 added for customer 1 at branch 11
Account 3 added for customer 2 at branch 11
Account 4 added for customer 2 at branch 11
Account 5 added for customer 1 at branch 10
Account 6 added for customer 1 at branch 10
Account 7 added for customer 2 at branch 10
Account 8 added for customer 2 at branch 10
Account id Branch id Branch name Customer id Customer name Balance
1 11 b11 1 c1 100.00
2 11 b11 1 c1 200.00
3 11 b11 2 c2 300.00
4 11 b11 2 c2 400.00
5 10 b10 1 c1 500.00
6 10 b10 1 c1 600.00
7 10 b10 2 c2 700.00
8 10 b10 2 c2 800.00
Branch id: 10 Branch name: b10 Number of accounts: 4
Accounts at this branch:
Account id Customer id Customer name Balance
5 1 c1 500.00
6 1 c1 600.00
7 2 c2 700.00
8 2 c2 800.00
Branch id: 11 Branch name: b11 Number of accounts: 4
Accounts at this branch:
Account id Customer id Customer name Balance
1 1 c1 100.00
2 1 c1 200.00
3 2 c2 300.00
4 2 c2 400.00
Customer id: 1 Customer name: c1 Number of accounts: 4
Accounts of this customer:
Account id Branch id Branch name Balance
1 11 b11 100.00
2 11 b11 200.00
5 10 b10 500.00
6 10 b10 600.00
Customer id: 2 Customer name: c2 Number of accounts: 4
Accounts of this customer:
Account id Branch id Branch name Balance
3 11 b11 300.00
4 11 b11 400.00
7 10 b10 700.00
8 10 b10 800.00
Branch 11 has been deleted
Customer id: 1 Customer name: c1 Number of accounts: 2
Accounts of this customer:
Account id Branch id Branch name Balance
5 10 b10 500.00
6 10 b10 600.00
Customer id: 2 Customer name: c2 Number of accounts: 2
Accounts of this customer:
Account id Branch id Branch name Balance
7 10 b10 700.00
8 10 b10 800.00
Account id Branch id Branch name Customer id Customer name Balance
5 10 b10 1 c1 500.00
6 10 b10 1 c1 600.00
7 10 b10 2 c2 700.00
8 10 b10 2 c2 800.00



*/
