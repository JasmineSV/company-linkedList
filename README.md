# Company of Employees: Single Linked List
## Goal:
Your assignment is to write a C++ program to read a text file containing the information of the employees of a company, load them into memory and perform some basic human resources operations. This assignment will help you practice: multiple file programming, classes, public and private methods, dynamic memory allocation, constructors and destructors, linked list and files.
## Implementation
This lab assignment gives you the opportunity to practice creating classes and using dynamic memory in one of the required classes.
There are two classes to implement `Employee` and `Company`. As you can see in the description table, `Company` will hold a linked list of `Employees`. This list of employees is modeled using linked nodes of `Employee*` (pointers to Employees). These employees are created dynamically when they are added to the list.

You will create the following files:
- `menu.cpp`: contains your main function
- `employee.h`: contains the Employee class declaration (No changes)
- `employee.cpp`: contains the Employee class method definitions (No changes)
- `company.h`: contains the Company class declaration (Major changes)
- `company.cpp`: contains the Company class method definitions (Major changes)

The following files are provided:
- `makefile` if you want to use the `make` utility this will help you considerably compiling your program from the command line.
- `main.cpp` holds the unit tests for this lab, below it is explained how to compile using this file.
- Four test files to test different scenarios


NOTE: Be careful ***not*** to have two main files in your `CMakeList.txt` file in CLion, as this will prevent the linker to compile your program.

### Class Descriptions

**Employee**

*Notice there are no changes from previous `Employee` implementation*

| Access | Member | Description |
|--------|--------|-----------|
Private | `_id: unsigned int` | ID
Private | `_name: string` | Name
Private | `_salary: double`| Salary
Private | `_managerId: unsigned int` | Manager ID
Public | `Employee(unsigned int, const string&, double, unsigned int=0` | Creates an employee using the values given by the parameters. The last parameter represents the manager ID. If the name parameter is an empty string, the constructor should initialize the name to “***”
Public | `Employee(const Employee&)` | Copy constructor for Employee
Public | `GetID(): unsigned int` | Accessor for ID
Public | `GetName(): string` | Accessor for name
Public | `GetSalary():double` | Accessor for salary
Public | `GetManagerId(): unsigned int`| Accessor for Manager ID
Public | `ToString():string` | Returns a string representation of the Employee. (see after the table for the details on this method)
Public | `Raise(double):void` | Gives a raise to the employee, adding the specified amount to his or her current salary.
Public | `Equals(const Employee&)`| Returns true if the employee specified by the parameter has same ID as current object.
Public | `Read(istream&):bool` |  Reads an employee from the `istream` returning `true`/`fals`e depending on whether read was successful.
Public | `Write(ostream&):void` | Writes the information about an employee, separated by spaces, to the `ostream`.
Public | `~Employee()`| Destructor, empty

**Company**

| Access | Member | Description |
|--------|--------|-----------|
Private | `struct Node{Employee* data; Node* next; }` |	Represents the node type that will become each of the links of the linked list.
Private | `_head: Node*` | Head of the list, is the pointer to the first element of the list.
Private | `_size: unsigned int` | The number of actual employees in the list. In the beginning, there are no employees.
Private | `Company(const Company&)` | Copy constructor private to prevent copies from 'outside' the class.
Public | `Company()` | Constructor for Company. Sets the `_size` to zero, initializes `_head` to `nullptr`.
Public | `AddEmployee(unsigned int, const string&, double, unsigned int=0): bool` | Adds an employee to the list (to the correct position, the list *must always be sorted*). The parameters specify the information about the employee. Returns `true` if it was able to add it, `false` otherwise.
Public | `AddEmployee(const Employee&): bool` | Adds the specified employee to the list(to the correct position, the list *must always be sorted*). Returns `true` if it was able to add it, `false` otherwise.
Public | `FindById(unsigned int): int` | Uses binary search to find an employee using the ID given in the parameter. Returns -1 if the employee is not found. If it is found returns the position of that employee.
Public | `FindByName(const string&, unsigned int=0): int` | Uses linear search starting from the position specified by the second parameter to find the first occurrence of the given name in the Array. Returns -1 if the employee is not found. If it is found returns the position of that employee.
Public | `Read(istream&):int` | Reads an `istream` and extracts all the employees’ data from there, and adds the employees to existing list of employees. Returns the number of employees read.
Public | `Write(ostream&):int` | Writes all the available employees to the `ostream`. Returns the number of employees written.
Public | `IsFull():bool` | Always returns `false`.
Public | `Get(unsigned int): Employee*` | Returns a pointer to the `Employee` at the position specified by the parameter. If the position is invalid, it returns `nullptr`. The referenced object belongs to the object and should not be “deleted” by the client.
Public | `GetEmployeeCount():unsigned int` | Returns the number of employees in the Company (`_size`)
Public | `~Company()`|Frees the memory by releasing all the dynamically created employees in the array.

Employee::ToString(), returns a formatted string following the following format:

`ID:    1 Name: Peter      Salary:        250 Manager ID:    0`

Widths:
- ID: 4
- Name: 10
- Salary: 10
- Manager ID: 4

### Program Menu

Your program should output the following menu:

```
1. Load from File
2. Save to File
3. List all Employees
4. Search by Name
5. Search by ID
6. Find Employee Boss Information
7. Add new Employee
8. Check if Database is Full
9. Exit
```

|Menu Option |  Description  |
-------------|----------------
Load a Company File | Asks the user for the file name containing the employee’s information. TXT files containing sample company information are included with this Lab document.
Save Company Data to File | Saves the current information in memory to a file. The program asks the user for the file name where the user wants to save this.
 List all Employees | Lists all the employees stored in memory. Uses company `ToString` method to display them.
 Search by Name | The user inputs a name, then, using the method `FindFirstByName` the program displays ***all*** employees with that name using `ToString` method.
Search by ID | The user inputs an ID, then, using the method `FindById` the program displays the employee with that ID using `ToString` method or that it did not find that ID.
Find Employee Boss Information| The user inputs an ID, then, using the method `FindById` the program displays the employee ID using `GetID` method or that it did not find that ID. Once the employee is found, gets the manager’s ID, and with it searches that ID and gets the manager’s rest of the information. Displays the manager information using `ToString` method.
Add New Employee | Requests the user to enter the following information about the employee: ID, name, salary and manager ID. Manager ID is zero for employees without boss. Only adds employees if it fits in the array! Only adds employees with ID that is not already in the list
Check if Database is Full| Displays a message indicating if the database is full, or not full.
Exit| Exits the program

## Error Handling
Your program should validate all input and check whether it was able to open files for the file operations. Your program should not crash.

## Programming Style
Please refer to all previous Lab documents for appropriate style. Here are some additional style rule:
- Use the const modifiers appropriately. Make sure methods that should be declared const are declared const.
- Prefix the identifiers for class data members with _ (underscore)

## Running your code
You can run and test your program from within CLion, but your final tests should be done in the command line following the next steps:
1. Move to the directory where your source files are.
1. Compile using the following command: `g++ -std=c++14 -Wall menu.cpp company.cpp employee.cpp -o company`. If you want you can run the `make` program by just typing `make` and hit enter. The `make` utility will read the provided makefile and will compile everything you need and produce the `company` executable.
1. The previous command will create an executable named `company`
1. Run `company`, test the operations with the sample operations shown at the end of this document. NOT ALL SCENARIOS ARE TESTED BY THESE SAMPLE RUNS. YOU MUST MAKE SURE YOUR PROGRAM WORKS IN CASES, NOT JUST FOR THESE SAMPLE RUNS.
1. Run the unit tests
   1. Compile the program using the following command: `g++ -std=c++14 -Wall main.cpp company.cpp employee.cpp -o test`. If you want you can run the `make` program by just typing `make test` and hit enter. The `make` utility will read the provided makefile and will compile everything you need and produce the `test` executable.
   1. Run `test`, the output should be:
   ```
   Employee Tests Passed Successfully
   Initial Company Tests Passed Successfully
   Company Test with Empty File Passed Successfully
   Company Test with Data File (1) Passed Successfully
   Company Test with Data File (2) Passed Successfully
   Congratulations you passed all the tests!
   ```

Once you tested both your menu program and the unit tests you are ready to push your changes to GitHub.

## Academic Integrity
Academic Integrity
This programming assignment is to be done on an individual basis. At the same time, it is understood that learning from your peers is valid and you are encouraged to talk among yourselves about programming in general and current assignments in particular.  Keep in mind, however, that each individual student must do the work in order to learn.  Hence, the following guidelines are established:
- Feel free to discuss any and all programming assignments but do not allow other students to look at or copy your code. Do not give any student an electronic or printed copy of any program you write for this class.
- Gaining the ability to properly analyze common programming errors is an important experience. Do not deprive a fellow student of his/her opportunity to practice problem solving: control the urge to show them what to do by writing the code for them.
- If you’ve given the assignment a fair effort and still need help, see the instructor or a lab assistant.
- **If there is any evidence that a program or other written assignment was copied from another student, neither student will receive any credit for it. This rule will be enforced.**
- Protect yourself: Handle throw-away program listings carefully, keep your repository private.

Refer to the ECS Department Policy on Academic Integrity that is included in the class syllabus.

## Grading Rubric Summary
The unit tests have the bigger weight on the grading for this assignment, if you are able to pass the unit tests, the rest of the program should work correctly.


## Sample Output:
```
ML-ARIAS:employee-list-fixed-array-full arias$ make
g++ -c menu.cpp -std=c++14 -Wall
g++ -c company.cpp -std=c++14 -Wall
g++ -c employee.cpp -std=c++14 -Wall
g++ menu.o company.o employee.o -o company -std=c++14 -Wall
ML-ARIAS:employee-list-fixed-array-full arias$ ./company
1. Load from File
2. Save to File
3. List all Employees
4. Search by Name
5. Search by ID
6. Find Employee Boss Information
7. Add new Employee
8. Check if Database is Full
9. Exit

1
Input filename: notfound.txt
Unable to open the file notfound.txt
1. Load from File
2. Save to File
3. List all Employees
4. Search by Name
5. Search by ID
6. Find Employee Boss Information
7. Add new Employee
8. Check if Database is Full
9. Exit

1
Input filename: employees1.txt
9 Records read from file employees1.txt
1. Load from File
2. Save to File
3. List all Employees
4. Search by Name
5. Search by ID
6. Find Employee Boss Information
7. Add new Employee
8. Check if Database is Full
9. Exit

3
ID:    1 Name: Peter      Salary:        250 Manager ID:    0
ID:    2 Name: Dio        Salary:        100 Manager ID:    0
ID:    3 Name: Silvia     Salary:        150 Manager ID:    1
ID:    4 Name: Leonel     Salary:       1801 Manager ID:    0
ID:    5 Name: Jon        Salary:       3500 Manager ID:    1
ID:    9 Name: Jon        Salary:       4100 Manager ID:    2
ID:   10 Name: Anna       Salary:       2250 Manager ID:    2
ID:   11 Name: Melissa    Salary:       1450 Manager ID:    1
ID:   16 Name: Nicole     Salary:         50 Manager ID:    0
1. Load from File
2. Save to File
3. List all Employees
4. Search by Name
5. Search by ID
6. Find Employee Boss Information
7. Add new Employee
8. Check if Database is Full
9. Exit

4
Search for name: Jon
ID:    5 Name: Jon        Salary:       3500 Manager ID:    1
ID:    9 Name: Jon        Salary:       4100 Manager ID:    2
1. Load from File
2. Save to File
3. List all Employees
4. Search by Name
5. Search by ID
6. Find Employee Boss Information
7. Add new Employee
8. Check if Database is Full
9. Exit

4
Search for name: Olga
Name not found on database
1. Load from File
2. Save to File
3. List all Employees
4. Search by Name
5. Search by ID
6. Find Employee Boss Information
7. Add new Employee
8. Check if Database is Full
9. Exit

5
Search for ID: 5
ID:    5 Name: Jon        Salary:       3500 Manager ID:    1
1. Load from File
2. Save to File
3. List all Employees
4. Search by Name
5. Search by ID
6. Find Employee Boss Information
7. Add new Employee
8. Check if Database is Full
9. Exit

5
Search for ID: 7
7 not found
1. Load from File
2. Save to File
3. List all Employees
4. Search by Name
5. Search by ID
6. Find Employee Boss Information
7. Add new Employee
8. Check if Database is Full
9. Exit

6
Search for ID: 5
Employee with ID: 5 has manager:
	ID:    1 Name: Peter      Salary:        250 Manager ID:    0
1. Load from File
2. Save to File
3. List all Employees
4. Search by Name
5. Search by ID
6. Find Employee Boss Information
7. Add new Employee
8. Check if Database is Full
9. Exit

99
Incorrect menu option!
1. Load from File
2. Save to File
3. List all Employees
4. Search by Name
5. Search by ID
6. Find Employee Boss Information
7. Add new Employee
8. Check if Database is Full
9. Exit

incorrect
Incorrect input!
1. Load from File
2. Save to File
3. List all Employees
4. Search by Name
5. Search by ID
6. Find Employee Boss Information
7. Add new Employee
8. Check if Database is Full
9. Exit

7
Input Employee Information
Employee id: 5
ID already exists!
Do you want to add use another ID yes
Input Employee Information
Employee id: 5
ID already exists!
Do you want to add use another ID no
1. Load from File
2. Save to File
3. List all Employees
4. Search by Name
5. Search by ID
6. Find Employee Boss Information
7. Add new Employee
8. Check if Database is Full
9. Exit

7
Input Employee Information
Employee id: 7
Employee name: Grace
Employee salary: 1300
Employee's Boss ID: 2
Employee added successfully
1. Load from File
2. Save to File
3. List all Employees
4. Search by Name
5. Search by ID
6. Find Employee Boss Information
7. Add new Employee
8. Check if Database is Full
9. Exit

3
ID:    1 Name: Peter      Salary:        250 Manager ID:    0
ID:    2 Name: Dio        Salary:        100 Manager ID:    0
ID:    3 Name: Silvia     Salary:        150 Manager ID:    1
ID:    4 Name: Leonel     Salary:       1801 Manager ID:    0
ID:    5 Name: Jon        Salary:       3500 Manager ID:    1
ID:    7 Name: Grace      Salary:       1300 Manager ID:    2
ID:    9 Name: Jon        Salary:       4100 Manager ID:    2
ID:   10 Name: Anna       Salary:       2250 Manager ID:    2
ID:   11 Name: Melissa    Salary:       1450 Manager ID:    1
ID:   16 Name: Nicole     Salary:         50 Manager ID:    0
1. Load from File
2. Save to File
3. List all Employees
4. Search by Name
5. Search by ID
6. Find Employee Boss Information
7. Add new Employee
8. Check if Database is Full
9. Exit

7
Database is full
1. Load from File
2. Save to File
3. List all Employees
4. Search by Name
5. Search by ID
6. Find Employee Boss Information
7. Add new Employee
8. Check if Database is Full
9. Exit

8
Database is Full
1. Load from File
2. Save to File
3. List all Employees
4. Search by Name
5. Search by ID
6. Find Employee Boss Information
7. Add new Employee
8. Check if Database is Full
9. Exit

9
```
