/*
*
*
*
*/
#include "BinarySearchTree.h"
#include <cmath>
using namespace std;

#define CASTAWAY 36
#define STOWAWAY 42

void insert_bt1(ifstream &, BinaryTree *);
void insert_bt2(ifstream &, BinaryTree *);
BinaryTree * round_one(BinaryTree *, BinaryTree *);
void populate_tree(BinaryTree *, BinaryTree *);
void round_two(BinaryTree *&);

int main()
{

    BinaryTree *BT = new BinaryTree;
    BinaryTree *BST = new BinarySearchTree;
    
    populate_tree(BT,BST);
    BinaryTree *first_round = round_one(BT,BST);
    round_two(first_round);
    
    delete BT;
    delete BST;   
}

void populate_tree(BinaryTree *BT1, BinaryTree *BT2)
{
	ifstream infile1,infile2;
	int rando = rand () % 2 + 1; 
    
    infile1.open("castaways.txt");
    infile2.open("stowaways.txt");
 	
    if (rando == 1)
    {
    	insert_bt1(infile1,BT1);
    	insert_bt2(infile2,BT2);
    }  
    else
    {
    	insert_bt1(infile1,BT2);
    	insert_bt2(infile2,BT1);
    } 

    infile1.close();
    infile2.close();
}

void insert_bt1(ifstream &infile, BinaryTree *BT)
{
	int survivor_count1 = 0;
	Survivor *castaways = new Survivor[CASTAWAY];

	for (int i = 0; i < CASTAWAY; i++)
	{
		survivor_count1 = 
		castaways[i].generate_the_next_castaway(infile,survivor_count1);
		BT->insert_item(castaways[i]);
	}

	delete [] castaways;
}

void insert_bt2(ifstream &infile, BinaryTree *BT)
{
	int survivor_count2 = 0;
	Survivor *stowaways = new Survivor[STOWAWAY];

	for (int i = 0; i < STOWAWAY; i++)
	{
		survivor_count2 = 
		stowaways[i].generate_the_next_castaway(infile,survivor_count2);
		BT->insert_item(stowaways[i]);
	}

	delete [] stowaways;
}

BinaryTree * round_one(BinaryTree *BT, BinaryTree *BT2)
{
	int a = BT->get_leaves();
	int b = BT2->get_leaves();

	if (b < a) 
	{
		cout << "loser have " << a << " leaves\n" 
			 << "ROUND ONE WINNER: BST" << endl;
		BT2->print(cout);
		return BT2;
	}	
	else
	{
		cout << "loser have " << b << " leaves\n"
			<< "ROUND ONE WINNER: BT" << endl;
		BT->print(cout);
		return BT;
	}
}



void round_two(BinaryTree *&BT)
{
 	if (BT->get_length() == 1)
 	{
 		cout << "WINNING SURVIVOR" << endl;
 		BT->print_root(cout);
 		return;
 	}
 	else
 	{
 		double average_age = BT->get_average_age();

 		cout << "Average age this round " << average_age << endl;
 		TreeItem item1 = BT->get_leftmost();
 		TreeItem item2 = BT->get_rightmost();

 		if (abs(item1.get_age()-average_age) 
 			< abs(item2.get_age()-average_age))
 		{
 			cout << "Voted off the island:" << endl;
 			item2.print(cout);
 			BT->remove_item(item2);
 		}	
 		else
 		{
 			cout << "Voted off the island:" << endl;
 			item1.print(cout);
 			BT->remove_item(item1);
 		}

 		round_two(BT);
 	}	
}