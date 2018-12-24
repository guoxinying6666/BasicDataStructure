/*
 * Hash.h
 *
 * Interface for a Hash Table class.
 *
 * COMP15 
 * Spring 2018
 *
 * Table 5 asked for a side of hash browns.
 * But this is Hash.
 * I think.
 * I mean, it's Hash-like.
 *
 */

#include <iostream>

#ifndef HASH_H_
#define HASH_H_

const int MAX_ITEMS = 200000;

template <class E> class Hash
{
public:
    Hash();

    bool is_full() const;
    bool is_empty() const;

    int retrieve(E&, bool &) const;
    int insert(E);

    int open_slots() const;
    
private:
    int length;
    E info[MAX_ITEMS];
};

#endif
