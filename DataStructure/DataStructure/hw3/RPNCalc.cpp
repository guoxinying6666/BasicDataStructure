/*
 * PRNCalc.cpp
 * COMP15
 * Spring 2018
 *
 * Author: Xinying Guo
 *
 * Doing PRC Calculatation
 */

#include "RPNCalc.h"

// Default constructor
RPNCalc::RPNCalc()
{
	data = "None";
}

// Function: run
// Input: None
// Returns: None
// Does: Excute program
void RPNCalc::run()
{
    while (!cin.eof()){
    	cin >> data;
    	excute();
    }	
}

// Function: push_num
// Input: None
// Returns: None
// Does: Push number to stack
void RPNCalc::push_num()
{
   	if (if_double() == true)
  	{
  		try
  		{
  			double op = stod(data);
  			s.push(op);
  		}
  		catch (FullStack ese)
  		{
  			cerr << ese.what();
  		}
   	}
}

// Function: excute
// Input: None
// Returns: None
// Does: Do excution for loop
void RPNCalc::excute()
{
	push_num();
    operate();
    print();
  	clear();
  	read_file();
  	report_comd();
  	quit();
}

// Function: quit
// Input: None
// Returns: None
// Does: Quit the program
void RPNCalc::quit()
{
	if (data == "Q" || data == "q")
	{
		s.make_empty();
		exit(0);
	}
}

// Function: operate
// Input: None
// Returns: None
// Does: Do operation
void RPNCalc::operate()
{
	if (data == "+" || data == "-" || 
		data == "*" || data == "/")
	{
	    try
	    {
			double val1 = s.top();
			s.pop();
			double val2 = s.top();
			s.pop();
			if      (data == "+") s.push((val2 + val1));
		  	else if (data == "-") s.push((val2 - val1));
		  	else if (data == "*") s.push((val2 * val1));
		  	else if (data == "/") s.push((val2 / val1));
	   	}
	    catch (EmptyStack ese)
	    {
			cerr << ese.what();
		}
	}
}

// Function: print
// Input: None
// Returns: None
// Does: Print number of top of the stack
void RPNCalc::print()
{
	if (data == "p" || data == "P")
	{
		try
		{
			cout << s.top() << endl;
		}
		catch (EmptyStack ese)
		{
			cerr << ese.what();
		}
	}

}

// Function: clear
// Input: None
// Returns: None
// Does: Make stack empty
void RPNCalc::clear()
{
	if (data == "c" || data =="C")
	{
		s.make_empty();
	}

}

// Function: read_file
// Input: None
// Returns: None
// Does: Read file from input
void RPNCalc::read_file()
{
	if (data == "F" || data == "f")
	{
		ifstream infile;
		string file_name;

		cin >> file_name;
		infile.open(file_name);
		
		if (!infile.is_open()) 
		{
			cerr << "Could not open file for reading" << endl;
			s.make_empty();
			exit(0);
		}
		else
		{
			read_file_from_file(infile);	
		} 

		infile.close();
	}
}


// Function: read_file_from_file
// Input: ifstream &
// Returns : None
// Does: Recursive read file from file
void RPNCalc::read_file_from_file(ifstream  &in)
{
	while (in >> data)
	{
		push_num();
    	operate();
    	print();
  		clear();
  		report_comd();

		if (data == "f" || data == "F")
		{
			ifstream infile;
			string file_name;

			in >> file_name;
			infile.open(file_name); 
		
			if (!infile.is_open()) 
			{
				cerr << "Could not open file for reading" 
					 << endl;
				s.make_empty();
				exit(0);
			}

			while (infile >> data)
			{
				read_file_from_file(infile);
			}

			infile.close();
		}

		if (data == "Q" || data == "q")
		{
			in.close();
			s.make_empty();
			break;
			exit(0);
		}
	}		
}

// Function: if_double
// Input: None
// Returns: bool
// Does: Check if the string can transfer to double
bool RPNCalc::if_double()
{
	bool is_double = true;	

    try
    {
   		stod(data);
    }
    catch (invalid_argument exception)
    {
    	is_double = false;
    }
    return is_double;
}

// Function: report_comd
// Input: None
// Returns: None
// Does: Report wrong command
void RPNCalc::report_comd()
{
	if (if_double() != true && 
		data != "+" && data != "-" && 
		data != "*" && data != "/" &&
		data != "p" && data != "P"&&
		data != "c" && data != "C"&&
		data != "F" && data != "f"&&
		data != "Q" && data != "q")
	{
		cout << "command " << data 
			 << " not implemented" << endl;
	}
}

// Function get_stack, const
// Inputs: none
// Returns: Stack, length of list
Stack RPNCalc::get_stack() const
{
	return s;
}

// Function get_data, const
// Inputs: none
// Returns: string, data get in
string RPNCalc::get_data() const
{
	return data;
}


