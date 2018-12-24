#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "HashTable.h"
#include "HashString.h"
using namespace std;

/*

For hash_value1():

For tiny-input.txt
Inserted a total of 224 items
total collisions: 17
elapsed time: 0.0206011

For dictionary.txt
Inserted a total of 272013 items
total collisions: 1671264
elapsed time: 0.138486

For directories.txt
Inserted a total of 2338 items
total collisions: 153
elapsed time: 0.00574279


For hash_value2():

For tiny-input.txt
Inserted a total of 224 items
total collisions: 24942
elapsed time: 0.0199866

For dictionary.txt
Inserted a total of 272013 items
total collisions: 199981676
elapsed time: 5.11784

For directories.txt
Inserted a total of 2338 items
total collisions: 2730193
elapsed time: 0.100854

For hash_value3():

For tiny-input.txt
Inserted a total of 224 items
total collisions: 11174
elapsed time: 0.00225717

For dictionary.txt
Inserted a total of 272013 items
total collisions: 198879251
elapsed time: 4.71007

For directories.txt
Inserted a total of 2338 items
total collisions: 2678279
elapsed time: 0.0671105

I changed the MAX_ITEMS = 40000, using 
The hash_value() 3:

For dictionarys.txt:
Inserted a total of 272013 items
total collisions: 797770769
elapsed time: 19.6422


*/
int read_input(char *, Hash<HashString> &);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Usage: ./hasher [inputfile]\n";
        return -1;
    }

    auto start = chrono::system_clock::now();

    Hash<HashString> h;
    int cols = read_input(argv[1], h);

    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "total collisions: " << cols << endl;
    cout << "elapsed time: " << elapsed.count() << endl;

    return 0;
}

int read_input(char *filename, Hash<HashString> &h)
{
    int total_collisions = 0;

    ifstream infile;
    infile.open(filename);
    if (!infile.is_open())
    {
        cerr << "Could not open " << filename << " for reading\n";
        return total_collisions;
    }

    string curr_word;
    int total_count = 0;
    while (!infile.eof())
    {
        infile >> curr_word;
        if (curr_word == "-1")
            break;

        HashString str(curr_word);
        total_collisions += h.insert(str);
        total_count++;
    }
    infile.close();

    cout << "Inserted a total of " << total_count << " items\n";
    return total_collisions;
}
