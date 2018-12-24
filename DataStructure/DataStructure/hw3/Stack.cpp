/*
 * Stack.cpp
 * COMP15
 * Spring 2018
 *
 * Author: Xinying Guo 
 *
 * Implement a Stack of RPNCalc
 */


#include "Stack.h"
using namespace std;

// Constructor
Stack::Stack()
{
    length = 0;
    head = NULL;
    curr_pos = NULL;
}

// Destructor
Stack::~Stack()
{
    NodeType *current = head;

    while (current != NULL)
    {
        NodeType *next = current -> next;
        delete current; 
        current = next;
    }
    head = NULL;
}

// Copy constructor
Stack::Stack(const Stack & l)
{

    curr_pos = NULL;
    length = l.length;

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
}

// Assignment Operator
Stack & Stack::operator = (const Stack & l)
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

// Function is_full
// Input: None
// Returns: bool
// Does: Check whether the function is full
bool Stack::is_full() const
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

// Function is_empty
// Input: None
// Returns: bool
// Does: Check if there are no element on the stack
bool Stack::is_empty() const
{ 
  if (length == 0)
    return true;
  else 
    return false;
}

// Function make_empty
// Input: None
// Returns: None
// Does: Empties the stack
void Stack::make_empty()
{
  NodeType *current = head;

  while (current != 0)
    {
        NodeType *next = current -> next;
        delete current; 
        current = next;
        length--;
    }

    head = NULL;
  //head = NULL;
}

// Function get_size
// Input: None
// Returns: int
// Does:Return the number of elements currently on the stack
int Stack::get_size() const
{
  return length;
}

// Function: top
// Input: None
// Returns: double
// Does: Return the value of the element in the top of the stack
double Stack::top() const
{
  if (is_empty())
    {
        throw EmptyStack();
    }
        else
    { 
        return head->info; 
    }
}

// Function push
// Input: double
// Returns: None
// Does: Push the given parameter on the top of the stack
void Stack::push(double p)
{
    if (is_full())
    {
      throw FullStack();
    }
    else
    {
        NodeType *location = new NodeType;
        location->info = p;
        location->next = head;
        head = location;
        length++;
    }
}

// Function pop
// Input: None
// Returns: None
// Does: Remove the element on the top of the stack
void Stack::pop()
{
    if (is_empty())
    {
      throw EmptyStack();
    }
    else  
    {
        NodeType *curr = head->next;
        delete head;
        head = curr;
        length--;
    }
}

// Function get_gead, const
// Inputs: none
// Returns: *head, pointer
NodeType Stack::get_head() const
{
  return *head;
}

// Function get_curr_pos, const
// Inputs: none
// Returns: *curr_pos, pointer
NodeType Stack::get_curr_pos() const
{
    return *curr_pos;
}
