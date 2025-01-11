#pragma once


#include <iostream>

using namespace std;


class clsPersonne
{
    string _Name;
    string _LastName;
    string _Email;
    string _Phone;

public:
    // this way is constractor
    clsPersonne(string name,string lastname,string email,string phone)
    {
        _Name = name;
        _LastName = lastname;
        _Email = email;
        _Phone = phone;
    }

    void setName(string name)
    {
        _Name = name;
    }

    void setLastName(string lastName)
    {
        _LastName = lastName;
    }

    void setEmail(string email)
    {
        _Email = email;
    }

    void setPhone(string phone)
    {
        _Phone = phone;
    }

    string Name()
    {
        return (_Name);
    }

    string LastName()
    {
        return (_LastName);
    }

    string FullName()
    {
        return (Name() + " " + LastName());
    }

    string Email()
    {
        return (_Email);
    }

    string Phone()
    {
        return (_Phone);
    }


};