/*
 * SixDegrees.cpp
 *
 * Implementation for SixDegrees class
 *
 * COMP15
 * Spring 2018
 * Homework 5
 * Author: Xinying Guo
 * date: Monday,April 2
 *
 * Implementing the interface of 
 * Graph of Actors
 * mian function: 
 * Populating tree and BFS
 */

#include "SixDegrees.h" 
using namespace std;

// Defalt constructor
SixDegrees::SixDegrees()
{	
	g = new Graph<Actor>(NUM_ACTORS);
}

// Destructor
SixDegrees::~SixDegrees()
{	
	delete g;
}

// Function initialize_graph
// Input: name of file to read
// Returns: void
// Does: Read all the actors from file and populate 
//       into Actor array in sixdegrees
void SixDegrees::populate_actors_from_file(string filename)
{
    ifstream infile;
    infile.open(filename);
    if (!infile.is_open())
    {
        cerr << "Could not open " << filename << " for reading\n";
        exit(1);
    }
    int count = 0;
    string name,movie;

    	while (getline(infile,name))
    	{
    		actor[count].set_name(name);
    		count++;
    		movie = "";
    		while (movie != "*")
    		{
    			getline(infile,movie);
    			if (movie == "*")
    				break;
    			else 
    				actor[count].add_name(movie);
    		}
    	}

    infile.close();
}

// Function populate_graph_from_file
// Input: None
// Returns: void
// Does: Populate graph basing on the actors been  
//       readed by the file
void SixDegrees::populate_graph_from_file()
{
	for (int i = 0; i < NUM_ACTORS; i++)
	{
		g->add_vertex(actor[i]);
	}

	for (int i = 0; i < NUM_ACTORS - 1; i++)
	{
		// n(n-1)/2 times comparasion
		for (int j = i + 1; j < NUM_ACTORS - 1; j++)
		{
			string edge_name = actor[i].connect(actor[j]);
			if (edge_name != "")
			{
				g->add_edge(actor[i-1],actor[j-1],edge_name);
				g->add_edge(actor[j-1],actor[i-1],edge_name);
			}
		}
	}
}

// Function run
// Input: istream &in, ostream &out
// Returns: void
// Does: read in names from istream and  
//       populate tree run BFS result 
// 		 to out 
void SixDegrees::run(istream &in, ostream &out)
{
	populate_actors_from_file(INPUT);
	populate_graph_from_file();
	
	while (!in.eof())
	{
		find_BFS(in,out);
	}
}

// Function find_BFS
// Input: istream &in, ostream &out
// Returns: void
// Does: read 2 name from istream in and 
//       using BFS() to find the shortest path
void SixDegrees::find_BFS(istream &in, ostream &out)
{
	string name1, name2;
	Actor a,b;

	getline(in,name1,'\n');
	if (name1.empty())
		return;
	a.set_name(name1);
	if (!g->is_vertex(a))
	{
		out << "Sorry, " + name1 + " is not in the list\n" << endl;
		// if the name is not in the list, read the next name
		getline(in,name1,'\n');
		if (name1.empty())
			return;
		a.set_name(name1);
	}

	getline(in,name2,'\n');
	if (name1.empty())
		return;
	b.set_name(name2);
	if (!g->is_vertex(b))
	{
		out << "Sorry, " + name2 + " is not in the list\n" << endl;
		// if the name is not in the list, read the next name
		getline(in,name2,'\n');
		if (name1.empty())
			return;
		b.set_name(name2);
	}

	if (g->is_vertex(a) && g->is_vertex(b))
	{
		a = g->find_vertex(a);
		b = g->find_vertex(b);
		BFS(a,b,out);
	}
}

// Function BFS
// Input: Actor a, Actor b, ostream &out
// Returns: void
// Does: Using queue to realize BFS method.
//       and find the shortest path
void SixDegrees::BFS(Actor a, Actor b, ostream &out)
{
	g->clear_marks();
    g->initialize_path();

    Queue<Actor> q1,q2;
    Actor curr,neighbor;
    
    q1.enqueue(a); 
    while (curr != b)
    {
        if (q1.is_empty())
        {
        	out << a.get_name() + " to " + b.get_name() + 
                ": No connnection\n" << endl;
            break;
        }

        q1.dequeue(curr);
        g->mark_vertex(curr);

        if (curr == b)
        {
            g->report_path(out, a, b);
            out << endl;
            return;
        }
        g->get_to_vertices(curr, q2);

        while (!q2.is_empty())
        {       
            q2.dequeue(neighbor);
            if (!g->is_marked(neighbor))
            {
                g->update_predecessor(curr,neighbor);
            }

            if (neighbor == b)
            {
                g->report_path(out, a, b);
                out << endl;
                return;
            }
            else 
            {
                if (!g->is_marked(neighbor))
                	q1.enqueue(neighbor);
            }
        }
    }

}

// Function get_edges()
// Input: Actor a, Actor b
// Returns: string
// Does: Get edge of grapth between Actor a 
// 		 and b
string SixDegrees::get_edges(Actor a, Actor b)
{
	return g->get_edge(a,b);
}
