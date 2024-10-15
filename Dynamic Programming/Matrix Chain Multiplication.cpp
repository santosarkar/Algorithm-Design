#include <iostream>
#include <limits.h>
using namespace std;

// Function to find the minimum cost of matrix multiplication
int matrixChainOrder(int p[], int n) {
    int dp[n][n]; // Create a 2D dp array

    // dp[i][i] = 0 because one matrix requires no multiplication
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;

    // Fill the dp array
    for (int L = 2; L < n; L++) { // L is chain length
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < dp[i][j])
                    dp[i][j] = q;
            }
        }
    }

    return dp[1][n - 1]; // Return minimum cost
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum cost: " << matrixChainOrder(arr, size) << endl;
    return 0;
}

