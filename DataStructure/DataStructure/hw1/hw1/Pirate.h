/*
 * Pirate.h
 * COMP15
 * Spring 2018
 *
 * Interface for a Pirate class
 * yo ho ho
 */

#include <fstream>
#include <string>
using namespace std;

#ifndef PIRATE_H_
#define PIRATE_H_


class Pirate
{
public:
    //Default constructor
    Pirate();
    Pirate(string);
    //Basic operations: print,generate pirate name,
    //assign pirate id, generate pirate name on sequence  
    void print(ostream &outfile) const;
    void generate_pirate_name(ifstream &, int);
    void assign_pirate_id();
    void generate_next_pirate(ifstream &infile);
    //return some basic info and mutator.
    string get_name() const;
    void set_name(string a);
    int get_pirate_id() const;
    void set_pirate_id(string a);

    friend bool operator == (const Pirate &, const Pirate &);
    
private:
    int pirate_id;
    string name;
    static int pirate_count;
};

#endif
