/*
    Title:      Lab 4 – employee-linked-list
    Purpose:   Read a text file containing the information of the employees of a company, load them into memory and perform some basic human resources operations. Using linked list
    Author:     Jasmine Salmeron
    Date:       November 22 2020
*/



//
// Created by 12066 on 11/19/2020.
//

#ifndef COMPANY_LINKED_LIST_JASMINESV_COMPANY_H
#define COMPANY_LINKED_LIST_JASMINESV_COMPANY_H

#include "employee.h"


class Company {
private:
struct Node{
    Employee* data;//linkedList of employee pointers--> use pointer because employee doesnt have default constructor
    Node* next;
};
    Node* _head;//pointer to _head
    unsigned int _size;//initializes _size
    Company(const Company& company);//passing company by reference --> copy constructor

public:
    Company();
    bool AddEmployee(unsigned int id, const string & name, double salary, unsigned int managerId);
    bool AddEmployee(const Employee& employee);
    int FindById(unsigned int);
    int FindByName(const string&, unsigned int=0);
    int Read(istream&);
    int Write(ostream&);
    bool IsFull();
    Employee* Get(unsigned int position);
    unsigned int GetEmployeeCount();
    string ToString()const;
    ~Company();

};




#endif //COMPANY_LINKED_LIST_JASMINESV_COMPANY_H
