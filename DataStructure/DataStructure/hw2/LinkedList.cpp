/*
 * LinkedList.cpp
 * COMP15
 * Spring 2018
 * 
 * Implementation for Linked List of Planets
 *
 * What is an astronaut's favorite candy bar?
 *
 * A mars bar!
 */

#include "LinkedList.h"
#include <iostream>
using namespace std;

// Default constructor
LinkedList::LinkedList()
{
    length = 0;
    head = NULL;
    curr_pos = NULL;
}

//Destructor
LinkedList::~LinkedList()
{
    while(head != 0)
    {
        NodeType *next = head->next;
        delete head; 
        head = next;
    }
}

//Copy constructor
LinkedList::LinkedList(const LinkedList & l)
{
    curr_pos = l.curr_pos;
    length = l.length;
    if(l.head == NULL)
        head = NULL;
    else
    {
        head = new NodeType;
        head->info = l.head->info;
        head->next = NULL;
        NodeType *curr = head;
        NodeType *orig = l.head;
        while (orig->next != NULL)
        {
            curr->next = new NodeType;
            curr->next->info = orig->next->info;
            curr->next->next = NULL;
            orig = orig->next;
            curr = curr->next;
        }
    }
}

// Assignment operator
LinkedList & LinkedList::operator = (const LinkedList &l)
{
    length = l.length;
    curr_pos = NULL;
    if (l.head == NULL)
        head = NULL;
    else
    {
        head = new NodeType;
        head->info = l.head->info;
        head->next = NULL;
        NodeType *curr = head;
        NodeType *orig = l.head;
        while (orig->next != NULL)
        {
            curr->next = new NodeType;
            curr->next->info = orig->next->info;
            curr->next->next = NULL;
            orig = orig->next;
            curr = curr->next;
        }
    }
    return *this;
}

// Function insert_planet
// Input: Planet object
// Returns: None
// Does: Adds PLanet to beginning of array, increases length
void LinkedList::insert_planet(Planet p)
{
    NodeType *location = new NodeType;
    location->info = p;
    location->next = head;

    head = location;
    length++;
}

// Function get_next_planet
// Inputs: none
// Returns: none
// Does: Returns the Planet object at the current pos
//       Wraps around to beginning if we're at the end
//       Returns a default planet if empty
Planet LinkedList::get_next_planet()
{
    if (length == 0)
    {
        Planet p;
        return p;
    }
    if (curr_pos == NULL)
        curr_pos = head;
    else
        curr_pos = curr_pos->next;
    return curr_pos->info;
}

// Function get_length, const
// Inputs: none
// Returns: int, length of list
int LinkedList::get_length() const
{
    return length;
}

// Function get_curr_pos, const
// Inputs: none
// Returns: int, value of curr_pos
NodeType LinkedList::get_curr_pos() const
{
    return *curr_pos;
}

// Function print, const
// Inputs: ostream object
// Returns: none
// Does: prints every element in the list
void LinkedList::print(ostream &out) const
{
    NodeType *location = head;
    while (location != NULL)
    {
        (location->info).print(out);
        out << endl;
        location = location->next;
    }
}

//Function find_planet, const
//Input: planet object, bool found 
//Return: none
//Doest: find whether list have planet 
Planet LinkedList::find_planet(Planet planet, bool &found) const
{
    NodeType *curr = head;
    while(curr != 0)
    {
        if(curr->info == planet)
        {
            found = true;
            return curr->info;
        }
        curr = curr->next;
    }
    return planet;
}

//Function delete_planet
//Input: planet object
//Return: none
//Doest: delete the planet
void LinkedList::delete_planet(Planet p)
{
    bool found = false;
    
    Planet p2 = find_planet(p, found);
    if(!found)
    {
        //cout << "The planet can not be found" << endl;
        return;
    }

    NodeType *curr = head;
    NodeType *previous = 0;
    
    if(head->info == p)
    {
        head = curr->next;
        delete curr;
        curr = 0;
        length--;
    }
    else
    {
        while(curr != 0)
        {
            previous = curr;
            curr = curr->next;
            if(curr->info == p)
            {
                previous->next = curr->next;
                delete curr;
                curr = 0;
                length--;
            }
        }
    }    
}

//Function make_empty
//Input: none 
//Return: none
//Doest: make the list empty 
void LinkedList::make_empty()
{
    while(head != 0)
    {
        NodeType *next = head -> next;
        delete head; 
        head = next;
        length--;
    }
    head = NULL;
}

//Function reset_list
//Input: none
//Return: none
//Doest: reset curr_pos
void LinkedList::reset_list()
{
    curr_pos = 0;
}

//Function is_full, const
//Input: none
//Return: bool
//Doest: find whether the list is full
bool LinkedList::is_full() const
{
    try
    {
        NodeType *node = new NodeType;
        delete node;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}




