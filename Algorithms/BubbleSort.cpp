/**
Bubble sort algorithm is the bubble sorting algorithm. The most important reason
for calling the bubble is that the largest number is thrown at the end of this
algorithm. This is all about the logic. In each iteration, the largest number is
expired and when iterations are completed, the sorting takes place.

Time Complexity:

Worst Case: O(n^2)
Best Case: O(n)
Average Case: O(n^2)

*/

#include <iostream>
#include <vector>

using namespace std;

// Function to sort the vector using Bubble Sort from smallest to largest
void BubbleSort(vector<long> &v){
    int n = v.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            if(v[j] > v[j+1]){
                swap(v[j], v[j+1]);
            }
        }
    }
}

// Function to sort the vector using Bubble Sort from largest to smallest
void BubbleSortReverse(vector<long> &v){
    int n = v.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            if(v[j] < v[j+1]){
                swap(v[j], v[j+1]);
            }
        }
    }
}