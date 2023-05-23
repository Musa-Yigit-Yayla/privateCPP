#include "RegistrationSystem.h"
void test0(){
RegistrationSystem rs;
rs. showAllStudents ();
cout << endl ;
rs. addStudent (2000 , "Kemal", "Ak");
rs. addStudent (1000 , "Nuri", "Yazici");
rs. addStudent (4000 , "Cengiz","Erdem");
rs. addStudent (3000 , "Osman", "Top");
rs. addStudent (4000 , "Can", "Gezici");
rs. addStudent (6000 , "Can", "Gezici");
rs. addStudent (5000 , "Ali", "Akdere");
rs. addStudent (7000 , "Burcin", "Temiz");
cout << endl ;
rs. showAllStudents ();
cout << endl ;
rs. addCourse (2000 , 555 , "CS555");
rs. addCourse (2000 , 540 , "CS540");
rs. addCourse (2000 , 513 , "CS513");
rs. addCourse (2000 , 524 , "CS524");
rs. addCourse (3000 , 524 , "CS524");
rs. addCourse (3000 , 540 , "CS540");
rs. addCourse (1000 , 540 , "CS540");
rs. addCourse (1000 , 524 , "CS524");
rs. addCourse (4000 , 524 , "CS524");
rs. addCourse (4000 , 510 , "CS510");
rs. addCourse (4000 , 540 , "CS540");
rs. addCourse (4000 , 513 , "CS513");
rs. addCourse (5000 , 510 , "CS510");
rs. addCourse (5000 , 513 , "CS513");
rs. addCourse (5000 , 540 , "CS540");
rs. addCourse (6000 , 540 , "CS540");
rs. addCourse (7000 , 510 , "CS510");
rs. addCourse (7000 , 513 , "CS513");

rs. addCourse (7000 , 540 , "CS540");
rs. addCourse (3000 , 524 , "CS524");
cout << endl ;
rs. deleteStudent (5000) ;
rs. deleteStudent (5000) ;
cout << endl ;
rs. showStudent (1000) ;
rs. showStudent (3000) ;
rs. showStudent (5000) ;
cout << endl ;
rs. showAllStudents ();
cout << endl ;
rs. withdrawCourse (3000 , 524) ;
rs. withdrawCourse (2000 , 555) ;
rs. withdrawCourse (2000 , 550) ;
rs. withdrawCourse (10000 , 510) ;
cout << endl ;
rs. cancelCourse (540) ;
rs. cancelCourse (201) ;
cout << endl ;
rs. showCourse (524) ;
rs. showCourse (540) ;
rs. showStudent (7000) ;
cout << endl ;
rs. deleteStudent (7000) ;
cout << endl ;
rs. showStudent (3000) ;
cout << endl ;
rs. showAllStudents ();
cout << endl ;
}
/*
Student 2000 has been added
Student 1000 has been added
Student 4000 has been added
Student 4000 has been deleted
Student 2000 has been deleted
Student 2000 does not exist
Student 1000 has been deleted
Student 2000 has been added
Student 1000 has been added
Student 4000 has been added
Student 2000 already exists
Student 1000 already exists
Student 4000 already exists

*/
void test1(){
     RegistrationSystem rs;

    rs.addStudent(2000, "Kemal", "Ak");
    rs.addStudent(1000, "Nuri", "Yazici");
    rs.addStudent(4000, "Cengiz", "Erdem");
    rs.deleteStudent(4000);
    rs.deleteStudent(2000);
    rs.deleteStudent(2000);
    rs.deleteStudent(1000);
    rs.addStudent(2000, "Kemal", "Ak");
    rs.addStudent(1000, "Nuri", "Yazici");
    rs.addStudent(4000, "Cengiz", "Erdem");
    rs.addStudent(2000, "Kemal", "Ak");
    rs.addStudent(1000, "Nuri", "Yazici");
    rs.addStudent(4000, "Cengiz", "Erdem");
}

/*
Student 1000 has been added
Course 555 has been added to student 1000
Course 540 has been added to student 1000
Student 1000 is already enrolled in course 540
Course 513 has been added to student 1000
Student 1000 has been withdrawn from course 540
Student 1000 has been withdrawn from course 513
Student 1000 is not enrolled in course 513
Student 1000 has been withdrawn from course 555
Course 555 has been added to student 1000
Course 540 has been added to student 1000
Course 513 has been added to student 1000
Student 1000 is already enrolled in course 555
Student 1000 is already enrolled in course 540
Student 1000 is already enrolled in course 513
Student 1000 has been withdrawn from course 540
Student 1000 has been withdrawn from course 513
Student 1000 has been withdrawn from course 555
Student 1000 is not enrolled in course 540
Student 1000 is not enrolled in course 513
Student 1000 is not enrolled in course 555
*/
void test2(){
 RegistrationSystem rs;
    rs.addStudent(1000, "Kemal", "Ak");
    rs.addCourse(1000, 555, "CS555");
    rs.addCourse(1000, 540, "CS540");
    rs.addCourse(1000, 540, "CS540");
    rs.addCourse(1000, 513, "CS513");
    rs.withdrawCourse(1000, 540);
    rs.withdrawCourse(1000, 513);
    rs.withdrawCourse(1000, 513);
    rs.withdrawCourse(1000, 555);
    rs.addCourse(1000, 555, "CS555");
    rs.addCourse(1000, 540, "CS540");
    rs.addCourse(1000, 513, "CS513");
    rs.addCourse(1000, 555, "CS555");
    rs.addCourse(1000, 540, "CS540");
    rs.addCourse(1000, 513, "CS513");
    rs.withdrawCourse(1000, 540);
    rs.withdrawCourse(1000, 513);
    rs.withdrawCourse(1000, 555);
    rs.withdrawCourse(1000, 540);
    rs.withdrawCourse(1000, 513);
    rs.withdrawCourse(1000, 555);

}
//MIGHT BE PROBLEMATIC OUTPUT ASK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
Student 2000 has been added
Student 1000 has been added
Student 4000 has been added
Course 555 has been added to student 2000
Student 2000 is already enrolled in course 555
Course 540 has been added to student 2000
Course 555 has been added to student 1000
Course 520 has been added to student 1000
Course 540 has been added to student 1000
Course 540 already exists with another name
Course 540 has been added to student 4000
Student 4000 is not enrolled in course 520
Student 1000 has been withdrawn from course 520
Course 520 does not exist
Student 2000 has been withdrawn from course 540
Student 1000 has been withdrawn from course 540
Student 4000 has been withdrawn from course 540
Student 6000 does not exist
Course 540 has been added to student 4000
Course 540 already exists with another name
Course 540 has been added to student 1000
Course 540 has been cancelled
Student 1000 is not enrolled in course 540
Student 1000 is not enrolled in course 520
Student 1000 has been withdrawn from course 555
*/
void test3(){
    RegistrationSystem rs;

    rs.addStudent(2000, "Kemal", "Ak");
    rs.addStudent(1000, "Nuri", "Yazici");
    rs.addStudent(4000, "Cengiz", "Erdem");

    rs.addCourse(2000, 555, "CS555");
    rs.addCourse(2000, 555, "CS555");
    rs.addCourse(2000, 540, "CS540");

    rs.addCourse(1000, 555, "CS555");
    rs.addCourse(1000, 520, "CS520");
    rs.addCourse(1000, 540, "CS540");

    rs.addCourse(4000, 540, "CSS540");
    rs.addCourse(4000, 540, "CS540");

    rs.withdrawCourse(4000, 520);
    rs.withdrawCourse(1000, 520);
    rs.cancelCourse(520);
    rs.withdrawCourse(2000, 540);
    rs.withdrawCourse(1000, 540);
    rs.withdrawCourse(4000, 540);

    rs.addCourse(6000, 540, "CS540");
    rs.addCourse(4000, 540, "CSS540");
    rs.addCourse(4000, 540, "CS540");
    rs.addCourse(1000, 540, "CSS540");

    rs.cancelCourse(540);
    rs.withdrawCourse(1000, 540);
    rs.withdrawCourse(1000, 520);
    rs.withdrawCourse(1000, 555);

}
/*
There are no students in the system
Student 2000 does not exist
Student 2000 has been added
Student id First name Last name
2000 Kemal Ak
Student 1000 has been added
Student 4000 has been added
Student id First name Last name
1000 Nuri Yazici
2000 Kemal Ak
4000 Cengiz Erdem
Course 555 does not exist
Course 555 has been added to student 2000
Course 540 has been added to student 2000
Course id Course name
555 CS555
Student id First name Last name
2000 Kemal Ak
Student id First name Last name
1000 Nuri Yazici
2000 Kemal Ak
Course id Course name
540 CS540
555 CS555
4000 Cengiz Erdem
Course 555 has been added to student 1000
Course 540 has been added to student 1000
Student 1000 is not enrolled in course 510
Student 1000 has been withdrawn from course 540
Course id Course name
540 CS540
Student id First name Last name
2000 Kemal Ak
Student id First name Last name
1000 Nuri Yazici
Course id Course name
555 CS555
Course 540 has been cancelled
Course 540 does not exist
Student id First name Last name
1000 Nuri Yazici
Course id Course name
555 CS555
2000 Kemal Ak
Course id Course name
555 CS555
4000 Cengiz Erdem
*/
void test4(){
 RegistrationSystem rs;
    rs.showAllStudents();

    rs.showStudent(2000);
    rs.addStudent(2000, "Kemal", "Ak");
    rs.showStudent(2000);

    rs.addStudent(1000, "Nuri", "Yazici");
    rs.addStudent(4000, "Cengiz", "Erdem");

    rs.showAllStudents();

    rs.showCourse(555);
    rs.addCourse(2000, 555, "CS555");
    rs.addCourse(2000, 540, "CS540");
    rs.showCourse(555);

    rs.showAllStudents();

    rs.addCourse(1000, 555, "CS555");
    rs.addCourse(1000, 540, "CS540");
    rs.withdrawCourse(1000, 510);
    rs.withdrawCourse(1000, 540);
    rs.showCourse(540);
    rs.showStudent(1000);

    rs.cancelCourse(540);
    rs.showCourse(540);

    rs.showAllStudents();

}
void myTest(){
    RegistrationSystem rs;

    rs.addStudent(2000, "Kemal", "Ak");
    rs.addStudent(1000, "Nuri", "Yazici");
    rs.addStudent(4000, "Cengiz", "Erdem");
    rs.deleteStudent(4000);
    rs.deleteStudent(2000);
    rs.deleteStudent(2000);
    rs.deleteStudent(1000);
    rs.addStudent(2000, "Kemal", "Ak");
    rs.addStudent(1000, "Nuri", "Yazici");
    rs.addStudent(4000, "Cengiz", "Erdem");
    rs.addStudent(2000, "Kemal", "Ak");
    rs.addStudent(1000, "Nuri", "Yazici");
    rs.addStudent(4000, "Cengiz", "Erdem");

    rs.showAllStudents();
    rs.addCourse(1000, 201, "CS201");
    rs.addCourse(1000, 223, "CS223");
    rs.showStudent(1000);
    rs.cancelCourse(223);
    rs.showAllStudents();
    rs.deleteStudent(1000);
    rs.showCourse(201);
    rs.deleteStudent(2000);
    rs.deleteStudent(4000);
}
int main () {
test0();
return 0;
}

