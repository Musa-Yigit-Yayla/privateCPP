#include <iostream>
using namespace std ;
#include "BankingSystem.h"

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
int main () {
/*cout << "Hey0" << endl;
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
B . showCustomer ( 4567 ) ;*/

test3();
return 0;
}
/*Outputs

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



*/
