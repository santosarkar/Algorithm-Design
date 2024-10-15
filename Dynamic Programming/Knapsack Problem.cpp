#include <iostream>
#include <vector>
using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, vector<int> wt, vector<int> val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0)); // Create a 2D dp array

    // Fill the dp array
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W]; // Return maximum value
}

int main() {
    int W = 50; // Maximum weight
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int n = val.size();
    cout << "Maximum value: " << knapsack(W, wt, val, n) << endl;
    return 0;
}

