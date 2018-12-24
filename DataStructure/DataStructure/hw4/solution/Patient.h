/*
 * Patient.h
 *
 * COMP15
 * Spring 2018
 *
 * Interface for a Patient
 * 
 */

#include <string>
using namespace std;

#ifndef PATIENT_H_
#define PATIENT_H_

class Patient
{
public:
    Patient();
    Patient(string, string);

    friend bool operator < (const Patient &, const Patient &);
    friend bool operator > (const Patient &, const Patient &);
    friend ostream & operator << (ostream &, const Patient &);

private:
    string fname, lname;
    bool head_wound;
    bool chest_pain;
    double temp;
    unsigned pulse;

    Priority priority;
};

#endif
