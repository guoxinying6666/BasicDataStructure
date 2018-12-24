/*
 * test-bst-driver.cpp
 *
 * Tests BASIC functionality of the BinarySearchtree class
 * Just the stuff from starter code.
 * 
 * Write your own tests.
 *
 * Have you written some tests?
 * 
 * Now write some more tests.
 * 
 * That's not enough tests.
 * 
 * COMP15
 * Spring 2018
 *
 */

#include <iostream>
#include <string>
#include "BinarySearchTree.h"
using namespace std;

// Test functions for the BST operations
void test_get_length(BinaryTree *, int);
void test_insert(BinaryTree *);
void test_preorder(BinaryTree *);
void test_inorder(BinaryTree *);
void test_postorder(BinaryTree *);
void test_get_left(BinaryTree *);
void test_remove(BinaryTree *);

int main()
{
    //BinarySearchTree *BST = new BinarySearchTree;
    BinaryTree *BT = new BinaryTree;
    //test_insert(BST);
    BT->preorder(cout);
    BinaryTree *BT2 = new BinaryTree(*BT);
    //BinarySearchTree BST3 = *BST;
    delete BT;
    delete BT2;
    //BT2->preorder(cout);
    //BST->preorder(cout);
    //BST3.preorder(cout);
    //test_remove(BST);
    //delete BT2;
    //delete BST3;
    

}

// Function test_insert
// Parameters: BT pointer, int for # of inserts
// Returns void
// Does: prints success if all the inserts worked
void test_insert(BinaryTree *bt)
{
    Survivor *vives = new Survivor[6];
    for (int i = 0; i < 5; i++)
    {
        string lname = "Hatch";
        lname += to_string(i+1);
        vives[i].set_name("Richard", lname);
        bt->insert_item(vives[i]);
    }
    vives[5].set_name("Richard", "Hatch1.5");
    bt->insert_item(vives[5]);

    if (bt->get_length() == 6)
    {
        cout << "test insert SUCCESS!\n";
    }
    else
    {
        cout << "test insert FAIL\n";
    }
    delete []vives;
}

// Function test_get_length
// Parameters: BT pointer, int for expected length
void test_get_length(BinaryTree *bt, int num_items)
{
    if (bt->get_length() == num_items)
    {
        cout << "test get length SUCCESS!\n";
    }
    else
    {
        cout << "test get length FAIL\n";
    }
}

// Print a preorder traversal
void test_preorder(BinaryTree *BT)
{
    cout << "Begin preorder test.\n";
    BT->preorder(cout);
    cout << "Expected Hatches: 1 2 3 4 5\n";
    cout << "Did that look right? If so then SUCCESS!\n\n";
}

// Print an inorder traversal
void test_inorder(BinaryTree *BT)
{
    cout << "Begin inorder test.\n";
    BT->inorder(cout);
    cout << "Expected Hatches: 1 2 3 4 5\n";
    cout << "Did that look right? If so then SUCCESS!\n\n";
}

// Print a postorder traversal
void test_postorder(BinaryTree *BT)
{
    cout << "Begin postorder test.\n";
    BT->postorder(cout);
    cout << "Expected Hatches: 5 4 3 2 1\n";
    cout << "Did that look right? If so then SUCCESS!\n\n";
}

// test_get_left
// Makes sure we correclty find the leftmost node
void test_get_left(BinaryTree *bt)
{
    TreeItem t = bt->get_leftmost();
    Survivor s;
    s.set_name("Richard", "Hatch1");
    if (t == s)
        cout << "test get_left SUCCESS\n";
    else
        cout << "test get_left FAIL\n";
}

void test_remove(BinaryTree *BT)
{
    Survivor leaf("Richard", "Hatch2","None","None",0), 
        root("Richard", "a","None","None",0),
        deepest("Richard", "c","None","None",0),
        alreadyremoved("Richard", "d","None","None",0),
        a("Richard", "e","None","None",0),
        b("Richard", "Hatch4","None","None",0);

    //BT->root->info.print(cout);   
    BT->inorder(cout);
    BT->remove_item(leaf);
    //cout << "delete" << endl;
    
    BT->remove_item(root);
    //BT->remove_item(deepest);
    //BT->remove_item(a);
    //BT->remove_item(b);
    BT->inorder(cout);
    BT->remove_item(alreadyremoved);


}
