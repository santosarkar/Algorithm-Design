
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the minimum number of coins to make a given amount
int minCoins(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount + 1, INT_MAX); // Create a dp array to store minimum coins for each amount

    dp[0] = 0; // Base case: 0 coins are needed to make the amount 0

    // Fill the dp array
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    // If dp[amount] is still INT_MAX, it means we cannot make that amount
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5}; // Example coin denominations
    int amount = 11; // Target amount
    int result = minCoins(coins, amount);

    if (result == -1) {
        cout << "It is not possible to make the amount " << amount << " with the given coins." << endl;
    } else {
        cout << "Minimum coins required to make amount " << amount << ": " << result << endl;
    }

    return 0;
}
