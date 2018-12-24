/*
 * Heap.cpp
 *
 * Implementation for Heap class
 * 
 * COMP15
 * Spring 2018
 *  4
 */

#include <iostream>
#include "Heap.h"
using namespace std;

//Constructor
template <class E>
Heap<E>::Heap()
{
	length = 0;
}

template <class E>
Heap<E>::~Heap()
{
	length = 0;
}

// Function is_full
// Input: None
// Returns: bool
// Does: Check whether the function is full
template <class E>
bool Heap<E>::is_full() const
{
	if (length == MAX_CAPACITY)
		return true;
	else 
		return false;
}

// Function is_empty
// Input: None
// Returns: bool
// Does: Check whether the function is empty
template <class E>
bool Heap<E>::is_empty() const
{
	if (length == 0)
		return true;
	else 
		return false;
}

// Function insert_item
// Input: E 
// Returns: void
// Does: Insert an item to heap
template <class E>
void Heap<E>::insert_item(E item)
{
	if (is_full())
		throw FullHeap();
	heap[length] = item;
	heapify_up(length);
	length++; 
}

// Function: extract
// Input: 
// Returns: E
// Does: extract item from the top and return 
//it and delete it
template <class E>
E Heap<E>::extract()
{
	if (is_empty())
		throw EmptyHeap();
	E temp = heap[0];
	heap[0] = heap[length-1];
	length--;
	heapify_down(0);
	return temp;
}

// Function: get_patrent_index
// Input: int
// Returns: int
// Does: find parent index
template <class E>
int Heap<E>::get_parent_index(int index) const
{
	if (index == 0)
		return 0;
	else if (index % 2 == 0)
		return (index -2 )/2;
	else 
		return (index - 1)/2;
}

// Function: get_children_indices
// Input: 
// Returns: int, int &, int &
// Does: get left and right child
template <class E>
void Heap<E>::get_children_indices(int index, int &left_child, int &right_child) const
{
	left_child = 2 * index + 1;
	right_child = 2 * index + 2;
}

// Function: get_value_at
// Input: int
// Returns: E
// Does: get value at a specific position
template <class E>
E Heap<E>::get_value_at(int index)
{
	if ((index < 0) || (index > MAX_CAPACITY))
		throw NoIndex();
	return heap[index];
}

template class Heap<int>;
template class Heap<Patient>;

