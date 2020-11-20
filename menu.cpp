//
// Created by 12066 on 11/19/2020.
//

#include "employee.h"
#include "company.h"



#include <istream>;
#include <iostream>
#include <fstream>
#include <string>
using std::cerr;
using std::endl;
using std:: cout;
using std::cin;
using std:: ifstream;
using std::ofstream;

unsigned int menu();

int main(){
        unsigned int options;
        Company company;
        do{
            if(options == 1)
            {
                cout << "Input file name: ";
                string filename;
                cin>> filename;
                ifstream input(filename);
                if(input.fail())
                {
                    cout<<"Unable to open file " << filename<< endl;
                }
                else{
                    int employees = company.Read(input);
                    cout<< employees << " records read from file " << filename << endl;
                }
            }
            else if(options ==2)
            {
                int employees;
                string fileName;
                cout<< "Enter file name";
                cin>> fileName;
                ofstream input(fileName);
                if(input.fail())
                {
                    cout<<"Please try again!! "<< endl;
                }else{
                    employees = company.Write(input);
                    cout<< "Number of employees: " << employees << endl;
                }
            }
            else if(options ==3)
            {
                int employeeCount;
                employeeCount = company.GetEmployeeCount();
                if (employeeCount == 0) {
                    cout << "No employees found." << endl;
                } else {
                    cout<<company.ToString() << endl;
                }
            }
            else if(options ==4)
            {
                string employeeName;
                int postition = 0;
                Company employee;
                cout<< "Enter employee name: ";
                cin>>employeeName;
                postition = company.FindByName(employeeName,postition);
                if(postition!=-1){
                    do{
                        employee.AddEmployee(*company.Get(postition));
                        postition = company.FindByName(employeeName, postition + 1);
                    }while(postition!=-1);
                }
                employee.Write(cout);
            }
            else if(options ==5)
            {
                unsigned int id;
                int position;
                cout<<"Enter ID: ";
                cin >> id;
                position = company.FindById(id);
                if(position != -1) {//it was looking for index -1 in the array which doesn't exist. So, with this it'll make sure that index is not -1
                    Employee employee(*company.Get(position));
                    cout << employee.ToString() << endl;

                }

            }
            else if(options ==6)
            {
                unsigned int id;
                int position;
                cout<< "Search for Id: ";
                cin >> id;
                position = company.FindById(id);
                if(position != -1) {//it was looking for index -1 in the array which doesn't exist. So, with this it'll make sure that index is not -1
                    Employee employee(*company.Get(position));
                    cout << "Employee with ID " << id<< " has manager: " << endl;//position after amaner:
                    position = company.FindById(employee.GetManagerId());
                    Employee manager = (*company.Get(position));
                    cout << manager.ToString() << endl;
                }

            } else if(options ==7)
            {
                bool input;
                unsigned int id;
                double salary;
                string name;
                unsigned int managerId;
                cout<< "Input Employee Information " << endl;
                cout<< "Employee id: ";
                cin >> id;
                cout<<"Employee Name: ";
                cin >> name;
                cout << "Employee Salary: ";
                cin>> salary;
                cout << "Employee's Boss Id: ";
                cin >> managerId;
                input = company.AddEmployee(id,name,salary,managerId);
                if(input== true)
                {
                    cout << "Employee added successfully" <<endl;
                }
                if(company.IsFull() == true){
                    cout<< "Data is full" << endl;
                }


            }
            else if(options ==8)
            {
                if(company.IsFull()== true)
                {
                    cout<< "Database is Full" << endl;
                }
                else {
                    cout<< "Not full yet" << endl;
                }
            }

        }while((options = menu()) != 9);
};



unsigned int menu(){
    unsigned int options;
    while (true){
        cout<< "1. Load from File" <<endl;
        cout<< "2. Save to File" <<endl;
        cout<< "3. List all Employees" <<endl;
        cout<< "4. Search by Name" <<endl;
        cout<< "5. Search by ID" <<endl;
        cout<< "6. Find Employee Boss Information" <<endl;
        cout<< "7. Add new Employee" <<endl;
        cout<< "8. Check if Database is Full" << endl;
        cout << "9. Exit "<< endl;
        cout << " " << endl;
        cin >> options;

        //if input failed
        if(cin.fail()){
            cin.clear();
            cin.ignore(255, '\n');
            cerr << "Invalid input!!" << endl;
            continue;
        }
        //if the number entered is not one of the options it displays a error message.
        if (options <= 0 || options > 9){
            cerr << "Incorrect menu option!!" <<endl;
            continue;
        }
        break;
    }
    return options;
}