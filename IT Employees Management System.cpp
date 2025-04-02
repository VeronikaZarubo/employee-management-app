// IT Employees Management System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
protected:
    int rollno, age;
    string name;

public:
    Employee(int stdRollno, string stdName, int stdAge) {
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
    void displayEmployee(){
        cout << "Roll No : " << rollno << endl;
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
    }
};

void addNewEmployee(vector<Employee>& employee) {
    int rollno, age;
    string name;
    cout << "Enter Rollno : " << endl;
    cin >> rollno;

    for (int i = 0;i < employee.size(); i++) {
        if (employee[i].getRollno() == rollno) {
            cout << "\t\Employee Already Exists..." << endl;
            return;
        }
    };

    cout << "Enter name : ";
    cin >> name;
    cout << "Enter Age : ";
    cin >> age;

    Employee newEmployee(rollno, name, age);
    employee.push_back(newEmployee);

    cout << "\t\Employee Add Successfully..." << endl;
};

void displayAllEmployee(vector<Employee>& employee) {
    if (employee.empty()) {
        cout << "\t\tNo Employee Found " << endl;
        return;
    }
    for (int i = 0;i < employee.size();i++)
        employee[i].displayEmployee();
}

void searchEmployee(vector<Employee>& employee) {
    int rollno;
    cout << "\t\tEnter Rollno : ";
    cin >> rollno;

    for (int i = 0; i < employee.size();i++) {
        if (employee[i].getRollno() == rollno) {
            cout << "\t\t------------- Employee Found --------------" << endl;
            employee[i].displayEmployee();
            return;
        }
    }

}

void updateEmployee(vector<Employee>& employee) {
    string name;
    bool found = false;
    int choice;

    cout << "\t\tEnter Name to Update Record : ";
    cin.ignore();
    getline(cin, name);

    for (int i = 0; i < employee.size();i++) {
        if (employee[i].getName() == name) {
            found = true;

            cout << "\t\t------- Employee Found -------" << endl;
            cout << "\t\t\t1. Update Rollno" << endl;
            cout << "\t\t\t2. Update Name" << endl;
            cout << "\t\t\t3. Update Age" << endl;
            cout << "\t\tEnter your Choice : " << endl;
            cin >> choice;

            switch (choice) {
                case 1: {
                    int rollno;
                    cout << "\t\t\t2. Enter New Rollno : ";
                    cin >> rollno;
                    employee[i].setRollno(rollno);
                    break;
                    }                    
                case 2: {
                    string name;
                    cout << "\t\t\t2. Enter New Name : ";
                    cin.ignore();
                    getline(cin, name);
                    employee[i].setName(name);
                    break;
                 }                    
                case 3: {
                    int age;
                    cout << "\t\t\t2. Enter New Age : ";
                    cin >> age;
                    employee[i].setAge(age);
                    break;
                 }
                default:
                    cout << "\t\tInvalid Number" << endl;         
            }
        }
        if (!found) {
            cout << "\t\tRecord Not Found Here" << endl;
            return;
        }                   
    }

}

void deleteEmployee(vector<Employee>& employee) {
    string name;
    cout << "Enter Name To Delete : ";
    cin.ignore();
    getline(cin, name);    

    for (int i = 0;i < employee.size();i++) {
        if (employee[i].getName() == name) {
            employee.erase((employee.begin() + i));
            cout << "\t\Employee Remove Successfully" << endl;
        }
    }
}


int main()
{
    vector<Employee> employee;
    employee.push_back(Employee(1, "oo", 71));

    char choice;

    do {
        system("cls");
        int op;
        cout << "\t\t------------------------------------------" << endl;
        cout << "\t\t\Employee Management System" << endl;
        cout << "\t\t------------------------------------------" << endl;
        cout << "\t\t\t1. Add New Employee" << endl;
        cout << "\t\t\t2. Display All Employees" << endl;
        cout << "\t\t\t3. Search Employee" << endl;
        cout << "\t\t\t4. Update Employee" << endl;
        cout << "\t\t\t5. Delete Employee" << endl;
        cout << "\t\t\t6. Exit" << endl;
        cout << "\t\t------------------------------------------" << endl;
        cout << "\t\tEnter Your Choice : ";
        cin >> op;
        switch (op) {
            case 1:
                addNewEmployee(employee);
                break;
            case 2:
                displayAllEmployee(employee);
                break;
            case 3:
                searchEmployee(employee);
                break;
            case 4:
                updateEmployee(employee);
                break;
            case 5:
                deleteEmployee(employee);
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
