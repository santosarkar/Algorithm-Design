#include <iostream>
#include <vector>
using namespace std;

// Function to perform Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size(); // Get the size of the array

    // Traverse through the entire array
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the first element is the minimum
        // Find the minimum element in unsorted array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update minimum index if found
            }
        }
        swap(arr[i], arr[minIndex]); // Swap the found minimum element with the first element
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
    vector<int> arr = {64, 25, 12, 22, 11}; // Example array

    cout << "Original array: ";
    printArray(arr); // Print the original array

    selectionSort(arr); // Call Selection Sort

    cout << "Sorted array: ";
    printArray(arr); // Print the sorted array

    return 0; // Indicate that the program ended successfully
}

