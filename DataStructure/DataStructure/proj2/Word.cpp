/*
 * Word.h
 *
 * Interface for a Word class.
 *
 * COMP15 
 * Spring 2018
 *
 * This class store a word and all the 
 * location it showed in the documents.
 * This class also stored the lower-case
 * version of string to help insensitive search
 * This class used a stack to store its location.
 *
 */

#include "Word.h"

// Initialized constructor
Word::Word()
{
	word = "Null";
	lowcase = "null";
}

// Constructor with parameter 
// Input: name
Word::Word(string name)
{
	word = name;
	switch_lowcase();
}

// Function set_name()
// Input: string
// Returns: void
// Does:  set the name of the word
void Word::set_name(string Name)
{
	word = Name;
	switch_lowcase();
}

// Function get_name()
// Input: 
// Returns: string
// Does:  return the name of the word
string Word::get_name()
{
	return word;
}

// Function get_lowcase_name
// Input: 
// Returns: string
// Does:  return the transfered lower case 
// of the word
string Word::get_lowcase_name()
{
	return lowcase;
}

// Function add_location
// Input: string
// Returns: void
// Does:  add the location of the word to list
// The location contain directory, which line 
// the word in the file, the line containing the 
// word
void Word::add_location(string position)
{
		if (!location.empty() && 
			location.back() == position)
			return;
		else
		location.push_back(position);
}

// Function display_word()
// Input: 
// Returns: void
// Does:  display all the location
// and information of the word 
void Word::display_word()
{
	list <string> :: iterator i;

    for (i = location.begin();
        i != location.end(); i++) 
    {
        cout << *i << endl;
    }

}

// Function switch_lowcase
// Input: 
// Returns: void
// Does:  switch every character of 
// name to lower case and store it to 
// stringlowcase
void Word::switch_lowcase()
{
	lowcase = word;
	for( char& c : lowcase) 
		c = tolower(c) ;
}





