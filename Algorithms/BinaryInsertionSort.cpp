/**
Binary Insertion Sort algorithm is an enhanced version of the insertion sort 
algorithm. Instead of using linear search to find the correct location to 
insert the current element, binary insertion sort uses binary search, which 
reduces the number of comparisons in the average case. However, the overall 
time complexity remains O(n^2) due to the shifting of elements.

Time Complexity:

Worst Case: O(n^2)
Best Case: O(n log n)
Average Case: O(n^2)

*/

#include <vector>
#include <cstdint>
#include <algorithm>
#include <iostream>


template <class T>
int64_t binary_search(std::vector<T> &arr, T val, int64_t low, int64_t high) {
    if (high <= low) {
        return (val > arr[low]) ? (low + 1) : low;
    }
    int64_t mid = low + (high - low) / 2;
    if (arr[mid] > val) {
        return binary_search(arr, val, low, mid - 1);
    } else if (arr[mid] < val) {
        return binary_search(arr, val, mid + 1, high);
    } else {
        return mid + 1;
    }
}


template <typename T>
void insertionSort_binsrch(std::vector<T> &arr) {
    int64_t n = arr.size();
    for (int64_t i = 1; i < n; i++) {
        T key = arr[i];
        int64_t j = i - 1;
        int64_t loc = sorting::binary_search(arr, key, 0, j);
        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}