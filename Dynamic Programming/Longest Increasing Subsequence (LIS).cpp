
#include <iostream>
#include <vector>
using namespace std;

// Function to find the length of LIS
int lis(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1); // Each element is at least a subsequence of length 1

    // Fill the dp array
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    // Find maximum value in dp array
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > maxLength) {
            maxLength = dp[i];
        }
    }

    return maxLength;
}

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    cout << "Length of LIS: " << lis(arr) << endl;
    return 0;
}
