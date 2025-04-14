// IT Employees Management System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class IAbstractEmployee{
public:
    virtual void AskForPromotion() = 0;
};

class Employee : public IAbstractEmployee {
protected:
    int rollno, workYears;
    string name, surname, position;

public:
    Employee(int stdRollno, string stdName, string stdSurname, int stdWorkYears, string stdPosition) {
        rollno = stdRollno;
        name = stdName;
        surname = stdSurname;
        workYears = stdWorkYears;
        position = stdPosition;
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
    void setSurname(string stdSurname) {
        surname = stdSurname;
    }
    string getSurname() {
        return surname;
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
        cout << name << " " << surname << " is working..." << endl;
    }
    void AskForPromotion() override {
        if (position == "CEO")
            cout << "Max position reached! No promotion for " << name << " available." << endl;
        else if (workYears > 3)
            cout << name << " " << surname << " got promoted!!" << endl;
        else
            cout << name << " " << surname << " sorry, no promotion for you.." << endl;
    };
    void displayEmployee(){
        cout << "Roll No : " << rollno << endl;
        cout << "Name : " << name << endl;
        cout << "Surname : " << surname << endl;
        cout << "Work Experience In Years : " << workYears << endl;
        cout << "Position : " << position << endl;
    }
};

// CEO, Analyst, Developer, Tester, HR classes   |
//                                              \|/
class CEO :public Employee {
public:
    CEO(int rollno, string name, string surname, int workYears, string position) :
        Employee(rollno, name, surname, workYears, position) {}
    void Work() {
        cout << name << " " << surname << " is making corporate decisions, managing operations..." << endl;
    }
};

class Analyst :public Employee {
public:
    Analyst(int rollno, string name, string surname, int workYears, string position) :
        Employee(rollno, name, surname, workYears, position) {}
    void Work() {
        cout << name << " " << surname << " is using math, statistics, and machine learning to find meaningful patterns in data..." << endl;
    }
};

class Developer :public Employee {
public:
    Developer(int rollno, string name, string surname, int workYears, string position) :
        Employee(rollno, name, surname, workYears, position) {}
    void Work() {
        cout << name << " " << surname << " is designing, programming, building, deploying and maintaining software..." << endl;
    }
};

class Tester :public Employee {
public:
    Tester(int rollno, string name, string surname, int workYears, string position) :
        Employee(rollno, name, surname, workYears, position) {}
    void Work() {
        cout << name << " " << surname << " is running various tests on software systems to ensure that they function according to the required standards..." << endl;
    }
};

class HR :public Employee {
public:
    HR(int rollno, string name, string surname, int workYears, string position) :
        Employee(rollno, name, surname, workYears, position) {}
    void Work() {
        cout << name << " " << surname << " is managing the entire employee lifecycle — recruitment, onboarding, training, termination or retirement..." << endl;
    }
};
                                     

//  Add, display, update, search, delete employee  |
//                                                \|/ 

void addNewEmployee(vector<Employee>& employee) {
    int rollno, workYears, positionNumber;
    string name, surname, position;
    cout << "Enter Rollno : " << endl;
    cin >> rollno;

    for (int i = 0;i < employee.size(); i++) {
        if (employee[i].getRollno() == rollno) {
            cout << "\t\tEmployee Already Exists..." << endl;
            return;
        }
    };

    cout << "Enter Name : ";
    cin >> name;
    cout << "Enter Surname : ";
    cin >> surname;
    cout << "Enter Work Experience In Years : ";
    cin >> workYears;

    cout << "\t-------------Choose A Position Number : " << endl;
    cout << "\t\t\t1. CEO" << endl;
    cout << "\t\t\t2. Analyst" << endl;
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
        position = "Analyst";
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

    Employee newEmployee(rollno, name, surname, workYears, position);
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
            CEO c = CEO(employee[i].getRollno(), employee[i].getName(), employee[i].getSurname(), employee[i].getWorkYears(), employee[i].getPosition());
            c.Work();
        }            
        else if (employee[i].getPosition() == "Analyst") {
            Analyst a = Analyst(employee[i].getRollno(), employee[i].getName(), employee[i].getSurname(), employee[i].getWorkYears(), employee[i].getPosition());
            a.Work();
        }
        else if (employee[i].getPosition() == "Developer") {
            Developer d = Developer(employee[i].getRollno(), employee[i].getName(), employee[i].getSurname(), employee[i].getWorkYears(), employee[i].getPosition());
            d.Work();
        }
        else if (employee[i].getPosition() == "Tester") {
            Tester t = Tester(employee[i].getRollno(), employee[i].getName(), employee[i].getSurname(), employee[i].getWorkYears(), employee[i].getPosition());
            t.Work();
        }
        else {
            HR hr = HR(employee[i].getRollno(), employee[i].getName(), employee[i].getSurname(), employee[i].getWorkYears(), employee[i].getPosition());
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
    string fullname;
    bool found = false;
    int choice;

    cout << "\t\tEnter Full Name to Update Record : ";
    cin.ignore();
    getline(cin, fullname);

    for (int i = 0; i < employee.size();i++) {
        if ((employee[i].getName()+' '+employee[i].getSurname()) == fullname) {
            found = true;

            cout << "\t\t------- Employee Found -------" << endl;
            cout << "\t\t\t1. Update Rollno" << endl;
            cout << "\t\t\t2. Update Name" << endl;
            cout << "\t\t\t3. Update Surname" << endl;
            cout << "\t\t\t4. Update Work Experience In Years" << endl;
            cout << "\t\t\t5. Update Position" << endl;
            cout << "\t\tEnter your Choice : ";
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
                    employee[i].setName(fullname);
                    break;
                 }   
                case 3: {
                    string surname;
                    cout << "\t\t\t2. Enter New Surname : ";
                    cin.ignore();
                    getline(cin, surname);
                    employee[i].setSurname(surname);
                    break;
                }
                case 4: {
                    int workYears;
                    cout << "\t\t\t2. Enter New years : ";
                    cin >> workYears;
                    employee[i].setWorkYears(workYears);
                    break;
                 }
                case 5: {
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
    string fullname;
    cout << "Enter Full Name To Delete : ";
    cin.ignore();
    getline(cin, fullname);

    for (int i = 0;i < employee.size();i++) {
        if ((employee[i].getName() + ' ' + employee[i].getSurname()) == fullname) {
            employee.erase((employee.begin() + i));
            cout << "\t\tEmployee Remove Successfully" << endl;
        }
    }
}

int main()
{
    vector<Employee> employee;
    employee.push_back(Employee(1, "John", "Doe", 20, "CEO"));
    employee.push_back(Employee(2, "Anna", "Nowak", 1, "Developer"));    
    employee.push_back(Employee(3, "Janina", "Kowalska", 8, "Analyst"));    
    employee.push_back(Employee(4, "Jan", "Kowalski", 3, "HR"));    

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
