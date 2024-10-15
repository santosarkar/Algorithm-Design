
#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum profit by cutting a rod
int rodCutting(vector<int>& prices, int rodLength) {
    vector<int> dp(rodLength + 1, 0); // Create a dp array to store the maximum profit for each length

    // Fill the dp array
    for (int i = 1; i <= rodLength; i++) {
        int maxProfit = 0;
        for (int j = 1; j <= i; j++) {
            maxProfit = max(maxProfit, prices[j - 1] + dp[i - j]);
        }
        dp[i] = maxProfit;
    }

    return dp[rodLength]; // Return the maximum profit for the full rod length
}

int main() {
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20}; // Example prices for rod pieces of length 1, 2, 3, ..., 8
    int rodLength = 8; // Length of the rod
    int result = rodCutting(prices, rodLength);

    cout << "Maximum profit by cutting the rod of length " << rodLength << ": " << result << endl;

    return 0;
}
