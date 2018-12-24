/*
 * tufts-major.cpp
 *
 * COMP15
 * Spring 2018
 * Lab 5
 *
 * Print out all the ways you could complete
 * the comp sci major (core courses only)
 */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "LinkedList.h"
using namespace std;

const int NUM_CORE = 7;

void read_majors_from_file(char *, LinkedList<string>[]);
void second_read(char *, LinkedList<string>[]);

// Get arguments from the command line first!
// Expected usage: ./major tufts-major-core.txt all-possible-order.txt
int main(int argc, char *argv[])
{
    LinkedList<string> dependencies[NUM_CORE];


    //string s1,s2; 
    //cin >> s1;
    //cin >> s2;
    // Note that this function call passes argv[1]
    // that's second command-line argument, tufts-major-core.txt
    read_majors_from_file(argv[1], dependencies);
    second_read(argv[2],dependencies);
}

// Function read_majors_from_file
// Input: file name, array of Linked Lists
// Returns: void
// Does: opens input file by name, reads in adjancency list
//       of course dependencies.
void read_majors_from_file(char *fname, LinkedList<string> courses[])
{
    ifstream infile;
    infile.open(fname);
    if (!infile.is_open())
    {
        cerr << "Could not open input file for reading\n";
        exit(1);
    }
    int course_counter = 0;
    while (!infile.eof())
    {
        string line;
        getline(infile, line);

        if (line == "-1")
            break;
        else if (course_counter < NUM_CORE)
        {
            stringstream ss(line);
            while (!ss.eof())
            {
                string tmp;
                ss >> tmp;
                if (tmp == "-1")
                    break;
                courses[course_counter].insert(tmp);
            }
            course_counter++;
        }
    }
    infile.close();
}

void second_read(char *fname, LinkedList<string> courses[])
{
    ifstream infile;
    infile.open(fname);
    if (!infile.is_open())
    {
        cerr << "Could not open input file for reading\n";
        exit(1);
    }
    int course_counter = 0;

    while (!infile.eof())
    {
        string line;
        getline(infile,line);
        bool found;
        if (line == "-1")
            break;
        else if (course_counter < NUM_CORE)
        {
            stringstream ss(line);
            stringstream sss(line);
            cout << ss;
            while (!ss.eof())
            {
                string tmp;
                ss >> tmp;
                course_counter++;
                for (int i = 0; i < 7; i++)
                {
                    tmp = courses[i].find(tmp,found);
                    if (found)
                    {
                        while(!ss.eof())
                        {
                            bool success = false;
                            int count = 0;
                            string tmp2;
                            sss >> tmp2;
                            while (count < course_counter)
                            {
                                if (tmp == tmp2)
                                {
                                    break;
                                    success = true;
                                }
                            }
                            if (success)
                                break;
                        }
                    }
                }
            
            }
            if (found)
                cout << line << endl;

            
        }
    }
    infile.close();
}


