#include <iostream>
#include <vector>
using namespace std;

// Function to perform Counting Sort
void countingSort(vector<int>& arr) {
    int maxElement = *max_element(arr.begin(), arr.end()); // Find the maximum element
    vector<int> count(maxElement + 1, 0); // Create a count array initialized to 0

    // Count occurrences of each element
    for (int num : arr) {
        count[num]++; // Increment the count for this number
    }

    // Reconstruct the sorted array
    int index = 0; // Initialize index for the sorted array
    for (int i = 0; i <= maxElement; i++) {
        while (count[i] > 0) {
            arr[index++] = i; // Place the number in the sorted array
            count[i]--; // Decrease the count
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
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1}; // Example array

    cout << "Original array: ";
    printArray(arr); // Print the original array

    countingSort(arr); // Call Counting Sort

    cout << "Sorted array: ";
    printArray(arr); // Print the sorted array

    return 0; // Indicate that the program ended successfully
}

