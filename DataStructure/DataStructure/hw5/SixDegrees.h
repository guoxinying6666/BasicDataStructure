/*
 * SixDegrees.h
 *
 * Interface for SixDegrees class
 *
 * COMP15
 * Spring 2018
 * Homework 5
 * Author: Xinying Guo
 * date: Monday,April 2
 *
 */

#include "Graph.h"
#include "Queue.h"
#include "Actor.h"
#include <istream>
#include <fstream>
#include <iostream>
#include <ostream>

#ifndef SIXDEGREES_H_
#define SIXDEGREES_H_

// The file is going to be read into Graph
const string INPUT = "actors.txt";
// The maxmum actors can be read in Graph
const int NUM_ACTORS = 200;

class SixDegrees
{
public:
    SixDegrees();
    ~SixDegrees();

    // Functions of populating tree and BFS
    void populate_graph_from_file();
    void populate_actors_from_file(string);
    void find_BFS(istream &, ostream &);
    void run(istream &, ostream &);
    void BFS(Actor, Actor, ostream &out);

    // Mutator
    string get_edges(Actor,Actor);

private:

    Graph<Actor> *g;
    Actor actor[NUM_ACTORS];
};

#endif