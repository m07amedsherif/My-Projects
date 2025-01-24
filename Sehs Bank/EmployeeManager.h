#pragma once
#include "client.h"
#include "Employee.h"
#include "FillData.h"

class EmployeeManager
{
private:
    static double printEmployeeMenu()
    {
        system("cls");
        cout << "[1]-Display Your Data \n"
             << "[2]-Check Salary\n"
             << "[3]-Update Password\n"
             << "[4]-Add New Client\n"
             << "[5]-Search Client\n"
             << "[6]-List All Clients\n"
             << "[7]-Edit Client\n"
             << "[8]-Log out\n";
        double choice = Validation::valid_choice(1, 8);

        return (choice);
    }

public:
    static void updatePassword(Employee *person)
    {
        person->set_password(FillData::set_password());
        cout << "Operation done successfully!\n";
    }
    static void employeeOptions(Employee *employee)
    {

        while (true)
        {
            int choice = printEmployeeMenu();
            system("cls");
            switch (choice)
            {
            case 1:
                employee->displayInfo();
                break;
            case 2:
                cout << "Salary: " << employee->get_salary() << endl;
                break;
            case 3:
                updatePassword(employee);
                break;
            case 4:
                AddnewClient(employee);

                break;
            case 5:
                searchForCLient(employee);

                break;
            case 6:
                employee->listClient();

                break;
            case 7:
                editClientInfo(employee);

                break;
            case 8:
                return;
                break;
            }
            system("pause");
        }
    }

    static void AddnewClient(Employee *employee)
    {
        string name, password;
        double balance;

        int id;
        name = FillData::set_name();
        password = FillData::set_password();
        balance = FillData::set_balance();
        id = allclients.size() + 1;
        Client c(name, password, id, balance);
        employee->addClient(c);
        cout << "Client added successfully!\n";
    }

    static void listAllClients(Employee *employee)
    {
        employee->listClient();
    }

    static void searchForCLient(Employee *employee)
    {
        int id;
        cout << "\nEnter client ID to search: ";
        cin >> id;
        Client *cli = employee->searchClient(id);
        if (cli == nullptr)
        {
            return;
        }
        else
        {

            cli->displayInfo();
        }
    }

    static void editClientInfo(Employee *employee)
    {
        int id;
        bool flag = true;
        while (flag)
        {
            cout << "\nEnter client ID to edit: ";
            cin >> id;
            Client *client = employee->searchClient(id);
            if (client == nullptr)
            {
                // cout << "Client not found !\n";
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
                double balance = FillData::set_balance();
                employee->editClient(id, name, password, balance);
                cout << "Data updated successfully \n";
                return;
            }
        }
    }

    static bool login(int id, string password)
    {
        Employee *ptr = nullptr;
        for (int i = 0; i < allEmployee.size(); i++)
        {
            if (allEmployee[i].get_id() == id && allEmployee[i].get_password() == password)
            {
                ptr = &allEmployee[i];
                system("cls");
                system("Color 02");
                cout << "Welcome back " << ptr->get_name() << endl;
                system("pause");
                system("Color 07");
                employeeOptions(ptr);
                return true;
            }
        }
        system("cls");
        system("Color 04");
        cout << "Could not find the Employee!\n";
        system("pause");
        system("Color 07");
        return false;
    }
};