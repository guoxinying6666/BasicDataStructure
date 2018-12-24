/*
 * HashTable.cpp
 * 
 * Implementation for Hash Table class
 *
 * COMP15
 * Spring 2018
 *
 * What hash you done??
 *
 */

#include <string>
#include "HashTable.h"
#include "HashString.h"
using namespace std;

// Default constructor
template<class E>
Hash<E>::Hash()
{
    length = 0;
}

// Function is_full(), const
// Parameters: none
// Returns: bool
// Does: Checks if array (static) is full
template<class E>
bool Hash<E>::is_full() const
{
    return (length == MAX_ITEMS);
}

// Function is_empty(), const
// Parameters: none
// Returns: bool
// Does: Checks if array is emtpy
template<class E>
bool Hash<E>::is_empty() const 
{
    return (length == 0);
}

// Function: retrieve
// Parameters: Item (E) &, bool &
// Returns: int, the number of collisions
// Does: Gets the hash value of the given item.
//       If the item is found at that position, return it.
//       If not, look for it in other positions in the array.
//       Hash table resolves collisions with linear probing.
template<class E>
int Hash<E>::retrieve(E &item, bool &found) const
{
    found = false;    
    int num_cols = 0;

    if (is_empty())
        return num_cols;

   
    size_t location = item.hash_value() % MAX_ITEMS;

    size_t start_loc = location;
    bool more_to_search = true;
    do 
    {
        if (info[location] == item || 
            info[location].is_empty())
            more_to_search = false;
        else{
            num_cols++;
            location = (location + 1) % MAX_ITEMS;
        }
    } while (location != start_loc && more_to_search);

    found = (info[location] == item);
    if (found)
        item = info[location];

    return num_cols;
}

// Function: insert
// Parameters: Item (E)
// Returns: int, the number of collisions
// Does: Gets the hash value of the given item.
//       If that position is available, insert the item.
//       If not, insert the item at the next open slot,
//       using linear probing. Counts and returns the number
//       of spaces we check before we can insert.
template<class E>
int Hash<E>::insert(E item)
{
    int collision_count = 0;
    if (is_full())
        return 0;

    size_t location = item.hash_value() % MAX_ITEMS;
    
    while (!info[location].is_empty())
    {
        collision_count++;
        location = (location + 1) % MAX_ITEMS;
    }

    info[location] = item;
    length++;

    return collision_count;
}

// Function: open_slots
// Parameters: None, const
// Returns: int, the number of empty slots in the array
// Does: Determines how 'full' our hash table is.
//       Iterates through each space and counts the number
//       that are empty. Ideal hash table is full!
template<class E>
int Hash<E>::open_slots() const
{
    int open = 0;
    for (size_t i = 0; i < MAX_ITEMS; i++)
    {
        if (info[i].is_empty())
            open++;
    }
    return open;
}


template class Hash<HashString>;
