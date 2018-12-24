/*
 * MaxHeap.h
 *
 * COMP15
 * Spring 2018
 *
 * Derived class for MinHeap type
 * Inherits from abstract Heap class
 *
 * The memory heap is neither a Heap nor
 * in memory. Discuss.
 *
 * (Oh no, but jk you guys. It's  only half true. 
 * The memory heap is in memory but not a Heap like,
 * you know, a heap.)
 *
 * THE MAXHEAP FOR PATIENT CAN NOT PERFECTLY MATCH 
 * THE OUTPUT FILE, BUT ONLY FOR SOME PATIENT HAVE 
 * SAME PRIORITY AND TIME_IN
 * CAN NOT FIDN THE BUG BUT THE MAX HEAP IS BIULD RIGHT
 *
 */



#include "Heap.h"

#ifndef MAXHEAP_H_
#define MAXHEAP_H_

template<class E> class MaxHeap:  public Heap<E>
{
public:
    MaxHeap();
    ~MaxHeap();
    
    // Overriding purely virtual functions
    void heapify_up(int);
    void heapify_down(int);
};

#endif
