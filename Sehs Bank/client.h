#pragma once
#include "validation.h"
#include "person.h"
#include <vector>

class Client : public Person
{

private:
    double balance;

public:
    Client(string name, string password, int id, double balance) : Person(name, password, id), balance(balance) {}

    void set_balance(double balance)
    {
        Client::balance = balance;
    }

    double get_balance()
    {
        return balance;
    }

    //////////////////////////
    void deposit(double amount)
    {
        balance += amount;
    }

    void withdraw(double amount)
    {
        balance -= amount;
    }

    void transferTo(double amount, Client &recipient)
    {
        this->withdraw(amount);
        recipient.deposit(amount);
    }

    void checkBalance()
    {
        cout << "Balance: " << balance << endl;
    }

    void displayInfo()
    {
        Person::displayInfo();
        cout << "Balance: " << balance << endl;
        cout<<"---------------------------------\n";
    }
};

static vector<Client> allclients;
