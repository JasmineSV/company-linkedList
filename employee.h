/*
    Title:      Lab 4 – employee-linked-list
    Purpose:   Read a text file containing the information of the employees of a company, load them into memory and perform some basic human resources operations. Using linked list
    Author:     Jasmine Salmeron
    Date:       November 22 2020
*/


//
// Created by 12066 on 11/19/2020.
//
#include <string>
#include <iostream>

#ifndef COMPANY_LINKED_LIST_JASMINESV_EMPLOYEE_H
#define COMPANY_LINKED_LIST_JASMINESV_EMPLOYEE_H

using std:: string;
using std:: istream;
using std:: ostream;

class Employee {
private:
    unsigned int _id;
    string _name;
    double _salary;
    unsigned int _managerId;

public:
    Employee(unsigned int id,const string& name, double salary, unsigned int managerId =0);
    Employee(const Employee&);
    unsigned int GetId();//accessor
    string GetName();
    double GetSalary();
    unsigned int GetManagerId();//accessor
    string ToString()const;
    void Raise(double);
    bool Equals(const Employee&);
    bool Read(istream&);
    void Write(ostream&);
    ~Employee();
};


#endif //COMPANY_LINKED_LIST_JASMINESV_EMPLOYEE_H
