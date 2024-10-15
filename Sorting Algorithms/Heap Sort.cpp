#include <iostream>
#include <vector>
using namespace std;

// Function to heapify a subtree rooted with node i
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child index
    int right = 2 * i + 2; // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left; // Update largest
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right; // Update largest
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]); // Swap root with largest
        heapify(arr, n, largest); // Recursively heapify the affected subtree
    }
}

// Main function to perform Heap Sort
void heapSort(vector<int>& arr) {
    int n = arr.size(); // Get the size of the array

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i); // Heapify each node
    }

    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0); // Call heapify on the reduced heap
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
    vector<int> arr = {12, 11, 13, 5, 6, 7}; // Example array

    cout << "Original array: ";
    printArray(arr); // Print the original array

    heapSort(arr); // Call Heap Sort

    cout << "Sorted array: ";
    printArray(arr); // Print the sorted array

    return 0; // Indicate that the program ended successfully
}

