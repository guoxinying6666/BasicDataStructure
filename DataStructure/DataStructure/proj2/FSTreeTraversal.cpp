/*
 * FSTreeTraversal.cpp
 *
 * Traverse the file system from the starting points and 
 * list all subdirectories and files within it
 *
 * COMP15
 * Spring 2018
 * Project 2 
 * Phase 1
 * Author: Xinying Guo
 * date: Monday,April 2
 * 
 * Used FSTree class to finish Traverse
 * Traversing using Dirnode class.
 *
 * How to compile: 
 * clang++ -Wall -Wextra -std=c++11 FSTreeTraversal.cpp 
 * FSTree.cpp DirNode.cpp
 * 
 */
#include "FSTree.h"
#include <istream>
#include <ostream>
#include <iostream>
using namespace std;

// Wrapped functions
// Traverse Tree
void traverse_tree (DirNode *,string);


int main(int argc, char *argv[])
{
	(void) argc;
	FSTree tree(argv[1]);
	DirNode *root = tree.get_root();
	string directory = root->get_name(); 
	traverse_tree(root,directory);
}

// Function traverse_tree()
// Parameters: DirNode *root,string directory
// Returns: void
// Does: Traverse FS tree to print out all the 
//		 files and subdirectories. 
void traverse_tree (DirNode *root,string directory)
{	
	if (directory != root->get_name())
		directory = directory + "/" + root->get_name();

	if (root->has_subdir())
	{
		for (int i = 0; i < root->num_subdirs(); i++)
		{
			traverse_tree(root->get_subdir(i),directory);
		}
	}
	
	if (root->has_files())
	{
		for (int j = 0; j < root->num_files(); j++)
		{
			cout << directory << "/" 
			 		<< root->get_file(j) << endl;
		}
	}
		cout << directory << endl;
}






