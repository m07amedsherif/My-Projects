#ifndef SCREENS_H
#define SCREENS_H
#include "ClientManger.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
class Screens
{
public:
    static void bankName()
    {
        cout << "\t\t@@@@@@@   @@@@@@@   @@   @@    @@@@@@@      #######   ########  ####     ##  ##   ##\n";
        cout << "\t\t@@        @@        @@   @@    @@           ##    ##  ##    ##  ## ##    ##  ##  ##\n";
        cout << "\t\t@@@@@@@   @@@@@@@   @@@@@@@    @@@@@@@      #######   ########  ##  ##   ##  ## #\n";
        cout << "\t\t     @@   @@        @@   @@         @@      ##    ##  ##    ##  ##   ##  ##  ##  ##\n";
        cout << "\t\t@@@@@@@   @@@@@@@   @@   @@    @@@@@@@      #######   ##    ##  ##    ####   ##   ##\n";
    }

    static void welcome()
    {
        system("cls");
        system("Color 07");
        cout << "\n\n\n\n\n\n";
        cout << "\t\t      ##       ##   #######   ##      #######  ########    ####    ####   #######\n";
        cout << "\t\t      ##   #   ##   ##        ##      ##       ##    ##    ##  #  #  ##   ##\n";
        cout << "\t\t      ##  ###  ##   ######    ##      ##       ##    ##    ##   ##   ##   #######\n";
        cout << "\t\t      ## ## ## ##   ##        ##      ##       ##    ##    ##        ##   ##\n";
        cout << "\t\t      ###     ###   #######   ######  #######  ########    ##        ##   #######\n\n\n";
        bankName();
    }

    static int loginOptions()
    {
        cout << "\n\n-------------------------------------------\n\n";
        cout << "Log in as:" << endl;
        cout << "[1]- Client\n[2]- Employee\n[3]- Admin\n[4]- Exit\n";
        return (Validation::valid_choice(1, 4));
    }

    static void loginAs()
    {
        bool login_state = false;

        FileManager f;
        f.getAllAdmins();
        f.getAllEmployees();
        f.getAllClients();

        while (true)
        {

            welcome();
            int choice = loginOptions();
            int id = 0;
            string password = "";
            if (choice != 4)
            {
                pair<int, string> p = login_data();
                id = p.first;
                password = p.second;
            }


            switch (choice)
            {
            case 1:
                login_state = ClientManger::login(id, password);
                break;
            case 2:
                login_state = EmployeeManager::login(id, password);
                break;
            case 3:
                login_state = AdminManager::login(id, password);
                break;
            case 4:
                cout << "Happy to help you!\n\n\n";
                return;
                break;
            }

            if (login_state == true)
            {
                f.saveallAdmins();
                f.saveallclients();
                f.saveallEmployee();
            }
        }
    }

    static pair<int, string> login_data()
    {
        bool flag = true;
        pair<int, string> p;
        cout << "Enter ID: ";
        int id = Validation::valid_number();
        string password = FillData::set_password();
        p = {id, password};
        return p;
    }

    static void runApp()
    {
        loginAs();
    }
};

#endif // SCREENS_H
