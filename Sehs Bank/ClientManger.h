#pragma once
#include "client.h"
#include "FillData.h"
#include "FileManager.h"

class ClientManger
{
public:
    static int printClientMenu()
    {
        system("cls");
        cout << "[1]- Display Your Data\n"
             << "[2]- Check Balance\n"
             << "[3]- Update Password\n"
             << "[4]- Deposit\n"
             << "[5]- Withdraw\n"
             << "[6]- Transfer Money\n"
             << "[7]- Log out\n";

        double choice = Validation::valid_choice(1, 7);

        return (choice);
    }

    static void updatePassword(Client *person)
    {
        person->set_password(FillData::set_password());
        cout << "Operation done successfully!\n";
    }

    static bool login(int id, string password)
    {
        Client *ptr = nullptr;
        for (int i = 0; i < allclients.size(); i++)
        {
            if (allclients[i].get_id() == id && allclients[i].get_password() == password)
            {
                ptr = &allclients[i];
                system("cls");
                system("Color 02");
                cout << "Welcome back " << ptr->get_name() << endl;
                system("pause");
                system("Color 07");
                clientOptions(ptr);
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

    static void deposit_operation(Client *c)
    {
        bool flag = true;
        do
        {
            double amount;
            cout << "\nNOTE: The amount of money has to be more than 0.\n";
            cout << "Enter the amount of money to deposit: ";

            amount = Validation::valid_number();

            if (!Validation::valid_deposit_amount(amount))
            {
                cout << "Invalid amount.\nThe amount has to be more than 0.";
                cout << "[1]- Reenter amount.\n[2]- Go to the previous menu.\n";
                cout << "Enter your choice: ";
                double choice = Validation::valid_choice(1, 2);

                if (choice == 2)
                {
                    flag = false;
                }
            }
            else
            {
                c->deposit(amount);
                cout << "Operation is done successfully!\n";
                flag = false;
            }

        } while (flag);
    }

    static void withdraw_operation(Client *c)
    {
        bool flag = true;
        do
        {
            double amount;
            cout << "\nNOTE: The amount of money has to be less than your balance.\n";
            cout << "Enter the amount of money to withdraw: ";

            amount = Validation::valid_number();

            if (!Validation::valid_withdraw_amount(amount, c->get_balance()))
            {
                cout << "Invalid amount.\nThe amount has to be more that zero and less than your balance.";
                cout << "[1]- Reenter the amount.\n[2]- Go to the previous menu.\n";
                cout << "Enter you choice: ";
                double choice = Validation::valid_choice(1, 2);

                if (choice == 2)
                {
                    flag = false;
                }
            }
            else
            {
                c->withdraw(amount);
                cout << "Operation is done successfully!\n";
                flag = false;
            }

        } while (flag);
    }

    static void transfer_operation(Client *c)
    {
        bool flag = true;
        do
        {
            double amount;
            cout << "\nNOTE: The amount of money has to be less than your balance.\n";
            cout << "Enter the amount of money to transfer: ";

            amount = Validation::valid_number();

            bool first_check = true;

            if (!Validation::valid_withdraw_amount(amount, c->get_balance()))
            {
                cout << "Invalid amount.\nThe amount has to be less than your balance.";
                cout << "[1]- Reenter the amount.\n[2]- Go to the previous menu.\n";
                cout << "Enter you choice: ";
                double choice = Validation::valid_choice(1, 2);

                if (choice == 2)
                {
                    flag = false;
                }
                first_check = false;
            }

            bool second_check = true;
            int id;
            if (first_check)
            {
                cout << "Enter the ID of the client to transfer the money to: ";
                id = Validation::valid_number();

                if (id > FillData::last_client_id() || id < 0)
                {
                    cout << "Could not find the account!\n";
                    cout << "[1]- Repeat the operation.\n[2]- Go to the previous menu.\n";
                    cout << "Enter you choice: ";
                    double choice = Validation::valid_choice(1, 2);

                    if (choice == 2)
                    {
                        flag = false;
                    }
                    second_check = false;
                }
            }

            if (first_check && second_check)
            {
                c->withdraw(amount);
                allclients[id - 1].deposit(amount);
                cout << "Operation done successfully!\n";
                flag = false;
            }

        } while (flag);
    }

    static void clientOptions(Client *client)
    {
        bool flage = true;
        while (flage)
        {
            int choice = printClientMenu();
            system("cls");
            switch (choice)
            {
            case 1:
                client->displayInfo();
                break;
            case 2:
                client->checkBalance();
                break;
            case 3:
                updatePassword(client);
                break;
            case 4:
                deposit_operation(client);
                break;
            case 5:
                withdraw_operation(client);
                break;
            case 6:
                transfer_operation(client);
                break;
            case 7:
                // flage = false;
                return;
                break;
            }
            system("pause");
        }
    }
};
