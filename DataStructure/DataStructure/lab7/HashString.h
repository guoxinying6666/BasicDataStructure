/*
 * HashString.h
 *
 * Interface for a HashString class.
 * We're making a Hash Table of HashString objects.
 *
 * COMP15
 * Spring 2018
 *
 */

#include <string>
using namespace std;

#ifndef HASH_STRING_H_
#define HASH_STRING_H_

class HashString
{
private:
    string word;

public:
    HashString();
    HashString(string);

    string get_word() const;
    void set_word(string);    

    size_t hash_value() const;
    bool is_empty() const;

    friend bool operator == (const HashString &, const HashString &);
    friend bool operator != (const HashString &, const HashString &);
};

#endif

