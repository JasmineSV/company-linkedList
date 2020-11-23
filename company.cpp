/*
    Title:      Lab 4 – employee-linked-list
    Purpose:   Read a text file containing the information of the employees of a company, load them into memory and perform some basic human resources operations. Using linked list
    Author:     Jasmine Salmeron
    Date:       November 22 2020
*/



//
// Created by 12066 on 11/19/2020.
//

#include "company.h"
#include "employee.h"
#include <sstream>
using std::stringstream;
using std:: endl;

Company::Company(const Company& company){
    for (Node* tmp = company._head; tmp != nullptr; tmp = tmp->next)
    {
        AddEmployee(tmp->data->GetId(), tmp->data->GetName(), tmp->data->GetSalary(), tmp->data->GetManagerId());//what would go here???
    }
}

Company::Company() {
    _head = nullptr;
    _size = 0;
}

bool Company::AddEmployee(unsigned int id, const string & name, double salary, unsigned int managerId) {
    //recieves info of employee
    Employee *employee =  new Employee(id, name, salary,managerId);//trying to create the employee

    Node* neo = new Node;//creating a new node
    neo->data= new Employee(*employee);//setting it
    neo->next = nullptr;
    if (_size == 0){// no element inside
        _head = neo;//element we're adding is the first one
    }else if (neo->data->GetId() < _head->data->GetId()){//if the incoming employee(element) is less than the first employee (head) you set incoming element to head
        neo->next = _head;//pointing neo next to head
        _head = neo;//head is pointing to neo because neo less than the element that was head before
    }else{
        Node* tmp = _head;
        while (tmp->next != nullptr && neo->data->GetId() > tmp->next->data->GetId())
            tmp = tmp->next;
        neo->next = tmp->next;
        tmp->next = neo;
    }
    _size++;
return true;
}

bool Company::AddEmployee(const Employee & employee) {
    Node* neo = new Node;
    neo->data= new Employee(employee);
    neo->next = nullptr;
    if (_size == 0){
        _head = neo;
    }else if (neo->data->GetId() < _head->data->GetId()){
        neo->next = _head;
        _head = neo;
    }else{
        Node* tmp = _head;
        while (tmp->next != nullptr && neo->data->GetId() > tmp->next->data->GetId())
            tmp = tmp->next;
        neo->next = tmp->next;
        tmp->next = neo;
    }
    _size++;
    return true;
}
//finding the id and setting it
int Company::FindById(unsigned int id) {
    if(_size == 0){

        return -1;
    }
    Node* curr = _head;
    int pos = 0;
    while (curr->next != NULL){
        if(curr->data->GetId() == id){
            return pos;
        }
        curr = curr->next;
        pos++;
    }
    return -1;
}

int Company::FindByName(const string & name, unsigned int position) {
    Node* curr = _head;
    int pos = 0;
    if(position <= _size){
        while (curr != NULL && pos < position){
            curr = curr->next;
            pos++;
        }
        while (curr != NULL) {
            if (curr->data->GetName() == name) {
                return pos;
            }
            pos++;
            curr = curr->next;
        }
    }
    return -1;

}

int Company::Read(istream & input) {

    string name;
    int read =0;
    unsigned int id;
    unsigned  int managerId;
    double salary;

        while(input >> id){
            input>> name;
            input>> salary;
            input>> managerId;
            AddEmployee(id,name,salary,managerId);
            read++;
        }
    return read;
}

int Company::Write(ostream & output) {
    int count = 0;//always initialize to zero so it resets
    for (Node* tmp = _head; tmp != nullptr; tmp = tmp->next) {
        output << tmp->data->ToString();
        count++;
    }
    return count;
}

bool Company::IsFull(){
    return false;
}

Employee *Company::Get(unsigned int position) {
    if(position>= _size){
        return nullptr;
    }
    Node* tmp = _head;
    for (int i = 0; i < position; ++i) {
        tmp = tmp->next;
    }
    return tmp->data;
}

unsigned int Company::GetEmployeeCount() {
    return _size;
}

Company::~Company() {

}
