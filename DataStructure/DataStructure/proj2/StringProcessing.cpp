/*
 * StringProcessing.cpp
 *
 * Strip all leading and trailing non-alphanum character
 * from the query and print it out
 *
 * COMP15
 * Spring 2018
 * Project 2 
 * Phase 1
 * Author: Xinying Guo
 * date: Monday,April 2
 * 
 * How to compile: 
 * clang++ -Wall -Wextra -std=c++11 StringProcessing.cpp 
 * 
 */
#include <istream>
#include <ostream>
#include <iostream>
#include <cctype>
using namespace std;

// Wrapped functions
// String Processing
void string_processing(string &);
string process_string(string query);

int main()
{
	string in;

	while (!cin.eof())
	{
		cin >> in;
		if (in == "q" || cin.eof())
			break;
		in = process_string(in);
		cout << in <<"\n\n";
	}
}

// Function string_processing
// Input: string &
// Returns: void
// Does:  Strip all leading and 
// 		  trailing non-alphanum character
//  	  from the query and print it out
void string_processing(string &in)
{
	size_t i = 0;
	size_t len = in.length();
	while(i <= len)
	{
    	if (isalnum(in[i]) )
    	{
        	if (i == 0)
        		break;
        	else
        	{
        		in.erase(0,i);
        		break;
        	}
    	}    	
    	else
        	i++;
	}

	len = in.length();
	while(len > 0)
    {
        if (!isalnum(in[len]))
        {
            in.erase(len,1);
            len--;
            if ((len == 0) && !isalnum(in[0]))
                in.erase(0,1);
        }       
        else
            break;
    }
}

string process_string(string query)
{
    int start = 0, end = query.length();

    for (start; start < end; start++) {
        if (isalnum(query[start])) {
            break;
        }
    }
    for (end; end > start; end--) {
        if (isalnum(query[end])) {
            break;
        }
    }

    return query.substr(start, end - start + 1);
}










