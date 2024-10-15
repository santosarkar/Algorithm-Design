#include <iostream>
#include <vector>
using namespace std;

// Function to perform linear search
int linearSearch(const vector<int>& arr, int target) {
    // Iterate through each element in the array
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) { // Check if the current element is the target
            return i; // Return the index if found
        }
    }
    return -1; // Target not found
}

int main() {
    vector<int> arr = {2, 4, 0, 1, 9}; // Example array
    int target;

    cout << "Enter the number to search: ";
    cin >> target; // Take input from the user

    int result = linearSearch(arr, target); // Call linear search function

    if (result != -1) {
        cout << "Element found at index " << result << endl; // Print the index if found
    } else {
        cout << "Element not found in the array." << endl; // Print if not found
    }

    return 0; // Indicate that the program ended successfully
}

