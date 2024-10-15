#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]); // Swap the elements
        }
    }
    swap(arr[i + 1], arr[high]); // Place the pivot in the correct position
    return (i + 1); // Return the partitioning index
}

// Function to perform Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partition the array

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " "; // Print each element
    }
    cout << endl; // Print a newline
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5}; // Example array

    cout << "Original array: ";
    printArray(arr); // Print the original array

    quickSort(arr, 0, arr.size() - 1); // Call Quick Sort

    cout << "Sorted array: ";
    printArray(arr); // Print the sorted array

    return 0; // Indicate that the program ended successfully
}

