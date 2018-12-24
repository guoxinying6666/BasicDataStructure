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

#include <string>
#include <iostream>
#include <cctype>
#include <list>
using namespace std;

#ifndef WORD_H_
#define WORD_H_

class Word
{
public:
    //Default constructor
    Word();
    //Constructor with parameter
    Word(string);
    //Set name for the class
    void set_name(string);
    //Put location to stack
    void add_location(string);
    //Pop locations to cout
    void display_word();
    //Get word
    string get_name();
    //Get lower case word
    string get_lowcase_name();
    //Switch the word to lower case
    void switch_lowcase();
private:
    // The word being stored
    string word;
    // The purely lower case version 
    // of word
    string lowcase;
	//Linked list<string> to store 
    //location information of word
    list<string> location;
};

#endif
