/*
 * PRNCalc.cpp
 * COMP15
 * Spring 2018
 *
 * Author: Xinying Guo 
 *
 * Doing PRC Calculate
 */


#include "Stack.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#ifndef RPNCALC_H_
#define RPNCALC_H_

class RPNCalc
{
 public:
  	// Default constructor
  	RPNCalc();

  	// Push number to stack
  	void push_num();

  	// Do operation
  	void operate();

  	// Print top number of the stack
  	void print();

  	// Make stack empty
  	void clear();

  	// Read and open file
  	void read_file();

  	// Print out no command implemented
  	void report_comd();

  	// Check if input string is double
  	bool if_double();

  	// Excute program
  	void run();

  	// Excute all the function
  	void excute();

  	// Quit program
  	void quit();

  	// Read file recursively
    void read_file_from_file(ifstream &);

  	// Get some basic info 
  	Stack get_stack() const;

  	string get_data() const;


private:
	Stack s;
	string data;
};

#endif
