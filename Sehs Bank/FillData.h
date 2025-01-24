#ifndef FILLDATA_H
#define FILLDATA_H
#include <iostream>
using namespace std;
#include "validation.h"
#include "FilesHelper.h"

class FillData
{
public:
    static string set_password()
    {
        string password;
        cout << "Enter the password: ";
        cin >> password;
        while (!Validation::valid_pass(password))
        {
            cout << "Invalid password!" << endl
                 << "Password must be with min size 8 and max size 20 without spaces : ";
            cin >> password;
        }
        return password;
    }

    static string set_name()
    {
        string name;
        cout << "Enter the user name: ";
        cin >> name;
        while (!Validation::valid_name(name))
        {
            cout << "Invalid name!" << endl
                 << "Name must be with min size 5 and max size 20 and only alphabetic: ";
            cin >> name;
        }
        return name;
    }

    static double set_balance()
    {
        double balance;
        cout << "Enter the value of the balance: ";
        balance = Validation::valid_number();
        while (!Validation::valid_balance(balance))
        {
            cout << "Invalid balance!" << endl
                 << "Please, enter valid balance: ";
            balance = Validation::valid_number();
        }
        return balance;
    }

    static double set_salary()
    {
        double salary;
        cout << "Enter the value of the salary: ";
        salary = Validation::valid_number();
        while (!Validation::valid_salary(salary))
        {
            cout << "Invalid salary amount!" << endl
                 << "Please, try again with minimum 5000: ";
            salary = Validation::valid_number();
        }
        return salary;
    }

    static int last_client_id()
    {
        return (allclients.size());
    }

    static int last_employee_id()
    {
        return (allEmployee.size());
    }

    static int last_admin_id()
    {
        return (allAdmins.size());
    }
};

#endif // FILLDATA_H
