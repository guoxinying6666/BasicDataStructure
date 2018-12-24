/* 
 * Survivor.h
 *
 * Interface for derived class Survivor
 */
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>
using namespace std;

#ifndef SURVIVOR_H_
#define SURVIVOR_H_

class Survivor
{
public:
	// Constructors
	Survivor();
	Survivor(string fn, string ln, string city,string state, int age);
	// Override "==", "<", ">"
	friend bool  operator == (const Survivor &, const Survivor &);
	friend bool  operator < (const Survivor &, const Survivor &);
	friend bool  operator > (const Survivor &, const Survivor &);
	// Print The Tree
	void print(ostream &);
	// Generate Survitors for tree
	int generate_castaway(ifstream &, int);
	// Setters 
	void set_name(string, string);
	void set_age(double);
	
	// Mutators to get parameters
	int get_age() const;
	string get_first_name() const;
	string get_last_name() const;
	string get_city() const;
	string get_state() const;

private:
	string first_name;
	string last_name;
	string city;
	string state;
	int age;
};

#endif 
