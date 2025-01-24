#pragma once
#include <fstream>
#include <string>
#include "filesNames.h"
#include "Fileparser.h"

class FilesHelper
{
public:
    static void saveLast(string last_id_file, int id)
    {

        clearLastidFile(last_id_file);

        ofstream outFile(last_id_file, ios::out);

        if (!outFile)
        {
            cerr << "Last ID file could not be found!" << endl;
            return;
        }

        outFile << id << endl;

        outFile.close();
        return;
    }

    static int getLast(string fileName)
    {
        string line;
        ifstream myfile(fileName);

        if (myfile.is_open())
        {
            getline(myfile, line);

            myfile.close();
        }
        return stoi(line);
    }

    static void saveClient(Client c)
    {
        string name = c.get_name();
        int id = c.get_id();
        string pass = c.get_password();
        double balance = c.get_balance();

        ofstream outFile(clientsData, ios::app);

        if (!outFile)
        {
            cerr << "Client data file could not be found!" << endl;
            return;
        }

        outFile << id << "-" << name << "-" << pass << "-" << balance << endl;

        outFile.close();

        saveLast(clientsLastId, id);
        return;
    }

    static void saveEmployee(string fileName, string last_id, Employee &e)
    {
        string name = e.get_name();
        int id = e.get_id();
        string pass = e.get_password();
        double salary = e.get_salary();

        ofstream outFile(fileName, ios::app);

        if (!outFile)
        {
            cerr << "File could not be found!" << endl;
            return;
        }
        outFile << id << "-" << name << "-" << pass << "-" << salary << endl;

        outFile.close();
        saveLast(last_id, id);
        return;
    }

    static void clearFile(string fileName, string lastIdFile)
    {
        ofstream outlastidfile(lastIdFile, ios::out | ios::trunc);

        if (!outlastidfile)
        {
            cerr << "Last ID file could not be found!" << endl;
            return;
        }

        ofstream outnamefile(fileName, ios::out | ios::trunc);

        if (!outnamefile)
        {
            cerr << "Data File could not be found!" << endl;
            return;
        }
    }

    static void clearLastidFile(string lastIdFile)
    {
        ofstream outfile(lastIdFile, ios::out | ios::trunc);

        if (!outfile)
        {
            cerr << "File could not be opened!" << endl;
            return;
        }
    }

    static void getClients()
    {
        int i = 0;
        string line;
        ifstream myfile(clientsData);

        while (getline(myfile, line))
        {
            allclients.push_back(parser::parse_to_client(line));
            i++;
        }
        myfile.close();
    }
    static void getEmployees()
    {
        int i = 0;
        string line;
        ifstream myfile(employeesData);

        while (getline(myfile, line))
        {
            allEmployee.push_back(parser::parse_to_employee(line));
            i++;
        }
        myfile.close();
    }
    static void getAdmins()
    {
        int i = 0;
        string line;
        ifstream myfile(adminsData);

        while (getline(myfile, line))
        {
            allAdmins.push_back(parser::parse_to_admin(line));
            i++;
        }
        myfile.close();
    }
};
