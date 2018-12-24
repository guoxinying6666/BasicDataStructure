/*
 * Patient.cpp
 *
 * Implementation for Patient class
 * 
 * COMP15
 * Spring 2018
 * Lab 4
 */

#include <iostream>
#include "Patient.h"
using namespace std;

// Default constructor
Patient::Patient()
{
    fname = "Jane";
    lname = "Doe";
    chest_pain = false;
    head_wound = false;
    temp = 98.6;
    pulse = 0;
    priority = FIVE;
}

// Parameterized constructor
Patient::Patient(string f, string l)
{
    fname = f;
    lname = l;
}

// Overloading comparison operators
bool operator < (const Patient &p1, const Patient &p2)
{
    if (p1.priority < p2.priority)
        return true;
    else
        return false;
}

bool operator > (const Patient &p1, const Patient &p2)
{
    if (p1.priority > p2.priority)
        return true;
    else 
        return false;    
}

// Print the patient
ostream & operator << (ostream &out, const Patient &p)
{
    out << p.fname << " " << p.lname << endl;
    out << ((p.head_wound) ? "Head wound\n" : "");
    out << ((p.chest_pain) ? "Chest pain\n" : "");
    out << "Pulse: " << p.pulse << endl;
    out << "Temp: " << p.temp << endl;
    out << "PRIORITY " << p.priority << endl;
    return out;
}


