/*
 * ArrayList.h
 * COMP15
 * Spring 2018 
 *
 * Interface for Array of Pirates, matey
 */

#include <iostream>
#include "Pirate.h"

#ifndef ARRAY_H_
#define ARRAY_H_

const int MAX_PIRATES = 100;

class ArrayList
{
public:
    // Default constructor
    ArrayList();
    ~ArrayList();
    // The basic operations:
    // Insert, Delete, and Find
    Pirate find_pirate(Pirate, bool &) const;
    void insert_pirate(Pirate);
    void delete_pirate(Pirate);
    Pirate get_next_pirate();

    // Start over at the beginning of the list
    void make_empty();
    void reset_array();

    // Return some basic info
    int get_length() const;
    void set_length(int a);
    int get_maxlength() const;
    void set_maxlength(int a);
    int get_curr_pos() const;
    void set_curr_pos(int a);

    // Print the array
    void print(ostream &outfile) const;
    void expand_array();
    void shrink_array();




private:
    int length;
    //Dynamic array
    Pirate *pirates;
    int curr_pos;
    int max_length;
};

#endif
