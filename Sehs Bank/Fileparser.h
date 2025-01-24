#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class parser
{
public:
    static vector<string> split(string line)
    {
        stringstream parse(line);
        string token;
        vector<string> parsedData;

        while (getline(parse, token, '-'))
        {

            parsedData.push_back(token);
        }
        return parsedData;
    }

    static Client parse_to_client(string line)
    {
        vector<string> parsed;
        parsed = split(line);

        int id;
        stringstream i;
        i << parsed[0];
        i >> id;

        stringstream d;
        double balance;
        d << parsed[3];
        d >> balance;

        Client x(parsed[1], parsed[2], id, balance);
        return x;

    }

    static Employee parse_to_employee(string line)
    {
        vector<string> parsed;
        parsed = split(line);

        int id;
        stringstream i;
        i << parsed[0];
        i >> id;

        stringstream d;
        double balance;
        d << parsed[3];
        d >> balance;

        Employee x(parsed[1], parsed[2], id, balance);
        return x;

    }

    static Admin parse_to_admin(string line)
    {
        vector<string> parsed;
        parsed = split(line);

        int id;
        stringstream i;
        i << parsed[0];
        i >> id;

        stringstream d;
        double balance;
        d << parsed[3];
        d >> balance;

        Admin x(parsed[1], parsed[2], id, balance);
        return x;

    }


};