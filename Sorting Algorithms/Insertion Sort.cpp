#include <iostream>
#include <vector>
using namespace std;

// Function to perform Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size(); // Get the size of the array

    // Traverse through 1 to n
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Element to be positioned
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Shift element to the right
            j = j - 1; // Move to the previous element
        }
        arr[j + 1] = key; // Place the key in its correct position
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
    vector<int> arr = {12, 11, 13, 5, 6}; // Example array

    cout << "Original array: ";
    printArray(arr); // Print the original array

    insertionSort(arr); // Call Insertion Sort

    cout << "Sorted array: ";
    printArray(arr); // Print the sorted array

    return 0; // Indicate that the program ended successfully
}

