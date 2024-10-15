#include <iostream>
#include <vector>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size(); // Get the size of the array
    // Traverse through all elements in the array
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already sorted, so we reduce the range
        for (int j = 0; j < n - 1 - i; j++) {
            // If the current element is greater than the next, swap them
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // Swap the elements
            }
        }
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
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90}; // Example array

    cout << "Original array: ";
    printArray(arr); // Print the original array

    bubbleSort(arr); // Call Bubble Sort

    cout << "Sorted array: ";
    printArray(arr); // Print the sorted array

    return 0; // Indicate that the program ended successfully
}
