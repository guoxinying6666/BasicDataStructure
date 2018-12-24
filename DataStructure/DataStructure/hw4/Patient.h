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

// enum priority of patients
enum Priority
{
    ONE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5
};

class Patient
{
public:
    // Default constructor
    Patient();
    // Constructor
    Patient(string, string);
    // Calculate priority of patients
    void calculate_priority(bool, bool, double, 
        unsigned, unsigned, bool);
    // find whether p1 > p2
    bool p1_first(Patient,Patient) const;
    // getters
    int get_priority() const;
    unsigned get_time_in() const;

    // Operator overload
    friend bool operator < (const Patient &, const Patient &);
    friend bool operator > (const Patient &, const Patient &);
    friend bool operator <= (const Patient &, const Patient &);
    friend bool operator >= (const Patient &, const Patient &);
    friend ostream & operator << (ostream &, const Patient &);
    friend bool operator == (const Patient &, const Patient &);

private:
    string fname, lname;
    bool head_wound;
    bool chest_pain;
    double temp;
    unsigned pulse;
    // time get in 
    unsigned time_in;
    // whether urgernt patient have high priority
    bool highest;
    Priority priority;
};



#endif
