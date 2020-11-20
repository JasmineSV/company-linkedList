//
// Created by 12066 on 11/19/2020.
//

#ifndef COMPANY_LINKED_LIST_JASMINESV_COMPANY_H
#define COMPANY_LINKED_LIST_JASMINESV_COMPANY_H

#include "employee.h"


class Company {
private:
struct Node{
    Employee* data;
    Node* next;
};
    Node* _head;
    unsigned int _size;
    Company(const Company& company);

public:
    Company();
    bool AddEmployee(unsigned int id, const string & name, double salary, unsigned int managerId);
    bool AddEmployee(const Employee& employee);
    int FindById(unsigned int);
    int FindByName(const string&, unsigned int=0);
    int Read(istream&);
    int Write(ostream&);
    bool IsFull();
    Employee* Get(unsigned int position);//postion
    unsigned int GetEmployeeCount();
    string ToString()const;
    ~Company();

};




#endif //COMPANY_LINKED_LIST_JASMINESV_COMPANY_H
