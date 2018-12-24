/*
 * HashString.cpp
 *
 * Implementation for s string that's stored
 * in a hash table.
 *
 * COMP15
 * Spring 2018
 * Lab 7
 *
 */

#include <unordered_set>
#include "HashString.h"

// Default constructor
HashString::HashString()
{
    word = "";
}

// Parameterized constructor: the string itself
HashString::HashString(string s)
{
    word = s;
}

// Return the word
string HashString::get_word() const
{
    return word;
}

// Set the word to the given value
void HashString::set_word(string s)
{
    word = s;
}

// is_empty, used to determine an unset value
// in the hash table
bool HashString::is_empty() const
{
    return (word == "");
}


// Overloaded operators
bool operator == (const HashString &h1, const HashString &h2)
{
    return (h1.word == h2.word);
}

bool operator !=  (const HashString &h1, const HashString &h2)
{
    return (h1.word != h2.word);
}

/*
size_t HashString::hash_value() const
{
	hash<string> h;
	size_t n = h(word);
	return n;
}
*/


/*
size_t HashString::hash_value() const
{

	size_t n = word.length()/10;
	return n;
}
*/


size_t HashString::hash_value() const
{

	size_t n = word.length() * 2000 % 137;
	return n;
}



