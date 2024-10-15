
#include <iostream>
#include <vector>
#include <algorithm> // For sort
using namespace std;

// Function to perform Bucket Sort
void bucketSort(vector<float>& arr) {
    int n = arr.size(); // Get the size of the array
    // Create buckets
    vector<vector<float>> buckets(n);

    // Distribute the elements into buckets
    for (float num : arr) {
        int bucketIndex = n * num; // Get the index for the bucket
        buckets[bucketIndex].push_back(num); // Add the number to the appropriate bucket
    }

    // Sort individual buckets and concatenate
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end()); // Sort the bucket
    }

    // Merge the buckets back into the original array
    arr.clear(); // Clear the original array
    for (const auto& bucket : buckets) {
        for (float num : bucket) {
            arr.push_back(num); // Add sorted elements back to the original array
        }
    }
}

// Function to print the array
void printArray(const vector<float>& arr) {
    for (float num : arr) {
        cout << num << " "; // Print each element
    }
    cout << endl; // Print a newline
}

int main() {
    vector<float> arr = {0.42, 0.32, 0.23, 0.75, 0.12, 0.78, 0.62}; // Example array

    cout << "Original array: ";
    printArray(arr); // Print the original array

    bucketSort(arr); // Call Bucket Sort

    cout << "Sorted array: ";
    printArray(arr); // Print the sorted array

    return 0; // Indicate that the program ended successfully
}
