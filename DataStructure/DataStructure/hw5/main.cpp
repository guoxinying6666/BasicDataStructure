/*
 * main.cpp
 *
 * Driver for Six Degrees of Kevin Bacon
 *
 * COMP15
 * Spring 2018
 * Author: Xinying Guo
 * date: Monday,April 2
 * 
 * Fun fact: Kevin Bacon's dad is locally famous,
 * but not for acting. He's a city planner for 
 * Philadelphia, and was on the cover of TIME
 * in 1964.
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "SixDegrees.h"

using namespace std;

// Inputing the name of 2 actors, the program can generate 
// the graph and find the common movie the actors plaied
// and find the path through those movies between the 2 actors.
int main(int argc, char *argv[]) 
{
    SixDegrees *sd = new SixDegrees;

    cout << "Enter two actor names separated by a new line.\n"
    	 << "Press ctrl-D to quit\n";
  	// If no file name was input in the command line
    // read command through cin
    if (argc == 1)
    {
    	sd->run(cin, cout); 
    }

    // If file name was been input in the command line
    // read command through file
    if (argc == 2)
    {
		ifstream infile;
    	infile.open(argv[1]);
    	sd->run(infile,cout);
    	infile.close();
    }  

    delete sd;

    return 0;
}
