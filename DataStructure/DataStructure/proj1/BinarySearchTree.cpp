/*
 * BinarySearchTree.cpp
 *
 * COMP15
 * Spring 2018
 *
 * Implementation for BST class.
 * Inherits from BinaryTree class.
 *
 * Beyonce also wants you to be a SURVIVOR.
 *
 * You thought you'd be stressed but you're chillin'.
 */

//#include <cstddef>
#include "BinarySearchTree.h"

// Member function definitions
BinarySearchTree::BinarySearchTree()
{
    // no action required, base class also called
}

// Destructor requires no action, base class handles it
BinarySearchTree::~BinarySearchTree()
{
    // no action required, base class also called
}

// Copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &tree)
{
    root = copy(tree.root);
}


// Assignment operator
BinarySearchTree & BinarySearchTree::operator = (const BinarySearchTree &tree)
{
    root = copy(tree.root);
    return *this;
}

// Function to insert into a BST
// Throws exception if full
// Calls wrapper function for recursion
void BinarySearchTree::insert_item(TreeItem item)
{
    if (is_full())
        throw FullTree();
    else
        insert_bst(root, item);
}


// Function find_item
// Purpose: Updates the item reference with
//          the one actually found, and bool reference with true/false. 
// Params: TreeItem &item, bool & found
// Returns: void
void BinarySearchTree::find_item(TreeItem &item, bool & found) const
{
    find_bst(root, item, found);
}

// Function remove_item
// Params: TreeItem item
// Returns: Nothing
// Purpose: Remove the item from BST
void BinarySearchTree::remove_item(TreeItem item)
{
        if (is_empty())
        {
            throw EmptyTree();
        }
        else
        {
            bool found = false;
            find_item(item, found);

            if (found)
                remove_bst(root, item);
        }
         
}

// Wrapper function for insert
void insert_bst(BinaryNode *&tree, TreeItem item)
{
    if (tree == NULL)
    {
        tree = new BinaryNode; // this part is why pass by ref
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
        return;
    }
    else if (item < tree->info)
    {
        insert_bst(tree->left, item);
    }
    else if (item > tree->info)   
    {
        insert_bst(tree->right, item);
    }
    else if (item == tree->info)
    {
        return;
    }
}

// Wrapper function for find
// Function: find_bst
// Params: BinaryNode *tree, TreeItem &item, bool &found
// Returns: Nothing
// Purpose: Updates the item reference with
//          the one actually found, 
//          and bool reference with true/false.
void find_bst(BinaryNode *tree, TreeItem &item, bool &found)
{ 
    found = false;
    if (tree == NULL)
    {
        found = false;
        return;
    }
    else if (item < tree->info)
        find_bst(tree->left,item,found);
    else if (item > tree->info)
        find_bst(tree->right,item,found);
    else 
    {
        item = tree->info;
        found = true;
        return;
    }

}

// Function: remove_bst
// Params: BinaryNode *&tree, TreeItem item
// Returns: Nothing
// Purpose: Remove TreeItem from Tree
void remove_bst(BinaryNode *&tree, TreeItem item) 
{
    //tree->info.print(cout);
    if (tree == NULL)
    {
        return;
    }
    else if (item == tree->info)
    {
        if (tree->left == NULL && tree->right == NULL)
            remove_leaves_item(tree);
        else if ((tree->left == NULL && tree->right != NULL) || 
                (tree->right == NULL && tree->left != NULL))
            remove_one_child_node(tree);
        else if (tree->left != NULL && tree->right != NULL)
            get_predecessor(tree);
    }
    else 
    {
        remove_bst(tree->left,item);
        remove_bst(tree->right,item);
    }
}

// Function: remove_leaves_item
// Params: BinaryNode *&tree
// Returns: Nothing
// Purpose: Remove leave TreeItem from Tree
void remove_leaves_item(BinaryNode *&tree)
{
    BinaryNode *tmp = tree;
    tree = NULL;
    delete tmp;    
    return;
}

// Function: remove_one_child_node
// Params: BinaryNode *&tree
// Returns: Nothing
// Purpose: Remove one child node TreeItem from Tree
void remove_one_child_node(BinaryNode *&tree)
{
    if (tree->left == NULL)
    {
        BinaryNode *tmp = tree;
        tree = tree->right;
        delete tmp;
        return;
    }

    if (tree->right == NULL)
    {
        BinaryNode *tmp = tree;
        tree = tree->left;
        delete tmp;
        return;
    }
}

// Function: get_predecessor
// Params: BinaryNode *&tree
// Returns: Nothing
// Purpose: Get_predecessor and return it to root
void get_predecessor(BinaryNode *&tree)
{
    TreeItem tmp = return_rightmost(tree->left);
    remove_bst(tree,tmp);
    tree->info = tmp;
    return;
}