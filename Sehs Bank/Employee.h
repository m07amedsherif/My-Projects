#pragma once
#include "validation.h"
#include "person.h"
#include <vector>

class Employee : public Person
{
protected:
    double salary;

public:
    Employee(string name, string password, int id, double salary)
        : Person(name, password, id), salary(salary)
    {
    }

    bool set_salary(double salary)
    {
        if (Validation::valid_salary(salary))
        {
            this->salary = salary;
            return true;
        }
        cout << " invalid input" << endl;
        return false;
    }

    double get_salary()
    {
        return salary;
    }

    void displayInfo()
    {
        Person::displayInfo();
        cout << "Salary : " << salary << endl;
        cout << "--------------------------------\n";
    }

    void addClient(const Client &client)
    {
        allclients.push_back(client);
        
    }

    void editClient(int id, string name, string password, double balance)
    {

        Client *client = searchClient(id);
        if (client != nullptr)
        {
            client->setName(name);
            client->set_password(password);
            client->set_balance(balance);
        }
        else
        {
            return;
        }
    }

    Client *searchClient(int id)
    {
        for (int i = 0; i < allclients.size(); i++)
        {
            if (allclients[i].get_id() == id)
            {
                return &allclients[i];
            }
        }
        cout<<"Client not found !\n";
        return nullptr;
    }
    void listClient()
    {
        for (int i = 0; i < allclients.size(); i++)
        {
            allclients[i].displayInfo();
        }
    }
};

static vector<Employee> allEmployee;