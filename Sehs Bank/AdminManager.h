#pragma once
#include "client.h"
#include "Employee.h"
#include "FillData.h"
#include "EmployeeManager.h"
#include "Admin.h"
class AdminManager
{

public:
    static double printAdminMenu()
    {
        system("cls");
        cout << "[1]-Display Your Data \n"
             << "[2]-Check Salary\n"
             << "[3]-Update Password\n"
             << "[4]-Add New Client\n"
             << "[5]-Add New Employee\n"
             << "[6]-Search Client\n"
             << "[7]-Search Employee\n"
             << "[8]-List All Clients\n"
             << "[9]-List All Employees\n"
             << "[10]-Edit Client Data\n"
             << "[11]-Edit Employee Data\n"
             << "[12]-Log out\n";
        double choice = Validation::valid_choice(1, 12);

        return (choice);
    }

    /******** */
    static void AdminOptions(Admin *admin)
    {

        while (true)
        {
            int choice = printAdminMenu();
            system("cls");
            switch (choice)
            {
            case 1:
                admin->displayInfo();
                break;
            case 2:
                cout << "Salary: " << admin->get_salary() << endl;
                break;
            case 3:
                EmployeeManager::updatePassword(admin);
                break;
            case 4:
                EmployeeManager::AddnewClient(admin);
                break;
            case 5:
                AddNewEmployee(admin);
                break;
            case 6:
                EmployeeManager::searchForCLient(admin);
                break;
            case 7:
                searchForEmployee(admin);
                break;
            case 8:
                admin->listClient();
                break;
            case 9:
                admin->listEmployee();

                break;
            case 10:
                EmployeeManager::editClientInfo(admin);
                break;
            case 11:
                editEmployeeInfo(admin);
                break;
            case 12:
                return;
                break;
            }
            system("pause");
        }
    }

    /******** */
    static bool login(int id, string password)
    {
        Admin *ptr = nullptr;
        for (int i = 0; i < allAdmins.size(); i++)
        {
            if (allAdmins[i].get_id() == id && allAdmins[i].get_password() == password)
            {
                ptr = &allAdmins[i];
                system("cls");
                system("Color 02");
                cout << "Welcome back " << ptr->get_name() << endl;
                system("pause");
                system("Color 07");
                AdminOptions(ptr);
                return true;
            }
        }
        system("cls");
        system("Color 04");
        cout << "Could not find the account!\n";
        system("pause");
        system("Color 07");
        return false;
    }
    /*************** */
    static void AddNewEmployee(Admin *admin)
    {
        string name, password;
        double salary;
        int id;
        name = FillData::set_name();
        password = FillData::set_password();
        salary = FillData::set_salary();
        id = allEmployee.size() + 1;
        Employee e(name, password, id, salary);
        admin->addEmployee(e);
        cout << "Employee added successfully!\n";
    }
    /*************** */
    static void searchForEmployee(Admin *admin)
    {
        int id;
        cout << "\nEnter Employee ID to search: ";
        cin >> id;
        Employee *empl = admin->searchEmployee(id);
        if (empl == nullptr)
        {
            return;
        }
        else
        {

            empl->displayInfo();
        }
    }
    /************** */
    static void editEmployeeInfo(Admin *admin)
    {
        int id;
        bool flag = true;
        while (flag)
        {
            cout << "\nEnter employee ID to edit: ";
            cin >> id;
            Employee *employee = admin->searchEmployee(id);
            if (employee == nullptr)
            {
                // cout << "Employee not found !\n";
                cout << "Do you want try another id ?\n1-yes\n2-Return to previous Menu\n";
                int choice = Validation::valid_choice(1, 2);
                if (choice == 2)
                {
                    flag = false;
                }
            }
            else
            {
                string name = FillData::set_name();
                string password = FillData::set_password();
                double salary = FillData::set_salary();
                admin->editEmployee(id, name, password, salary);
                cout << "Data updated successfully \n";
                return;
            }
        }
    }
};