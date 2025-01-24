#pragma once
#include "validation.h"
#include "person.h"
#include <vector>
#include <iostream>
using namespace std;
// #include "person.h"
// #include "Employee.h"

class Admin : public Employee
{

public:
    Admin(string name, string password, int id, double salary)
        : Employee(name, password, id, salary) {}

    void addEmployee(Employee &employee)
    {
        allEmployee.push_back(employee);
    }

    Employee *searchEmployee(int id)
    {
        for (int i = 0; i < allEmployee.size(); i++)
        {
            if (allEmployee[i].get_id() == id)
            {
                return &allEmployee[i];
            }
        }
        cout << "Employee not found.\n";
        return nullptr;
    }

    void editEmployee(int id, string name, string password, double salary)
    {
        Employee *employee = searchEmployee(id);
        if (employee != nullptr)
        {
            employee->setName(name);
            employee->set_password(password);
            employee->set_salary(salary);
        }
        else
        {
            return;
        }
    }

    void listEmployee()
    {
        for (int i = 0; i < allEmployee.size(); i++)
        {
            allEmployee[i].displayInfo();
        }
    }
};

static vector<Admin> allAdmins;