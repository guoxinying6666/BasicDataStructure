/* COMP15
 * Spring 2018
 * Merge two sorted arrays
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cmath>
#include <string>
using namespace std;

// Merge function prototype
void merge(int [], int [], int [], int);
void insertion_sort(int [], int);

// Helper functions
void populate(int [], int);
bool verify_sorted(int [], int);

const int MAX_SIZE = 10000;
const int RANGE = 1000;

int main(int argc, char *argv[])
{
    srand(time(NULL));

    if (argc != 2)
    {
        cerr << "Usage: ./a.out [size]\n";
        return -1;
    }
    
    int num_values = atoi(argv[1]);
    if (num_values > MAX_SIZE)
        num_values = MAX_SIZE;

    // Declare and initialize the two sub arrays
    int *ray1 = new int[num_values];
    int *ray2 = new int[num_values];
    populate(ray1, num_values);
    populate(ray2, num_values);

    // Sort each one individually
    insertion_sort(ray1, num_values);
    insertion_sort(ray2, num_values);

    // Sanity check
    cout << "Before merging, here are my two arrays\n";
    for (int i = 0; i < num_values; i++)
        cout << ray1[i] << " ";
    cout << endl << endl;
    for (int i = 0; i < num_values; i++)
        cout << ray2[i] << " ";
    cout << endl << endl;

    // Merge the two into one big fat sorted output
    int *sorted = new int[num_values * 2];
    merge(ray1, ray2, sorted, num_values);

    if (verify_sorted(sorted, num_values * 2))
        cout << "Sort SUCCESS!\n";
    else
        cout << "Sort FAIL\n";


    delete []ray1;
    delete []ray2;
    delete []sorted;

    return 0;

}

// Function populate
// Input: array to fill up, size
// Returns: void
// Does: generates a bunch of random numbers
//       and fills up the array
void populate(int ray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int n = rand() % RANGE;
        int neg = rand() % 2;
        if (neg == 1)
            n = n * -1;
        ray[i] = n;
    }
}

// Function verify_sorted
// Input: array of ints, int for size
// Returns: bool
// Does: iterates through the array, comparing each number
//       to its successor and ensuring the values are
//       monotonically increasing. Returns true if sorted
bool verify_sorted(int ray[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        cout << ray[i] << " ";
        if (ray[i] > ray[i+1])
        {
            cout << "i = " << i << " and value is " << ray[i] << endl;
            cout << "i+1 = " << i+1 << " and value is " << ray[i+1] << endl;
            return false;
        }
    }
    cout << ray[size-1] << endl << endl;
    return true;
}

// Function insertion_sort (in-place)
// Input: array of ints, int for size
// Returns: void
// Does: Picks the next unsorted number, and 
//       finds correct slot for it in the sorted
//       subarray
void insertion_sort(int ray[], int size)
{
    int curr_value;
    for (int i = 0; i < size; i++)
    {
        curr_value = ray[i];
        for (int j = 0; j < i; j++)
        {
            if (curr_value < ray[j])
            {
                for (int k = i; k > j;k--)
                    ray[k] = ray[k-1];
                ray[j]= curr_value;
                break;
            }
        }
    }
}

// Function: merge
// Input: two sorted arrays of equal size
//        one unpopulated output array, and int for size
// Returns: void
// Does: merges the two sorted arrays into one big
//       fat output array. Assumes both are the same size.
void merge(int ray1[], int ray2[], int result[], int size)
{
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    while (c1 < size && c2 < size)
    {
        if (ray1[c1] < ray2[c2])
            result[c3++] = ray1[c1++];
        else
            result[c3++] = ray2[c2++];
    }

    if (c1 == size)
        while (c2 < size)
            result[c3++] = ray2[c2++];

    else
        while (c1 < size)
            result[c3++] = ray1[c1++];

}

