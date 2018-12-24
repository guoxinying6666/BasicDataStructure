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
    time_in = 0;
    highest = true;
}

// Parameterized constructor
Patient::Patient(string f, string l)
{
    fname = f;
    lname = l;
}

// Overloading comparison operators
// COmpare priority and time_in
bool operator < (const Patient &p1, const Patient &p2)
{
    return (!p1.p1_first(p1, p2)) ;
}

bool operator <= (const Patient &p1, const Patient &p2)
{
    return (p1.p1_first(p2, p1));
}

bool operator >= (const Patient &p1, const Patient &p2)
{
    return (p1.p1_first(p1, p2));
}

bool operator > (const Patient &p1, const Patient &p2)
{
    return (!p1.p1_first(p2, p1));
}

bool operator == (const Patient &p1, const Patient &p2)
{
    return ((p1.priority == p2.priority) 
        && (p1.time_in == p2.time_in));
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

// Function: calculate_priority
// Input: bool chest_pain1,bool head_wound1,
//   double temp1, unsigned pulse1, unsigned time_in1, bool highest1
// Returns: void 
// Does: calculate priorirty of patients
void Patient::calculate_priority(bool chest_pain1,bool head_wound1,
    double temp1, unsigned pulse1, unsigned time_in1, bool highest1)
{
    chest_pain = chest_pain1;
    head_wound = head_wound1;
    temp = temp1;
    pulse = pulse1;
    time_in = time_in1;
    highest = highest1;
    if (!highest)
    {
        if ((chest_pain && head_wound) || (head_wound && 
            (pulse < 90)) || (chest_pain && (pulse < 90))) 
            {priority = ONE;}
        else if ((head_wound && (pulse >= 90)) || 
            (chest_pain && (pulse >= 90)))
            {priority = TWO;}
        else if (((pulse < 90) && (temp > 100) && 
            !head_wound && !chest_pain))
            {priority = THREE;}
        else if ((((temp > 100) && (pulse > 90)) || 
            ((temp < 100) && (pulse < 90))) && 
            (!head_wound && !chest_pain))
            {priority = FOUR;}
        else  
            {priority = FIVE;}
    }
    if (highest)
    {

        if ((chest_pain && head_wound) || 
            (head_wound && pulse < 90) || (chest_pain && pulse < 90)) 
            {priority = FIVE;}
        else if ((head_wound && pulse > 90) || (chest_pain && pulse > 90))
            {priority = FOUR;}
        else if ((pulse < 90 && temp > 100 && !head_wound && !chest_pain))
            {priority = THREE;}
        else if ((((temp > 100 && pulse > 90) || 
            (temp < 100 && pulse < 90))) && (!head_wound && !chest_pain))
            {priority = TWO;}
        else  
            {priority = ONE;}
    }
}

// Function: p1_first
// Input:Patient ,Patient 
// Returns: bool
// Does: return whether p1 >= p2 
bool Patient::p1_first(Patient p1,Patient p2) const
{
    if (!highest)
    {
        if (p1.get_priority() > p2.get_priority())
            return true;
        else if (p1.get_priority() < p2.get_priority())
            return false;
        else if (p1.get_time_in() >= p2.get_time_in())
            return true;
        else 
            return false;
    }
    else
    {
        if (p1.get_priority() > p2.get_priority())
            return true;
        else if (p1.get_priority() < p2.get_priority())
            return false;
        else if (p1.get_time_in() <= p2.get_time_in())
            return true;
        else 
            return false;
    }

}

// Function: get_priority
// Input: None
// Returns: int
// Does: return priority
int Patient::get_priority() const
{
    return priority;
}

// Function: get_time_in
// Input: None
// Returns: unsigned
// Does: return time_in
unsigned Patient::get_time_in() const
{
    return time_in;
}

