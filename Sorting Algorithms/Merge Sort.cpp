#include <iostream>
#include <vector>
using namespace std;

// Function to merge two subarrays
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid; // Size of the right subarray

    // Create temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i]; // Copy the smaller element
            i++;
        } else {
            arr[k] = R[j]; // Copy the smaller element
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the mid point

        mergeSort(arr, left, mid); // Sort first half
        mergeSort(arr, mid + 1, right); // Sort second half

        merge(arr, left, mid, right); // Merge the sorted halves
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

    mergeSort(arr, 0, arr.size() - 1); // Call Merge Sort

    cout << "Sorted array: ";
    printArray(arr); // Print the sorted array

    return 0; // Indicate that the program ended successfully
}

