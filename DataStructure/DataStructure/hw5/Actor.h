/*
 * Actor.h
 *
 * Interface for Actor class
 *
 * COMP15
 * Spring 2018
 * Homework 5
 * Author: Xinying Guo
 * date: Monday,April 2
 * 
 */
#ifndef ACTOR_H_
#define ACTOR_H_

#include <ostream>
#include <fstream>
#include <string>
#include "LinkedList.h"
using namespace std;

class Actor
{
 public:
    // Default Constructor
    Actor();

    // Set element to actors
    void add_name(string movie);
    void set_name(string);

    // Basic functions of actors
    bool if_in(string movie);
    string connect(Actor);

    // Get element of actor
    string get_name() const;

    // Operators override
    friend bool operator == (const Actor &, const Actor &);
    friend bool operator != (const Actor &, const Actor &);
    friend ostream & operator << (ostream &, const Actor &);

  private:
	string name;
	LinkedList<string> movies;
};

#endif