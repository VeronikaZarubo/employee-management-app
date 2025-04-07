// IT Employees Management System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee {
protected:
    int rollno, workYears;
    string fullName, position;

public:
    Employee(int stdRollno, string stdfullName, int stdWorkYears, string stdPosition) {
        rollno = stdRollno;
        fullName = stdfullName;
        workYears = stdWorkYears;
        position = stdPosition;
    }
    void setRollno(int stdRollno) {
        rollno = stdRollno;
    }
    int getRollno() {
        return rollno;
    }
    void setfullName(string stdfullName) {
        fullName = stdfullName;
    }
    string getfullName() {
        return fullName;
    }
    void setPosition(string stdPosition) {
        position = stdPosition;
    }
    string getPosition() {
        return position;
    }
    void setWorkYears(int stdWorkYears) {
        workYears = stdWorkYears;
    }
    int getWorkYears() {
        return workYears;
    }
    void Work() {
        cout << fullName << " is working..." << endl;        
    }
    void AskForPromotion() {
        if (position == "CEO")
            cout << "Max position reached! No promotion for " << fullName << " available." << endl;
        else if (workYears > 3)
            cout << fullName << " got promoted!!" << endl;
        else
            cout << fullName << " sorry, no promotion for you.." << endl;
    };
    void displayEmployee(){
        cout << "Roll No : " << rollno << endl;
        cout << "Full Name : " << fullName << endl;
        cout << "Work Experience In Years : " << workYears << endl;
        cout << "Position : " << position << endl;
    }
};

// CEO, Analytics, Developer, Tester, HR classes   |
//                                                \|/
class CEO :public Employee {
public:
    CEO(int rollno, string fullName, int workYears, string position) :
        Employee(rollno, fullName, workYears, position) {};
    void Work() {
        cout << fullName << " is making corporate decisions, managing operations..." << endl;
    }
};

class Analytics :public Employee {
public:
    Analytics(int rollno, string fullName, int workYears, string position) :
        Employee(rollno, fullName, workYears, position) {
    };
    void Work() {
        cout << fullName << " is using math, statistics, and machine learning to find meaningful patterns in data..." << endl;
    }
};

class Developer :public Employee {
public:
    Developer(int rollno, string fullName, int workYears, string position) :
        Employee(rollno, fullName, workYears, position) {
    };
    void Work() {
        cout << fullName << " is designing, programming, building, deploying and maintaining software..." << endl;
    }
};

class Tester :public Employee {
public:
    Tester(int rollno, string fullName, int workYears, string position) :
        Employee(rollno, fullName, workYears, position) {
    };
    void Work() {
        cout << fullName << " is running various tests on software systems to ensure that they function according to the required standards..." << endl;
    }
};

class HR :public Employee {
public:
    HR(int rollno, string fullName, int workYears, string position) :
        Employee(rollno, fullName, workYears, position) {
    };
    void Work() {
        cout << fullName << " is managing the entire employee lifecycle — recruitment, onboarding, training, termination or retirement..." << endl;
    }
};
                                     

//  Add, display, update, search, delete employee  |
//                                                \|/ 

void addNewEmployee(vector<Employee>& employee) {
    int rollno, workYears, positionNumber;
    string fullName, position;
    cout << "Enter Rollno : " << endl;
    cin >> rollno;

    for (int i = 0;i < employee.size(); i++) {
        if (employee[i].getRollno() == rollno) {
            cout << "\t\tEmployee Already Exists..." << endl;
            return;
        }
    };

    cout << "Enter Full Name : ";
    cin >> fullName;
    cout << "Enter Work Experience In Years : ";
    cin >> workYears;

    cout << "\t-------------Choose A Position Number : " << endl;
    cout << "\t\t\t1. CEO" << endl;
    cout << "\t\t\t2. Analytics" << endl;
    cout << "\t\t\t3. Developer" << endl;
    cout << "\t\t\t4. Tester" << endl;
    cout << "\t\t\t5. HR" << endl;
    cout << "\t\t\t6. Exit" << endl;
    cout << "Enter Position : ";
    cin >> positionNumber;
    
    switch(positionNumber){
    case 1: 
        position = "CEO";
        break;
    case 2: 
        position = "Analytics";
        break;
    case 3: 
        position = "Developer";
        break; 
    case 4: 
        position = "Tester";
        break;
    case 5: 
        position = "HR";
        break;
    case 6: 
        return;
    default:
        cout << "\t\tInvalid Number" << endl;
        return;
    }

    Employee newEmployee(rollno, fullName, workYears, position);
    employee.push_back(newEmployee);

    cout << "\t\tEmployee Add Successfully..." << endl;
};

void displayAllEmployee(vector<Employee>& employee) {
    if (employee.empty()) {
        cout << "\n\t\tNo Employee Found \n" << endl;
        return;
    }
    for (int i = 0;i < employee.size();i++)
    {
        cout << "\t\t----------------------------------------- " << endl;
        employee[i].displayEmployee();
        employee[i].AskForPromotion();

        if (employee[i].getPosition() == "CEO") {
            CEO c = CEO(employee[i].getRollno(), employee[i].getfullName(), employee[i].getWorkYears(), employee[i].getPosition());
            c.Work();
        }            
        else if (employee[i].getPosition() == "Analytics") {
            Analytics a = Analytics(employee[i].getRollno(), employee[i].getfullName(), employee[i].getWorkYears(), employee[i].getPosition());
            a.Work();
        }
        else if (employee[i].getPosition() == "Developer") {
            Developer d = Developer(employee[i].getRollno(), employee[i].getfullName(), employee[i].getWorkYears(), employee[i].getPosition());
            d.Work();
        }
        else if (employee[i].getPosition() == "Tester") {
            Tester t = Tester(employee[i].getRollno(), employee[i].getfullName(), employee[i].getWorkYears(), employee[i].getPosition());
            t.Work();
        }
        else {
            HR hr = HR(employee[i].getRollno(), employee[i].getfullName(), employee[i].getWorkYears(), employee[i].getPosition());
            hr.Work();
        }
    }
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
    string fullName;
    bool found = false;
    int choice;

    cout << "\t\tEnter Full Name to Update Record : ";
    cin.ignore();
    getline(cin, fullName);

    for (int i = 0; i < employee.size();i++) {
        if (employee[i].getfullName() == fullName) {
            found = true;

            cout << "\t\t------- Employee Found -------" << endl;
            cout << "\t\t\t1. Update Rollno" << endl;
            cout << "\t\t\t2. Update Full Name" << endl;
            cout << "\t\t\t3. Update Work Experience In Years" << endl;
            cout << "\t\t\t4. Update Position" << endl;
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
                    string fullName;
                    cout << "\t\t\t2. Enter New Full Name : ";
                    cin.ignore();
                    getline(cin, fullName);
                    employee[i].setfullName(fullName);
                    break;
                 }                    
                case 3: {
                    int workYears;
                    cout << "\t\t\t2. Enter New years : ";
                    cin >> workYears;
                    employee[i].setWorkYears(workYears);
                    break;
                 }
                case 4: {
                    string position;
                    cout << "\t\t\t2. Enter New Position : ";
                    cin >> position;
                    employee[i].setPosition(position);
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
    string fullName;
    cout << "Enter Full Name To Delete : ";
    cin.ignore();
    getline(cin, fullName);

    for (int i = 0;i < employee.size();i++) {
        if (employee[i].getfullName() == fullName) {
            employee.erase((employee.begin() + i));
            cout << "\t\tEmployee Remove Successfully" << endl;
        }
    }
}

int main()
{
    vector<Employee> employee;
    employee.push_back(Employee(1, "John Doe", 20, "CEO"));    
    employee.push_back(Employee(2, "Anna Nowak", 1, "Developer"));    
    employee.push_back(Employee(3, "Janina Kowalska", 8, "Analytics"));    
    employee.push_back(Employee(4, "Jan Kowalski", 3, "HR"));    

    char choice;

    do {
        system("cls");

        cout << "\t\t==========================================" << endl;
        cout << "\t\tAll The Employee Display" << endl;

        displayAllEmployee(employee);

        int op;
        cout << "\t\t------------------------------------------" << endl;
        cout << "\t\t\tEmployee Management System" << endl;
        cout << "\t\t------------------------------------------" << endl;
        cout << "\t\t\t1. Add New Employee" << endl;
        cout << "\t\t\t2. Search Employee" << endl;
        cout << "\t\t\t3. Update Employee" << endl;
        cout << "\t\t\t4. Delete Employee" << endl;
        cout << "\t\t\t5. Exit" << endl;
        cout << "\t\t------------------------------------------" << endl;
        cout << "\t\tEnter Your Choice : ";
        cin >> op;
        switch (op) {
            case 1:
                addNewEmployee(employee);
                break;
            case 2:
                searchEmployee(employee);
                break;
            case 3:
                updateEmployee(employee);
                break;
            case 4:
                deleteEmployee(employee);
                break;
            case 5:
                exit(1);
            default:
                cout << "\t\tInvalid number ..." << endl;
        }
            cout << "\t\tDo You Want To continue [Yes / No] ? :";
            cin >> choice;

    } while (choice == 'y' || choice == 'Y');  

};
