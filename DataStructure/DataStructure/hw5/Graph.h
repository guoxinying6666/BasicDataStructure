/*
 * Graph.h
 * 
 * Interface for Graph class
 *
 * COMP15
 * Spring 2018
 * Homework 5
 * Author: Xinying Guo
 * date: Monday,April 2
 *
 * Jump back.
 */

#include <ostream>
#include <string>
#include <iostream>
#include "Queue.h"
#include "Actor.h"
#include "Stack.h"
using namespace std;

#ifndef GRAPH_H_
#define GRAPH_H_

class FullGraph : public exception {
public:
  const char *what() const throw() { return "My graph is full";}
};

class EmptyGraph : public exception {
public:
  const char *what() const throw() { return "My graph is empty";}
};

const string NULL_EDGE = "NONE";
const int NULL_PRED = -1;

// wrapper functions
template<class Vertex>
int index_is(Vertex *vertices, Vertex v);

template<class Vertex>
class Graph
{
public:
    Graph();
    Graph(int);
    Graph(const Graph &);
    ~Graph();

    // Assignment operator
    Graph & operator =(const Graph &);

    // Mutator functions
    void initialize_graph(int);
    void add_vertex(Vertex);
    void add_edge(Vertex, Vertex, string);

    // Accessor functions
    void print_matrix(ostream &) const;
    string get_edge(Vertex, Vertex) const; 
    int get_path_length() const;
    Vertex find_vertex(Vertex) const;

    // Helpers for BFS, DFS
    void get_to_vertices(Vertex, Queue<Vertex> &) const;
    void clear_marks();
    void mark_vertex(Vertex);
    bool is_marked(Vertex) const;
    bool is_vertex(Vertex) const;
    void initialize_path();
    void update_predecessor(Vertex, Vertex);
    void report_path(ostream &, Vertex, Vertex) const;

private:
    int curr_vertex;
    int num_vertices;
    Vertex *vertices;
    string **edges;
    int *path;
    bool *marks;
};

#endif


