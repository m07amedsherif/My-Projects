#ifndef VALIDATION_H
#define VALIDATION_H
#include <bits/stdc++.h>
using namespace std;

class Validation
{
public:
    static bool isAlphabetic(string word)
    {

        bool alpha = true;

        for (int i = 0; i < word.size(); i++)
        {

            if (!isalpha(word[i]) && word[i] != ' ')
            {
                return false;
            }
        }

        return true;
    }

    static bool valid_name(string word)
    {
        if (word.size() < 5 || word.size() > 20 || !(isAlphabetic(word)))
        {
            return false;
        }

        return true;
    }

    static bool valid_pass(string word)
    {

        if (word.size() < 8 || word.size() > 20)
        {
            return false;
        }

        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == ' ')
            {
                return false;
            }
        }

        return true;
    }

    static bool valid_balance(double balance)
    {
        return (balance >= 1500);
    }

    static bool valid_salary(double salary)
    {
        return (salary >= 5000);
    }

   static bool valid_deposit_amount(double amount)
    {
        return (amount > 0);
    }

   static bool valid_withdraw_amount(double amount, double balance)
    {
        return (amount <= balance && amount >= 0);
    }

    static double valid_number()
    {
        double amount;
        cin >> amount;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, please enter a valid number: ";
            cin >> amount;
        }
        return amount;
    }

    static int valid_choice(int first, int last)
    {
        cout << "Enter A Number Between " << first << " And " << last << ": " << endl;
        cout << "Enter Your Choice: ";
        int choice = valid_number();
        if (choice < first || choice > last)
        {
            choice = valid_choice(first, last);
        }
        return choice;
    }

};
#endif // VALIDATION_H
