/*
    Title:      Lab 4 – employee-linked-list
    Purpose:   Read a text file containing the information of the employees of a company, load them into memory and perform some basic human resources operations. Using linked list
    Author:     Jasmine Salmeron
    Date:       November 22 2020
*/


#include "employee.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using std::stringstream;
using std:: endl;
using std:: cout;
using std:: setw;
using std:: left;
using std:: right;

Employee::Employee(unsigned int id, const string& name, double salary, unsigned int managerId):_id(id), _salary(salary), _name(name),_managerId(managerId){
    if(name.empty())
    {
        _name = "***";
    }
    else{
        _name = name;
    }

}
Employee::Employee(const Employee& employee):_id(employee._id),_salary(employee._salary), _name(employee._name), _managerId(employee._managerId){

}
/*
 * intializing accessors
 */
unsigned int Employee::GetId(){
    return this->_id;
}
string Employee::GetName(){
    return this -> _name;
}
double Employee:: GetSalary(){
    return this ->_salary;
}
unsigned int Employee::GetManagerId(){
    return this-> _managerId;
}
string Employee::ToString() const{
    stringstream out;
    out<< "ID: " << setw(4)<< _id << " Name: "<< left << setw(10)<< _name <<" Salary: " <<right<< setw(10)<< _salary << " Manager ID: " << setw(4)<< _managerId << endl;
    return out.str();
}
void Employee::Raise(double raise){
    _salary+=raise;
}
bool Employee::Equals(const Employee& employee){
    if( _id == employee._id)
    {
        return true;
    }
    return false;
}
bool Employee::Read(istream& input){
    input>> _id >> _name >> _salary >>_managerId;
    return !input.fail();
}
void Employee::Write(ostream& output){
    output<< _id <<", " << setw(4)<< _name <<", " <<setw(4)<<  _salary <<", " << setw(4)<< _managerId;
}
Employee::~Employee(){

}