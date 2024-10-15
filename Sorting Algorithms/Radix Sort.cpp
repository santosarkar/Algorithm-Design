#include <iostream>
#include <vector>
using namespace std;

// Function to get the maximum value in the array
int getMax(const vector<int>& arr) {
    int maxVal = arr[0]; // Assume the first element is the maximum
    for (int num : arr) {
        if (num > maxVal) {
            maxVal = num; // Update the maximum if a larger value is found
        }
    }
    return maxVal; // Return the maximum value
}

// Function to perform counting sort based on a specific digit
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size(); // Get the size of the array
    vector<int> output(n); // Output array
    int count[10] = {0}; // Initialize count array

    // Store count of occurrences of digits
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++; // Count the digit at the current exponent
    }

    // Change count[i] so that count[i] now contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1]; // Accumulate counts
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; // Place the element in output[]
        count[(arr[i] / exp) % 10]--; // Decrease count
    }

    // Copy the output array back to arr[], so that arr[] now contains sorted numbers according to the current digit
    for (int i = 0; i < n; i++) {
        arr[i] = output[i]; // Copy sorted elements back to the original array
    }
}

// Function to perform Radix Sort
void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr); // Get the maximum value

    // Do counting sort for every digit
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp); // Sort based on the current digit
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
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66}; // Example array

    cout << "Original array: ";
    printArray(arr); // Print the original array

    radixSort(arr); // Call Radix Sort

    cout << "Sorted array: ";
    printArray(arr); // Print the sorted array

    return 0; // Indicate that the program ended successfully
}

