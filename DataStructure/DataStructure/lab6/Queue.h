#include <iostream>
using namespace std;

#ifndef NODE_TYPE_H_
#define NODE_TYPE_H_

template<class E>
struct NodeType
{
    E info;
    NodeType<E> *next;
};

#endif

#ifndef QUEUE_H_
#define QUEUE_H_

class FullQueue : public exception {
public:
  const char *what() const throw() { return "Full Queue OVERFLOOOOW";}
};

class EmptyQueue : public exception {
public:
  const char *what() const throw() { return "Queue is Empty!";}
};


template<class E>
class Queue
{
private:
    NodeType<E> *front;
    NodeType<E> *rear;

public:
    Queue();

    // The Rule of Three!
    ~Queue();
    Queue(const Queue &);
    Queue & operator = (const Queue &);

    void make_empty();
    void enqueue(E);
    void dequeue(E &);
    bool is_empty() const;
    bool is_full() const;
};

#endif
