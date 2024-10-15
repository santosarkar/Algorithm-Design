
#include <iostream>
#include <vector>
using namespace std;

// Function to perform binary search
int binarySearch(const vector<int>& arr, int target) {
    int left = 0; // Starting index
    int right = arr.size() - 1; // Ending index

    // Continue searching while the left index is less than or equal to the right index
    while (left <= right) {
        int mid = left + (right - left) / 2; // Find the middle index

        // If the target is found at mid, return the index
        if (arr[mid] == target) {
            return mid;
        }
        // If the target is greater than mid, ignore the left half
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        // If the target is smaller than mid, ignore the right half
        else {
            right = mid - 1;
        }
    }

    // Target was not found
    return -1;
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40}; // Sorted array
    int target;

    cout << "Enter the number to search: ";
    cin >> target; // Take input from the user

    int result = binarySearch(arr, target); // Call the binary search function

    if (result != -1) {
        cout << "Element found at index " << result << endl; // Print the index if found
    } else {
        cout << "Element not found in the array." << endl; // Print if not found
    }

    return 0; // Indicate that the program ended successfully
}
