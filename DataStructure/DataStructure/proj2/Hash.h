/*
 * Hash.h
 *
 * Implementation of hash table.
 * The has table is used for storing
 * Word data.
 *
 * COMP15
 * Spring 2018
 *
 */
#include <string>
#include <list>
#include <iostream>
#include "Word.h"
using namespace std;

#ifndef HASH_H_
#define HASH_H_

const int MAX_TABLE_SIZE = 500000;

class Hash
{
public:
    //Constructor
    Hash();
    //Destructor
    ~Hash();     
    // inserts a key into hash table
    void insert_item(string, string);
    // find item form hash table
    void find_item(string);
    // find the lower case version of word
    void find_lowcase_item(string);
    // find hashing value
    int hash_value(string);
    // switch string to lower case
    string switch_lowcase(string);
    // Display all the hash function
    // Only used for testing
    void display_hash();


private:
    //Pointer to an array containing buckets
    list<Word> *table;
};

#endif