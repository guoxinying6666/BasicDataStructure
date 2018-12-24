#include "MinHeap.h"

template <class E> 
MinHeap<E>::MinHeap()
 {
 	this->length = 0;
 }

 template <class E> 
MinHeap<E>::~MinHeap()
 {

 }
    
// Overriding purely virtual functions
// Overriding purely virtual functions
// Function: heapify_up
// Input:int
// Returns: void 
// Does: heapify from bottom to top
template <class E>    
void MinHeap<E>::heapify_up(int index) 
{
	if (index == 0)
	{
		return;
	}
	if (this->heap[this->get_parent_index(index)] 
		> this->heap[index])
	{
		E temp = this->heap[index];
		this->heap[index] = this->heap[this->get_parent_index(index)];
		this->heap[this->get_parent_index(index)] = temp;
		heapify_up(this->get_parent_index(index));
	}

}

// Overriding purely virtual functions
// Function: heapify_down
// Input:int
// Returns: void 
// Does: heapify from top to bottom
template <class E>
void MinHeap<E>::heapify_down(int index)
{
	int left_child, right_child;
	Heap<E>::get_children_indices(index, left_child, right_child);
	if (left_child > this->length)
	{
		return;
	} 
	else if ((left_child < this->length) && 
		(right_child <= this->length))
	{
		
		if ((this->heap[left_child] < this->heap[index]) || 
			(this->heap[right_child] < this->heap[index]))
		{
			if (this->heap[right_child] < 
				this->heap[left_child])
			{
				E temp = this->heap[index];
				this->heap[index] = 
				this->heap[right_child];
				this->heap[right_child] = temp;
				heapify_down(right_child);

			}
			else 
			{				
				E temp = this->heap[index];
				this->heap[index] = 
				this->heap[left_child];
				this->heap[left_child] = temp;
				heapify_down(left_child);
			}
		}
	}
	else if (left_child == this->length)
	{
		if ((this->heap[left_child] < 
			this->heap[index]))
		{
			E temp = this->heap[index];
			this->heap[index] = 
			this->heap[left_child];
			this->heap[left_child] = temp;
			heapify_down(left_child);
		}
	}

}

template class MinHeap<int>;
template class MinHeap<Patient>;