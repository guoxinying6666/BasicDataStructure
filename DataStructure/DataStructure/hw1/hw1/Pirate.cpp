/*
 * Pirate.cpp
 * COMP15
 * Spring 2018
 *
 * Implarrrrrrmentation of a Pirate
 */

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Pirate.h"
using namespace std;

int Pirate::pirate_count = 0;

//Constructor
Pirate::Pirate()
{
    pirate_id = -1;
    name = "Cap'n Hook";
}
//COnstructor
Pirate::Pirate(string n)
{
    assign_pirate_id();
    name = n;
}
// Function print
// Input: ofstream, oncst
// Returns: none
// Does: Print id and name of pirate to file
void Pirate::print(ostream &outfile) const
{
   outfile << pirate_id << " "<< name;
}
// Function generate_pirate_name
// Input: ifstream , int
// Returns: none
// Does: Generate random name for pirate 
void Pirate::generate_pirate_name(ifstream &infile, int range)
{
    string pname;
    int rando = rand() % range;
    int count = 0;

    infile.clear();
    infile.seekg(0, ios::beg);
    while (getline(infile, pname))
    {
        if (count == rando)
        {
            name = pname;
            break;
        }
        count++;
    }
}
// Function generate_next_pirate
// Input: ifstream
// Returns: none
// Does: Generate name for pirate in sequence
void Pirate::generate_next_pirate(ifstream &infile)
{
    infile.clear();
    string pname;
    int count = 0; 
    static int pirate_count = 0;

    infile.seekg(0, ios::beg);
    while (getline(infile, pname))
    {
        if (count == pirate_count)
        {
            name = pname;
            break;
        }
        count++;
    }
    pirate_count ++;


}

// Function: assign_pirate_id
// Input: none
// Returns: none
// Does: Assign pirate id to pirate
void Pirate::assign_pirate_id()
{
    pirate_id = pirate_count++;
}

bool operator == (const Pirate &p1, const Pirate &p2)
{
    return (p1.pirate_id == p2.pirate_id);
}
// Function get_name
// Input: none, oncst
// Returns: string
// Does: Returns the value of pirate name
string Pirate::get_name() const 
{
    return name;
}
// Function set_name
// Input: string
// Returns: none
// Does: Set name for pirate
void Pirate::set_name(string a)
{
    name = a;
}
// Function get_pirate_id
// Input: none, oncst
// Returns: int
// Does: Returns the value of pirate id 
int Pirate::get_pirate_id() const
{
    return pirate_id;
}
// Function set_pirate_id
// Input: string
// Returns: none
// Does: Set pirate id
void Pirate::set_pirate_id(string a)
{
    a = pirate_id;
}


