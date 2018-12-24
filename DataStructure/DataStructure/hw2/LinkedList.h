/*
 * LinkedList.h
 * COMP15
 * Spring 2018
 *
 * Interface for Linked List of Planets
 *
 * What is an astronaut's favorite candy bar?
 *
 * A milky way!
 */

#include "Planet.h"
#include <fstream>

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

class LinkedList
{
public:
    // Default constructor
    LinkedList();
    ~LinkedList();

    // Copy constructor/Users/Xinying/Desktop/Linux/comp15-linux/hw2/LinkedList.h
    LinkedList(const LinkedList &);

    // Assignment Operator
    LinkedList & operator = (const LinkedList &);

    // The basic operations:
    // Insert, delete, and find
    void insert_planet(Planet);
    Planet get_next_planet();

    // Return some basic info
    int get_length() const;
    NodeType get_curr_pos() const;

    // Print the list
    void print(ostream &) const;

    // Find the first instance of the list
    Planet find_planet(Planet, bool &) const;

    // Delete first instance of the given planet
    void delete_planet(Planet);

    // Deallocating allocated memory
    void make_empty();

    // Reset curr_pos to initial state
    void reset_list();

    // Check whether the function is full
    bool is_full() const;


private:
    int length;
    NodeType *head;
    NodeType *curr_pos;
};

#endif
