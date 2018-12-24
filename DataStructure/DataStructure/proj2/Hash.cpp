/*
 * Hash.cpp
 *
 * Implementation of hash table.
 * The has table is used for storing
 * Word data.
 *
 * COMP15
 * Spring 2018
 * Project2
 *
 */
#include <Hash.h>
#include <Word.h>
#include <iostream>
#include <list>
using namespace std;

// Constructor
Hash::Hash()
{
    // allocate double linked list
    // for the hash table. each list is a chain
    // and there are totally MAX_TABLE_SIZe
    // buckets
    table = new list<Word>[MAX_TABLE_SIZE];
}

// Destructor
Hash::~Hash()
{
    //delete hash table
    delete[] table;
}

// Function: insert_item
// Parameters: string key, string need to be stored, 
// int bucket, the slot number to be insert in, 
// string location, the word's location
// Returns: void
// Does: insert item to hash table
void Hash::insert_item(string key, string location)
{
    int bucket = hash_value(key); 
    list <Word> :: iterator i;

    for (i = table[bucket].begin();
        i != table[bucket].end(); i++) 
    {
        // Check if the word was being stored 
        // if it was, then add the location 
        // to the existing word in hash table
        if (i->get_name() == key)
        {
            i->add_location(location);
            break;
        }
    }
    // If word can not be find in the existing 
    // hash table than create a new word and 
    // store it and all it's information to hash table. 
    if (i == table[bucket].end())
    {
        Word word(key);
        word.add_location(location);
        table[bucket].push_back(word); 
    }
}

// Function display_hash() 
// Input: 
// Returns: void
// Does:  Display all the element in 
// Hash table. Only used for testing
void Hash::display_hash() 
{
    for (int i = 0; i < MAX_TABLE_SIZE; i++) 
    {
        for (auto x : table[i])
        {
            x.display_word();
        }

    }
}

// Function find_item()
// Input: string
// Returns: void
// Does:  find the item in the hash table and 
// display the item
void Hash::find_item(string word)
{
    int bucket = hash_value(word);
    bool found = false;

    list <Word> :: iterator i;

    for (i = table[bucket].begin();
        i != table[bucket].end(); i++) 
    {
        // if found, display the word
        if (i->get_name() == word)
        {
            i->display_word();
            found = true;
        }
    }

    // Counld not found
    if (!found)
        cout << word 
        << " Not Found. Try with @insensitive or @i.\n";
}


// Function find_lowcase_item
// Input: string
// Returns: void
// Does:  find the string's lower case version 
// in the hash table and 
// display the item
void Hash::find_lowcase_item(string word)
{
    word = switch_lowcase(word);
    bool found = false;
    int bucket = hash_value(word);

    list <Word> :: iterator i;

    for (i = table[bucket].begin();
        i != table[bucket].end(); i++) 
    {
        // If found, display the location
        if (i->get_lowcase_name() == word)
        {
            i->display_word();
            found = true;
        }
    }

    // Could not found
    if (!found)
        cout << word << " Not Found.\n";
}

// Function hash_value
// Input: string
// Returns: int
// Does:  find the index of hash
// table where the value was being
// stored
int Hash::hash_value(string word)
{
    string lowcase = switch_lowcase(word);
    hash<string> h;
    size_t n = h(lowcase);

    return (n % MAX_TABLE_SIZE);
}

// Function switch_lowcase
// Input: string
// Returns: string
// Does:  switch all the the upper case character 
// to lower case in a string
string Hash::switch_lowcase(string word)
{
    string lowcase = word;

    for( char& c : lowcase) 
        c = tolower(c);
    
    return lowcase;
}



