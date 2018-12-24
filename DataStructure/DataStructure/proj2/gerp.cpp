/*
 * gerp.cpp
 *
 * 
 * This is the driver of the program.
 * This calss is for recieving command from command line and 
 * searching the word from hash table. When the word was being
 * recieved, it can print out the directory, which line and the 
 * contex of the line.
 *
 * COMP15
 * Spring 2018
 * Project 2 
 * Phase 2
 * Author: Xinying Guo
 * date: Monday,April 2
 * 
 * How to compile: 
 * make gerp
 * 
 */
#include <istream>
#include <ostream>
#include <iostream>
#include <cctype>
#include <string>
#include "Indexing.h"
using namespace std;

// Wrapped functions
// String Processing
string process_string(string);


// Function: main
// Input: int argc, char *argv[]
// Returns: int
// Does:  Driver of the program
// Read word from command line and process 
// the file being read from command line
// Print out Query and input word to find the 
// item in hash table.
int main(int argc, char *argv[])
{

    (void) argc;    
    Indexing index;
    Hash h;
    index.biuld_tree(argv[1],h);
    // Repeatedly query word from cin until
    // end the program
	while (!cin.eof())
	{
		string in;
        cout << "Query? ";
        cin >> in;
        // exit by "q" and eof
		if (in == "q" || cin.eof())
        {
            cout << "\nGoodbye! Thank you and have a nice day.\n"; 
			break;
        }
        // insensitive search
        if ((in == "@i" || (in == "@insensitive")))
        {
            cin >> in;
            in = process_string(in);
            h.find_lowcase_item(in);
        }
        // non-insensitive search
        else 
        {
            in = process_string(in);
            h.find_item(in);
        }
	}
}

// Function string_processing
// Input: string &
// Returns: void
// Does:  Strip all leading and 
// 		  trailing non-alphanum character
//  	  from the query and print it out
string process_string(string query)
{
    int start = 0, end = query.length();

    for (; start < end; start++) 
    {
        if (isalnum(query[start])) {
            break;
        }
    }

    for (; end > start; end--) 
    {
        if (isalnum(query[end])) {
            break;
        }
    }

    return query.substr(start, end - start + 1);
}