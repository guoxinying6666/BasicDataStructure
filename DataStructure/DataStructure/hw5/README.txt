Name:           Xinying Guo
UserName:       xinying

Comp15 HW5
*******************************************************************************
Overview  of the modules used and data structure:

NodeType.h:

LinkedList.h
LinkedList.cpp  :     Was used in implementing the Actor class. Storing movies the actor played.  

Stack.h
Stack.cpp:      :     Was used in Graph.cpp to store obeject in order to report path. 

Queue.h 
Queue.cpp 		:     Was used in BFS() of sixdegrees to store actors to generate shortest path.      

Actor.h
Actor.cpp	    :     One of data type can be stored in ADT of Graph, Stack, Queue. 
					  Sixdegrees class generate graph Using actors. Main program is basing on this class.

Graph.h
Graph.cpp:      :     The ADT graph, including all the function needed to generate graph and parameters
					  being used in graph. The graph class is the template of int, char, string, actor. 

Sixdegrees.h
Sixdegrees.cpp	:     This class is responsible for the Graph itself, and for interacting with the user. 
					  It have a Graph of Actor objects as its attribute. It populated graph of actors from file, and 
					  using BFS to find its shortest path between actors. 

test_graph.cpp: :	  This class is responsible for unit testing functions implemented in graph and sixdegrees. 

main.cpp		:     The driver responsible for run the main program. 

*******************************************************************************
ADT used and key algorithm: 

ADT: 
LinkedList : Template of int, double, string. It was been used for stroing movies in the actor class. 
Stack: Template of int, char, string, Actor. It was used for Graph class to store object and report path. 
Queue: Template of int, cahr, string, Acror. It was used for BFS() function in Sixdegree class to store current 
	   actors and it's neighbors. BFS function was realized through recursively finding neighbors, enqueue, dequeue, and finding neighbir's neighbors.

Key algorithm:
Graph: The graph was implemented by Adjacency matrix. The Graph class including vertices, edges, path, and marks. The vertices 	 	   store the vertices being added to the graph, and the edges matrix store the edges between vertices (undirected). The path array was been used to record path from one vertex to another by recording the position of vertices. The marks was being used to record whether the vertices was been processed or not. By using marks, we can reduce the complexity of calculation of graph. The graph class have other functions to help realize populating graph and doing things using graph.  

BFS: BFS using a method of finding all the neighbors from a beginger and finding the neighbors of the beginger's neighbors to find the shortest path from one actor the the other. 1. We enqueue the beginer to q1 and mark it and 2. dequeue it find it's neighbors to q2 and update precessor. 3. if we can find the end from q2, we stop searching. If we can't find the end from q2, we dequeue neighbors from q2 and enqueue them to q1 and mark them. Repeat the step (123) until we find the end, and we can report the path. 

*******************************************************************************
Challenges and complementation:

All the part of assignment was being accomplished. Myoutput.txt file is slightly different from the expected_output.txt. The first differences is "to" and "and". The assignment said that we should print out " and " but the expected_output.txt print out "to". The rest problems are all because actors have different common movies. We can fix it through changing the connect() function in Actor.cpp. I tested most edges problems I was aware of, but I cannot garantee that's the whole thing. 
*******************************************************************************
How I tested my code:

test_get_edge():
I populated a graph using a small document "actorss.txt" and try to find edge of the graph I generated.

The actorss have 5 objects need to be read: 
name1--movie1->name6--movie3->name2;
name2--movie4->name3--movie4->name6--movie3->name1;
name3--movie4->name2--movie4->name6;
movie4;
name6--movie4->name2--movie4->name3--movie1->name1;

test_populate_tree():
I populated a graph using a small document "actorss.txt" and get the edges of the graph randomly. 

test_BFS():
I tried to find the shortest path using BFS function and related functions of the small graph I generated. Comparing the output with expected output I calculated using paper and pen. Tested all the edges possible. 

test_coopy_constructor():
I create 1 original graph and using copy constructor to copy it then delete the original function. Test If the copied one can still work the same way as the original graph. I used graph<int> and add edges bwtween vertices to test the copy constructor can work in different situation. I also test whether it can work for empty graph.

test_operator():
The same method I used in testing copy constructor. The differences is I used assignment operator instread of copy constructor. 


*******************************************************************************
DataStructure:

Graph, LinkedList, Queue, Stack. 

Algorithm: 

BFS




