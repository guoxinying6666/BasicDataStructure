/*
 * Array.cpp
 * COMP15
 * Spring 2018
 *
 * Implementation for Arrrrrrray of Pirates
 */

#include "ArrayList.h"

// Default constructor
// Length and current position default to 0
ArrayList::ArrayList()
{
    length = 0;
    curr_pos = 0;
    pirates = new Pirate[MAX_PIRATES];
    max_length = MAX_PIRATES;
}
ArrayList::~ArrayList()
{
    delete [] pirates;
}

// Function find_pirate
// Inputs: Pirate object, bool by reference
// Returns: Pirate object
// Does: Looks for pirate in the array, modifies bool if found
//       Returns the object from the list and not the passed one
//       (In case they're different.)
Pirate ArrayList::find_pirate(Pirate p, bool &found) const
{
    int location = 0;
    while ((location < length) && !found)
    {
        if (p == pirates[location])
        {
            found = true;
            p = pirates[location];
            break;
        }
        location++;
    }
    return p;
}

// Function insert_pirate
// Inputs: Pirate object
// Returns: Nothing
// Does: Adds Pirate to end of array, increases length
void ArrayList::insert_pirate(Pirate p)
{
    for(int i = 0; i < get_length(); i++)
    {
        if (pirates[i] == p)
        {
            cerr << "The pirate is duplicated added" << endl;
            return;
        }
    }
    pirates[length] = p;
    length++;

    expand_array();
}

// Function delete_pirate
// Inputs: Pirate object
// Returns: Nothing
// Does: Deletes pirate, shifts everything else over, and shrink array
void ArrayList::delete_pirate(Pirate p)
{
    for(int i = 0; i < get_length()+1; i++)
    {
        if (pirates[i] == p)
        {
            for (int j = i; j < get_length(); j++)
            {
                pirates[i] = pirates[i+1];     
            }
             --length;    
        }     
        else
        {
            //cerr << "The pirate does not exist" << endl;
        }   
    }
    shrink_array(); 
}

// Function get_next_pirate
// Input: None
// Returns: Pirate object
// Does: Returns pirate at curr_pos
//       Increments curr_pos, but wraps around
Pirate ArrayList::get_next_pirate()
{
    Pirate p = pirates[curr_pos];
    curr_pos = (curr_pos + 1) % length;
    return p;
}

// Function make_empty
// Input: none
// Returns: none
// Does: sets length to 0 (memory not modified)
void ArrayList::make_empty()
{
    length = 0;
}

// Function reset_array
// Input: none
// Returns: none
// Does: sets curr_pos to 0 
void ArrayList::reset_array()
{
    curr_pos = 0;
}

// Function print
// Input: none, const
// Returns: none
// Does: Prints array from 0 to length
void ArrayList::print(ostream &outfile) const 
{
    if(length == 1 || length == 0)
    {

            for (int i = 0; i < length; i++)
            {
                pirates[i].print(outfile); 
            }
    }
    else
    {
        for (int i = 0; i < length-1; i++)
            {
                pirates[i].print(outfile); 
                outfile << ", ";
            }
                pirates[length-1].print(outfile);
        //outfile << '\n';
    }

        
}


// Function get_length
// Input: none, oncst
// Returns: int
// Does: Returns the value in length attribute
int ArrayList::get_length() const
{
    return length;
}
// Function get_maxlength
// Input: none, oncst
// Returns: int
// Does: Returns the value in max length of array 
int ArrayList::get_maxlength() const
{
    return max_length;
}
// Function get_curr_pos
// Input: none, oncst
// Returns: int
// Does: Returns the value current position

int ArrayList::get_curr_pos() const
{
    return curr_pos;
}
// Function set_length
// Input: int
// Returns: none
// Does: set value to length 
void ArrayList::set_length(int a)
{
    length = a;
}
// Function set_maxlength
// Input: int
// Returns: none
// Does: Returns the value of capacity of array
void ArrayList::set_maxlength(int a)
{
    a = length;
}
// Function set_curr_pos
// Input: int
// Returns: none
// Does: set current position
void ArrayList::set_curr_pos(int a)
{
    a = curr_pos;
}
// Function expand capacity of array
// Input: none, oncst
// Returns: none
// Does: Expand capacity of array if the array is full 
void ArrayList::expand_array()
{
    if(get_length() == max_length)
    {
        max_length = 2 * max_length;
        Pirate *temp = new Pirate[max_length];
        for(int i = 0; i < get_length(); i++)
        {
            temp[i] = pirates[i];
        }
        delete [] pirates;
        pirates = temp;
        cout << "Expand to " << max_length << endl;
    }
}
// Function shrink_array
// Input: none
// Returns: none
// Does: SHrink capacity of array if the array length less 
//than half of capacity
void ArrayList::shrink_array()
{
    if(get_length() <= max_length/2)
    {
        max_length = max_length/2;
        Pirate *temp = new Pirate[max_length];
        for(int i = 0; i < length; i++)
        {
            temp[i] = pirates[i];
        }
        delete [] pirates;
        pirates = temp;
        cout << "Contract to" << " "<< max_length << endl;
    }
}







