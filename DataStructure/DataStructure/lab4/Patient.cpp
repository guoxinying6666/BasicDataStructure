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
    return (p1.priority < p2.priority);
}

bool operator > (const Patient &p1, const Patient &p2)
{
    return (p1.priority > p2.priority);
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

void Patient::calculate_priority(bool chest_pain1,bool head_wound1,double temp1, unsigned pulse1)
{
    chest_pain = chest_pain1;
    head_wound = head_wound1;
    temp = temp1;
    pulse = pulse1;
    int count = 1;
    if (chest_pain == true) 
        count++;
    if (head_wound == true)
        count++;
    if (temp > 97)
        count++;
    if (pulse > 100)
        count++;
    if (count == 5)
        priority = FIVE;
    if (count == 4)
        priority = FOUR;
    if (count == 3)
        priority = THREE;
    if (count == 2)
        priority = TWO;
    if (count == 1)
        priority = ONE;
}



