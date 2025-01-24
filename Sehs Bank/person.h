#pragma once
#include "validation.h"
#include <iostream>
using namespace std;
class Person
{
protected:
    string name;
    string password;
    int id;

public:
    Person(string name, string password, int id)
        : name(name), password(password), id(id) {};

    ////////////Setters///////////////
    void setName(string name)
    {
        Person:: name = name;
    }

    void set_password(string password)
    {
        Person:: password = password;
    }

    void set_id(int id)
    {
        Person:: id = id;
    }

    ////////////Getters///////////////
    string get_name()
    {
        return name;
    }

    string get_password()
    {
        return password;
    }

    int get_id()
    {
        return id;
    }

    ////////////Informations///////////////
    virtual void displayInfo()
    {
        cout << "Name: " << name << endl
             << "ID: " << id << endl;
    }
};
