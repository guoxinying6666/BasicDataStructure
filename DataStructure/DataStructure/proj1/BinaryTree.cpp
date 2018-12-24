/*
 * BinaryTree.cpp
 *
 * Implementation for base class BinaryTree
 * Starter code for Project 1
 * 
 * COMP15
 * Spring 2018
 *
 * What did the Binary Tree traversal get a dinner?
 *
 * The pre-fix menu!
 */

#include "BinaryTree.h"

// Constructor
BinaryTree::BinaryTree()
{
    root = NULL;
}

// Destructor
BinaryTree::~BinaryTree()
{
    destroy(root);
}
// Copy Constructor
BinaryTree::BinaryTree(const BinaryTree &tree)
{
    root = copy(tree.root);
}
// Override operator
BinaryTree & BinaryTree::operator = (const BinaryTree &tree)
{
    root = copy(tree.root);
    return *this;
}

// Function: copy
// Purpose: Help deep copy the tree 
// Parameters: const BinaryNode
// Returns: BinaryNode *
BinaryNode * BinaryTree::copy (const BinaryNode *curr)
{
    if(curr == NULL)
    {
        return NULL;
    }
    BinaryNode *tmp = new BinaryNode;
    tmp->info = curr->info;
    tmp->left = copy(curr->left);
    tmp->right = copy(curr->right);
    return tmp;
}

// Function get_length (const)
// Counts the total number of nodes in the tree
int BinaryTree::get_length() const
{
    return count_nodes(root);
}

// Function get_leaves (const)
// Counts the total number of leaves in the tree
int BinaryTree::get_leaves() const
{
    return count_leaves(root);
} 

// Function get_height (const)
// Counts the total height of the tree
int BinaryTree::get_height() const
{
    return count_height(root);
}

// Inorder traversal
void BinaryTree::inorder(ostream &out) const
{
    print_inorder(root, out);
}

// preorder traversal
void BinaryTree::preorder(ostream &out) const
{
    print_preorder(root, out);
}

// postorder traversal
void BinaryTree::postorder(ostream &out) const
{
    print_postorder(root, out);
}

// Function insert_item
// Checks for fullness, throws exception if necessary
// insert item into next open slot
void BinaryTree::insert_item(TreeItem item)
{
    if (is_full())
        throw FullTree();
    else
        insert_bt(root, item);
}

// Function find_item
// finds the given item using queue as auxiliary structure
void BinaryTree::find_item(TreeItem &item, bool & found) const
{
    find_bt(root, item, found);
}

// Function remove_item
// Checks for empty tree, throws exception if necssary
// remove item, if found
void BinaryTree::remove_item(TreeItem item)
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
            remove_bt(root, item);
    }
}

// Return the item at the deepest left node
// (Would come first in an in-order traversal)
// Throws exception if tree is empty
TreeItem BinaryTree::get_leftmost() const
{
    return return_leftmost(root);
}


// Function: is_full
// Purpose: Check whether tree is full
// Parameters: None
// Returns: bool
bool BinaryTree::is_full()
{
    try
    {
        BinaryNode *node = new BinaryNode;
        delete node;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}

// Function: is_empty
// Purpose: Check whether tree is empty
// Parameters: None
// Returns: bool
bool BinaryTree::is_empty()
{
    return (root == NULL);
}

// Function: get_average_age
// Purpose: Get average age of the TreeItem
// Parameters: None
// Returns: double
double BinaryTree::get_average_age() const
{
    return average_age(root);
}

// Return the item at the deepest right node
// (Would come first in an in-order traversal)
// Throws exception if tree is empty
TreeItem BinaryTree::get_rightmost() const
{
    return return_rightmost(root);
}

// Function: print
// Purpose: Print Tree root and information
// Parameters: ostream &out
// Returns: Nothing
void BinaryTree::print(ostream &out) const
{
    // Call print function in Survivor
    root->info.print(out);
    out << "Height: " << dec << get_height() << endl
        << "Number of nodes: " << dec << get_length() << endl
        << "Number of leaves: " << dec << get_leaves() 
        << "\n" <<endl;
}

// Function: print_root
// Purpose: Print Tree root
// Parameters: ostream &out
// Returns: Nothing
void BinaryTree::print_root(ostream &out) const
{
    root->info.print(out);
}

/* Definitions for Recursive Wrapper Functions */

// Function destroy (wrapper)
// Used by destructor and = operator
// Follows postfix order, deletes nodes one by one
void destroy(BinaryNode *&tree)
{
    if (tree != NULL)
    {
        destroy(tree->left);
        destroy(tree->right);
        delete tree;
    }
}

// Recursively counts the total number of nodes in the tree
int count_nodes(BinaryNode *tree)
{
    if (tree == NULL)
        return 0;
    else
        return count_nodes(tree->left) + count_nodes(tree->right) + 1;
}

// Recursively counts the total number of the leaves in the tree
int count_leaves(BinaryNode *tree)
{
    if (tree == NULL)
        return 0;
    else if (count_nodes(tree) == 1)
        return count_leaves(tree->left) + count_leaves(tree->right) +1;
    else 
        return count_leaves(tree->left) + count_leaves(tree->right);        
}

int count_height(BinaryNode *tree)
{
    if (tree == NULL)
        return -1;
    else 
        return max(count_height(tree->left),count_height(tree->right)) + 1;
}

// Print in  order
void print_inorder(BinaryNode *tree, ostream &out)
{
    if (tree != NULL)
    {
        print_inorder(tree->left, out);
        tree->info.print(out);
        print_inorder(tree->right, out);
    }
} 

// Print in prefix order
void print_preorder(BinaryNode *tree, ostream &out)
{
    if (tree != NULL)
    {
        tree->info.print(out);
        print_preorder(tree->left, out);
        print_preorder(tree->right, out);
    }
} 

// Print in postfix order
void print_postorder(BinaryNode *tree, ostream &out)
{
    if (tree != NULL)
    {
        print_postorder(tree->left, out);
        print_postorder(tree->right, out);
        tree->info.print(out);
    }
}

// Function insert_bt (wrapper)
// Params: BinaryNode reference, TreeItem
// Returns: void
// Does: Finds next open spot using a queue
//       allocates a new BinaryNode and sets
//       its info to the given tree
void insert_bt(BinaryNode *&tree, TreeItem item)
{
    // enqueue and dequeue until empty
    BinaryNode *temp = NULL;
    BinaryNode *node = new BinaryNode;
    node->info = item;
    node->left = NULL;
    node->right = NULL;
    if (tree == NULL)
    {
        tree = node;
        return;
    }
    
    Queue q;
    q.enqueue(tree);
    while (!q.is_empty())
    {
        q.dequeue(temp);
        if (temp->left != NULL)
        {
            q.enqueue(temp->left);
        }
        else
        {
            temp->left = node;
            return;
        }
        if (temp->right != NULL)
        {
            q.enqueue(temp->right);
        }
        else
        {
            temp->right = node;
            return;
        }
    }
}

// Function find_bt (not a member function)
// Parameters: BinaryNode (root), TreeItem reference, bool reference
// Returns: void
// Does: Uses an auxiliary queue to iterate through each node
//       until the item is found. Updates the item reference with
//       the one actually found, and bool reference with true/false. 
void find_bt(BinaryNode *tree, TreeItem &item, bool &found)
{ 
    found = false;
    if (tree == NULL)
    {
        return;
    }

    Queue q;
    q.enqueue(tree);

    while (!q.is_empty())
    {
        BinaryNode *node; 
        q.dequeue(node);
        if (node->info == item)
        {
            item = node->info;
            found = true;
            return;
        }
        if (node->left != NULL)
            q.enqueue(node->left);
        if (node->right != NULL)
            q.enqueue(node->right);
    }
}

// Function remove_bt (wrapper)
// Parameters: BinaryNode reference (root), TreeItem to remove
// Returns: void
// Does: Uses an auxiliary queue to find the deepest item
//       swaps one to delete with deepest item
//       deletes deepest item
void remove_bt(BinaryNode *&tree, TreeItem item) 
{
    if (tree == NULL)
    {
        return;
    }

    Queue q;
    q.enqueue(tree);

    BinaryNode *deep = NULL, *keynode = NULL;

    while (!q.is_empty())
    {
        q.dequeue(deep);
        if (deep->info == item)
            keynode = deep;
        if (deep->left != NULL)
            q.enqueue(deep->left);
        if (deep->right != NULL)
            q.enqueue(deep->right);
    }

    TreeItem val = deep->info;
    delete_deepest(tree, deep);
    if (deep != keynode)
        keynode->info = val;
}

// Delete deepest node in the tree
// Helper function for remove
void delete_deepest(BinaryNode *&tree, BinaryNode *&deepnode)
{
    Queue q;
    q.enqueue(tree);

    BinaryNode *temp;
    while (!q.is_empty())
    {
        q.dequeue(temp);
        if (temp->right != NULL)
        {
            if (temp->right->info == deepnode->info)
            {
                temp->right = NULL;
                delete deepnode;
                return;
            }
            else
                q.enqueue(temp->right);
        }
        if (temp->left != NULL)
        {
                if (temp->left->info == deepnode->info)
                {
                    temp->left = NULL;
                    delete deepnode;
                    return;
                }
                else
                    q.enqueue(temp->left);
        }
    }
}

// Function return_leftmost(wrapper)
// Params: BinaryNode *, the tree
// Returns: TreeItem, the info in the deepest left node
// Throws exception if tree is empty, it has no leftmost node
TreeItem return_leftmost(BinaryNode *tree)
{
    if (tree == NULL)
        throw EmptyTree();
    else if (tree->left == NULL)
        return tree->info;
    else
       return return_leftmost(tree->left);
}

// Function return_rightmost(wrapper)
// Params: BinaryNode *, the tree
// Returns: TreeItem, the info in the deepest right node
// Throws exception if tree is empty, it has no rightmost node
TreeItem return_rightmost(BinaryNode *tree)
{
    if (tree == NULL)
        throw EmptyTree();
    else if (tree->right == NULL)
        return tree->info;
    else
       return return_rightmost(tree->right);
}

// Function average_age(wrapper)
// Params: BinaryNode *, the tree
// Returns: double, the average age of all castaways
// Find the average age of all castaways
double average_age(BinaryNode *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    return ((average_age(tree->left) 
                * count_nodes(tree->left)) 
            + (average_age(tree->right) 
                * count_nodes(tree->right))
            + tree->info.get_age()) /count_nodes(tree);
}
