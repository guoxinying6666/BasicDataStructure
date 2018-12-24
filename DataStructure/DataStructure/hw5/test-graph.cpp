/*
 * test_graph.cpp
 *
 * Test for Graph of Kevin Bacon
 *
 * COMP15
 * Spring 2018
 * Author: Xinying Guo
 * date: Monday,April 2
 * 
 * Fun fact: Kevin Bacon's dad is locally famous,
 * but not for acting. He's a city planner for 
 * Philadelphia, and was on the cover of TIME
 * in 1964.
 */
#include "SixDegrees.h"
#include <sstream>
#include <istream>
#include <ostream>
using namespace std;

// Wrapped functions
// Test whether populate the tree successful
void test_populate_tree(SixDegrees *);
// Test whether BFS work successful
void test_BFS(SixDegrees *);
// Test whether copy constructor work Successful
void test_coopy_constructor();
// Test whether get_edge work successful
void test_get_edge(SixDegrees *);
// Test whether assignment operator work successful
void test_operator();


int main()
{
	SixDegrees *x = new SixDegrees;

	test_get_edge(x);
	test_populate_tree(x);
	test_BFS(x);
	test_coopy_constructor();
	test_operator();

	delete x;
}

// Function test_get_edge
// Input: SixDegrees *x
// Returns: void
// Does: test whether get_edges in SixDegrees 
// function work 
void test_get_edge(SixDegrees *x)
{
	string file = "actorss.txt";
	Actor a,b;

	x->populate_actors_from_file(file);
	x->populate_graph_from_file();

	a.set_name("name1");
	b.set_name("name2");
	string outcome1 = x->get_edges(a, b);
	string outcome2 = x->get_edges(b, a);

	if ((outcome1 == "movie3") && (outcome2 == "movie3"))
		cout << "get edge successful" << endl;
	else 
		cout << "get edge fail" << endl;
}

// Function test_populate_tree
// Input: SixDegrees *x
// Returns: void
// Does: Test whether the tree been populated 
// 		 successfully
void test_populate_tree(SixDegrees *x)
{
	Actor a,b,c,d;

	a.set_name("name1");
	b.set_name("name2");
	c.set_name("name3");
	d.set_name("name4");

	string outcome1 = x->get_edges(a, b);
	string outcome2 = x->get_edges(b, a);
	string outcome3 = x->get_edges(b, c);
	string outcome4 = x->get_edges(c, b);

	if ((outcome3 == "movie4") && (outcome4 == "movie4")
		&& (outcome1 == "movie3") && (outcome2 == "movie3"))
		cout << "populate tree is successful" << endl;
	else 
		cout << "populate tree fail" << endl;

}

// Function test_BFS
// Input: SixDegrees *x
// Returns: void
// Does: Test whether the BFS function work
// 		 successfully
void test_BFS(SixDegrees *x)
{
	stringstream ss1,ss2,ss3,ss4;
	stringstream out1,out2,out3,out4;
	string outcome1,outcome2,outcome3,outcome4;

	ss1 << "name1\nname2";
	ss2 << "name5\nname3";
	ss3 << "name4\nname1";
	ss4 << "name2\nname3";

	x->find_BFS(ss1,out1);
	x->find_BFS(ss2,out2);
	x->find_BFS(ss3,out3);
	x->find_BFS(ss4,out4);

	getline(out1,outcome1);
	getline(out2,outcome2);
	getline(out3,outcome3);
	getline(out4,outcome4);

	// if the first line of the output is correct, we assume that the 
	// output is correct
	if (outcome1 == "name1 and name2 have a costar distance of 1")
		cout << "vertex with multiple valid path test success" << endl;
	if (outcome2 == "Sorry, name5 is not in the list")
		cout << "The item is not in the graph test success" << endl;
	if (outcome3 == "name4 to name1: No connnection")
		cout << "There is no valid path test success" << endl;
	if (outcome4 == "name2 and name3 have a costar distance of 1")
		cout << "There is only one path test success" << endl;
}

// Function test_coopy_constructor
// Input: None
// Returns: void
// Does: Test whether copy constructor of the graph work
// 		 successfully
void test_coopy_constructor()
{
	Graph<int> *g = new Graph<int>;
	Graph<int> *p = new Graph<int>(*g);

	// If we delete the original graph and leave the copied one
	// The one is suposed to work the function of graph
	delete g;

	if (!p->is_marked(5))
		cout << "empty graph copy constructor success" << endl;

	// We create a graph with vertices and edges
	// To test whether the graph was been tested
	Graph<int> *w = new Graph<int>(10);
	w->add_vertex(1);
	w->add_vertex(2);
	w->add_vertex(3);
	w->add_vertex(4);
    w->add_edge(1, 2, "1 and 2");
    w->add_edge(1,3,"1 and 3");
    w->add_edge(3,4,"3 and 4");
    Graph<int> *e = new Graph<int>(*w);

    // If we delete the original graph and leave the copied one
	// The one is suposed to work the function of graph
    delete w;

    // if we can get the edge, we can prove that 
	// the graph was been copied
    if (e->is_vertex(3))
    	cout << "Graph with vertices copy" 
    	<< " constructortest success" << endl;
    if(e->get_edge(1,3) == "1 and 3")
    	cout << "Graph with edges copy" 
    	<< " constructor test success" << endl;

	delete p;
	delete e;
}

// Function test_operator
// Input: None
// Returns: void
// Does: Test whether copy assignment 
// 		 operator of the graph work successfully
// Using the same method we used to test copy constructor
void test_operator()
{
	Graph<int> *g = new Graph<int>;
	Graph<int> *p = new Graph<int>;

	*g = *p;
	delete g;
	if (!p->is_marked(5))
		cout << "empty graph assignment operator" 
		<< " constructor success" << endl;

	Graph<int> *w = new Graph<int>(10);
	w->add_vertex(1);
	w->add_vertex(2);
	w->add_vertex(3);
	w->add_vertex(4);
    w->add_edge(1, 2, "1 and 2");
    w->add_edge(1,3,"1 and 3");
    w->add_edge(3,4,"3 and 4");
    Graph<int> *e = new Graph<int>;
    *e = *w;
    delete w;

    if (e->is_vertex(3))
    	cout << "Graph with vertices assignment" 
    	<< " operator test success" << endl;
    if(e->get_edge(1,3) == "1 and 3")
    	cout << "Graph with edges assignment"  
    	<< " operator test success" << endl;

	delete p;
	delete e;

}




