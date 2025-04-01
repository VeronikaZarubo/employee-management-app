// IT Employees Management System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    int rollno, age;
    string name;

public:
    Student(int stdRollno, string stdName, int stdAge) {
        rollno = stdRollno;
        name = stdName;
        age = stdAge;
    }
    void setRollno(int stdRollno) {
        rollno = stdRollno;
    }
    int getRollno() {
        return rollno;
    }
    void setName(string stdName) {
        name = stdName;
    }
    string getName() {
        return name;
    }
    void setAge(int stdAge) {
        age = stdAge;
    }
    int getAge() {
        return age;
    }
    void displayStudent(){
        cout << "Roll No : " << rollno << endl;
        cout << "Name : " << rollno << endl;
        cout << "Age : " << rollno << endl;
    }
};

void addNewStudent(vector<Student>& students) {
    int rollno, age;
    string name;
    cout << "Enter Rollno : " << endl;
    cin >> rollno;

    for (int i = 0;i < students.size(); i++) {
        if (students[i].getRollno()==rollno) {
            cout << "\t\tStudent Already Exists..." << endl;
            return;
        }
    };


    cout << "Enter name : " << endl;
    cin >> name;
    cout << "Enter Age" << endl;
    cin >> age;

    Student newStudent(rollno, name, age);
    students.push_back(newStudent);

    cout << "\t\tStudent Add Successfully..." << endl;
};


int main()
{
    vector<Student> students;
    students.push_back(Student(1, "oo", 71));

    char choice;

    do {
        system("cls");
        int op;
        cout << "\t\t------------------------------------------" << endl;
        cout << "\t\t\tStudent Management System" << endl;
        cout << "\t\t------------------------------------------" << endl;
        cout << "\t\t\t1. Add New student" << endl;
        cout << "\t\t\t2. Display All Students" << endl;
        cout << "\t\t\t3. Search Student" << endl;
        cout << "\t\t\t4. Update student" << endl;
        cout << "\t\t\t5. Delete student" << endl;
        cout << "\t\t\t6. Exit" << endl;
        cout << "\t\t------------------------------------------" << endl;
        cout << "\t\tEnter Your Choice : ";
        cin >> op;
        switch (op) {
        case 1:
            addNewStudent(students);
            break;
        case 6:
            exit(1);
        default:
            cout << "\t\tInvalid number ..." << endl;
        }
        cout << "\t\tDo You Want To continue [Yes / No] ? :";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

        


};
