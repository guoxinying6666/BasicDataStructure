/*
 * Stack.h
 * COMP15
 * Spring 2018
 *
 * Author: Xinying Guo 
 *
 * Interface for Stacks of PRNCalcs
 */

#include <string>
#include <iostream>
#include <string>
using namespace std;

#ifndef STACK_H_
#define STACK_H_

//LinkedList Node 
struct NodeType
{
  double info;
  NodeType *next;
};

class Stack
{
 public:
  // Default constructor
  Stack();
  // Destructor
  ~Stack();

  // Copy constructor
  Stack(const Stack &);

  // Assignment Operator
  Stack & operator = (const Stack &);

  // Check whether the function is full
  bool is_full() const;

  // Check if there are no element on the stack
  bool is_empty() const;

  // Empties the stack
  void make_empty();

  // Return the number of elements currently on the stack
  int get_size() const;

  // Return the value of the element in the top of the stack
  double top() const;

  // Push the given parameter on the top of the stack
  void push(double);

  // Remove the element on the top of the stack
  void pop();

  NodeType get_head() const;

  NodeType get_curr_pos() const;

 private:
    int length;
    NodeType *head;
    NodeType *curr_pos;
};

// Exception FullStack Definition
class FullStack : public exception
{
public:
    const char* what() const throw() 
    {
      return "Oh no, the stack is full!\n";
    }
};

// Exception EmptyStack Definition
class EmptyStack : public exception
{
public:
    const char* what() const throw() 
    {
      return "Oh no, the stack is empty!\n";
    }
};




#endif
