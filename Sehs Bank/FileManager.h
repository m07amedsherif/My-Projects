#pragma once
#include "DataSourceInterface.h"
#include "filesNames.h"
#include "FilesHelper.h"

class FileManager : public DataSourceInterface
{

public:
    void addClient(Client c)
    {
        FilesHelper::saveClient(c);
    }
    void addEmployee(Employee e)
    {
        FilesHelper::saveEmployee(employeesData, employeesLastId, e);
    }
    void addAdmin(Admin a)
    {
        FilesHelper::saveEmployee(adminsData, adminsLastId, a);
    }
    void getAllClients()
    {
        FilesHelper::getClients();
    }
    void getAllEmployees()
    {
        FilesHelper::getEmployees();
    }
    void getAllAdmins()
    {
        FilesHelper::getAdmins();
    }
    void  removeAllClients()
    {
        FilesHelper::clearFile(clientsData, clientsLastId);
    }
    void removeAllEmployees()
    {
        FilesHelper::clearFile(employeesData, employeesLastId);
    }
    void removeAllAdmins()
    {
        FilesHelper::clearFile(adminsData, adminsLastId);
    }
    void saveallclients()
    {
        removeAllClients();
        for (int i = 0; i < allclients.size(); i++)
        {
            FilesHelper::saveClient(allclients[i]);
        }
    }
    void saveallEmployee()
    {
        removeAllEmployees();
        for (int i = 0; i < allEmployee.size(); i++)
        {
            FilesHelper::saveEmployee(employeesData, employeesLastId, allEmployee[i]);
        }
    }
    void saveallAdmins()
    {
        removeAllAdmins();
        for (int i = 0; i < allAdmins.size(); i++)
        {
            FilesHelper::saveEmployee(adminsData, adminsLastId, allAdmins[i]);
        }
    }
};
