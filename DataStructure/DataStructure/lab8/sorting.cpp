/* COMP15
 * Spring 2018
 * Lab 8: Starter Code
 * Sorting! 
 * input size: 10 100 1000 10000
 * selection aux: 9.9405e-05 0.000130602 0.00480434 0.382813
 * selection in-place: 6.8408e-05 0.000111015 0.00219726 0.200322 
 * Mergesort: 7.9087e-05 0.000102761 0.00210522 0.194635
 * Quicksort: 0.000105621 9.8534e-05 0.000240248 0.00234544
 *
 * Quick sort is quicker than other sort even if its complexity is 
 * O(n^2). mergesort is slightly quicker than selection-in place sort.
 * The selection in-place sort is quicker than selection auxiliary sort. 
 * Basig on my data.
 * 
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <ctime>
#include <climits>
using namespace std;

// Sorting function prototypes
void insertion_sort(int [], int);
void selection_aux(int [], int);
void selection_place(int [], int);
void mergesort(int [], int, int);
void quicksort(int [], int, int);
void merge(int [], int, int, int);
int partition(int [], int, int);

// Helper functions
void populate(int [], int);
bool verify_sorted(int [], int);

const int MAX_SIZE = INT_MAX;
const int RANGE = 10000;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "Usage: ./sort [sortname] [num]\n";
        return -1;
    }

    int num_values = atoi(argv[2]);
    if (num_values < 1 || num_values > MAX_SIZE)
        num_values = MAX_SIZE;

    // Measure wall-clock time
    auto start = chrono::system_clock::now();

    // Declare and initialize the array
    int *ray = new int[num_values];
    populate(ray, num_values);

    if (num_values <= 0)
    {
        cerr << "Unable to sort, exiting\n";
        return -1;
    }
    
    if (string(argv[1]) == "quicksort")
        quicksort(ray, 0, num_values-1);
    else if (string(argv[1]) == "insertion")
        insertion_sort(ray, num_values);
    else if (string(argv[1]) == "selection-aux")
        selection_aux(ray, num_values);
    else if (string(argv[1]) == "selection-place")
        selection_place(ray, num_values);
    else if (string(argv[1]) == "mergesort")
        mergesort(ray, 0, num_values-1);
    else
        cerr << "Unknown sorting algorithm, exiting\n";

    if (verify_sorted(ray, num_values))
        cout << "Sort SUCCESS!\n";
    else
        cout << "Sort FAIL\n";


    delete []ray;

    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "elapsed time: " << elapsed.count() << endl;

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
        if (ray[i] > ray[i+1])
            return false;
    }
    return true;
}

// Function: selection sort, aux array
// Input: array of ints, int for size
// Returns: void
// Does: Finds next element from unsorted array
//       to put in sorted output array 
// This is the one we implemented in real-time
// during lecture last week!
void selection_aux(int ray[], int size)
{
    int *newray = new int[size];

    for (int i = 0; i < size; i++)
    {
        int largest = ray[i];
        int largest_index = i;
        int nlength = size;

        for (int j = 0; j < nlength; j++)
        {
            if (ray[j] > largest)
            {
                largest = ray[j];
                largest_index = j;
            }
        }
        newray[(size-i)-1] = ray[largest_index];

       nlength--;
       ray[largest_index] = -99999;
    }

    for (int i = 0; i < size; i++)
        ray[i] = newray[i];

    delete [] newray;
}

// Function insertion_sort (in place)
// Input: array of ints, int for size
// Returns: void
// Does: Repeatedly chooses the next element
//       and places it into its correct position.
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


// Function mergesort
// Input: array of ints, low, high
// Returns: void
// Does: Cuts the array in half at the midpoint,
//       recursively sorts the left and right subarrays
//       and merges the results back together
void mergesort(int ray[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(ray, low, mid);
        mergesort(ray, mid+1, high);
        merge(ray, low, high, mid);
    }
}


// Function merge
// Helper function for mergesort
// Merges two already-sorted array
void merge(int ray[], int low, int high, int mid)
{
    int i = low, k = 0, j = mid + 1;
    int *c = new int[(high-low)+1];
    while (i <= mid && j <= high)
    {
        if (ray[i] < ray[j])
            c[k++] = ray[i++];
        else
            c[k++] = ray[j++];
    }
    while (i <= mid)
        c[k++] = ray[i++];
    while (j <= high)
        c[k++] = ray[j++];

    for (i = 0; i < k; i++)
        ray[i+low] = c[i];

    delete [] c;
}

// Function: selection sort in place
// Input: array of ints, int for size
// Returns: void
// Does: Finds next element from unsorted subarray
//       to put in sorted subarray 
void selection_place(int ray[], int size)
{
  int nlength = size;

    for (int i = 0; i < size; i++)
    {
        int largest = ray[0];
        int largest_index = 0;

        for (int j = 0; j < nlength; j++)
        {
            if (ray[j] > largest)
            {
                largest = ray[j];
                largest_index = j;
            }
        }
 
	   int tmp = ray[(size-i) -1];
	   ray[(size-i) - 1] = ray[largest_index];
	   ray[largest_index] = tmp;
       nlength--;
    }
}


// Function quicksort
// Input: array, int for low/high
// Returns: void
// Does: chooses a pivot, calls helper
//       partition function to split the elements
//       on either side of the pivot.
//       then, a recursive quicksort!
void quicksort(int ray[], int low, int high)
{
  if (low < high)
    {
      int p = partition(ray,low,high);
      quicksort(ray,low,p-1);
      quicksort(ray,p+1,high);
    }	
}

int partition(int ray[], int low, int high)
{
    int pivot = ray[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (ray[j] < pivot)
        {
            i++;
            int tmp = ray[i];
            ray[i] = ray[j];
            ray[j] = tmp;
        }

    }

    int tmp2 = ray[high];
    ray[high] = ray[i+1];
    ray[i + 1] = tmp2;

    return i+1;
}
