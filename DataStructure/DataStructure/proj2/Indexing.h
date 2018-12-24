/*
 * Indexing.h
 *
 * Interface for Indexing words.
 *
 * COMP15 
 * Spring 2018
 *
 * Read file and index words to hash table. 
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

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Hash.h"
#include "FSTree.h"
using namespace std;

#ifndef INDEXING_H_
#define INDEXING_H_

class Indexing
{
public:
    //Constructor
    Indexing();
    //Biuld tree for directory
    void biuld_tree(string,Hash &);
    //Traverse documents and store them in hash
    //table
    void traverse_tree(DirNode *,string, Hash &);
    //Read word from file and put it in hash table
    void read_in_word(string,Hash &);
    //Put the word to hashing
    void put_to_hashing(Hash &, string, string);
    //Switch word to lower case word
    string switch_to_lowcase(string);
    //Hash function to find bucket number
    size_t find_bucket_value(string);
    // process string to remove symbols before 
    // or after characters
    string process_string(string);

private:

};

#endif
