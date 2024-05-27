/**
Bead sort algorithm, also known as gravity sort, is a natural sorting algorithm
inspired by the natural phenomenon of beads falling under gravity. The algorithm 
works by representing each number as a column of beads and letting the beads fall 
under gravity to form sorted columns.

Time Complexity:

Worst Case: O(S)
Best Case: O(S)
Average Case: O(S)

S: Sum of the input numbers

Note: Bead sort is not a comparison-based sorting algorithm and is generally 
limited to positive integers. It is not practical for large numbers or 
negative numbers.

*/
#include <bits/stdc++.h>

#define BEAD(i, j) beads[i * max + j]
using namespace std;

// Function to perform bead sort on an array
void beadSort(int *a, int len) {
    // Find the maximum element
    int max = a[0];
    for (int i = 1; i < len; i++)
        if (a[i] > max)
            max = a[i];

    // allocating memory
    unsigned char *beads = new unsigned char[max * len];
    memset(beads, 0, static_cast<size_t>(max) * len);

    // mark the beads
    for (int i = 0; i < len; i++)
        for (int j = 0; j < a[i]; j++) BEAD(i, j) = 1;

    for (int j = 0; j < max; j++) {
        // count how many beads are on each post
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += BEAD(i, j);
            BEAD(i, j) = 0;
        }
        // Move beads down
        for (int i = len - sum; i < len; i++) BEAD(i, j) = 1;
    }
    // Put sorted values in array using beads
    for (int i = 0; i < len; i++) {
        int j;
        for (j = 0; j < max && BEAD(i, j); j++) {
        }
        a[i] = j;
    }
    delete[] beads;
}

// driver function to test the algorithm
int main() {
    int a[] = {5, 3, 1, 7, 4, 1, 1, 20};
    int len = sizeof(a) / sizeof(a[0]);

    beadSort(a, len);

    for (int i = 0; i < len; i++) printf("%d ", a[i]);

    return 0;
}