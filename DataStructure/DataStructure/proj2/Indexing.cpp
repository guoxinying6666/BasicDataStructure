/*
 * Indexing.cpp
 *
 * Interface for Indexing words.
 *
 * COMP15 
 * Spring 2018
 *
 * Read file and index words to hash table. 
 * 
 * COMP15
 * Spring 2018
 * Project 2 
 * Phase 2
 * Author: Xinying Guo
 * date: Monday,April 2
 * 
 * How to compile: 
 * make gerp
 *
 */
#include "Indexing.h"    

//Constructor
Indexing::Indexing()
{

}

// Function biuld_tree
// Input: string, Hash &
// Returns: void
// Does:  biuld tree and store data to hash
void Indexing::biuld_tree(string root_directory, Hash &h)
{
    FSTree tree(root_directory);
    DirNode *root = tree.get_root();
    string directory = root->get_name(); 
    traverse_tree(root,directory,h);
}

// Function traverse_tree
// Input: DirNode *root,
// string, Hash &
// Returns: void
// Does:  traverse tree and store 
// the traversed result to hash
void Indexing::traverse_tree(DirNode *root,
                        string directory,Hash &h)
{
    if (directory != root->get_name())
        directory = directory + "/" + root->get_name();

    if (root->has_subdir())
    {
        for (int i = 0; i < root->num_subdirs(); i++)
        {
            traverse_tree(root->get_subdir(i),directory,h);
        }
    }
    
    if (root->has_files())
    {
        for (int j = 0; j < root->num_files(); j++)
        {
            string file = directory + "/" 
                        + root->get_file(j);
            read_in_word(file,h);
        }
    }
}

// Function read_in_word
// Input: string, Hash &
// Returns: void
// Does:  Read the word from file and put
// it to hash table
void Indexing::read_in_word(string file_name, Hash &h)
{
    ifstream infile;
    infile.open(file_name);

    if (!infile.is_open())
        return;

    int count = 0;
    stringstream ss;
    string line,word;

    while (getline(infile,line))
    {
        ss.clear();
        ss << line;
        count++;
        while (ss >> word)
        {
            word = process_string(word);
            // The location information stores file name,
            // line count and the line showing that 
            // word
            string location = file_name + ":" + to_string(count) 
                                + ": " + line;
            put_to_hashing(h, word,location);
        }
    }

    infile.close();

}

// Function put_to_hashing
// Input: Hash &h, 
// string, string
// Returns: void
// Does:  Pute the word and the location to
// hash table
void Indexing::put_to_hashing(Hash &h, 
    string key, string location)
{
    h.insert_item(key, location);
}

// Function: switch_to_lowcase
// Input: string word
// Returns: string
// Does:  switch the word to purely lowcase 
// word and return it.
string Indexing::switch_to_lowcase(string word)
{
    string lowcase = word;
    
    for( char& c : lowcase) 
        c = tolower(c);
    
    return lowcase;
}

// Function: find_bucket_value
// Input: string word
// Returns: size_t
// Does:  find the index of chain in hash table
// by giving string 
size_t Indexing::find_bucket_value(string word)
{
    string lowcase = switch_to_lowcase(word);
    hash<string> h;
    // The storage of word in chain based on 
    // the hash function of lower case of word
    size_t n = h(lowcase);
    return n;

}

// Function: process_string
// Input: string 
// Returns: string
// Does:  Porcess string to get ride of symbols 
// before or after the character
string Indexing::process_string(string query)
{
    int start = 0, end = query.length();

    for (; start < end; start++) {
        if (isalnum(query[start])) {
            break;
        }
    }
    for (; end > start; end--) {
        if (isalnum(query[end])) {
            break;
        }
    }

    return query.substr(start, end - start + 1);
}













