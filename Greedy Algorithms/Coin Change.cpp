
#include <iostream>
#include <vector>
#include <climits> // Include for INT_MAX
using namespace std;

// Function to find the minimum number of coins needed to make a given amount
int coinChange(const vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX); // Create a dp array and initialize with a large value
    dp[0] = 0; // Base case: no coins are needed to make the amount 0

    // Iterate through each coin
    for (int coin : coins) {
        // Update dp array for each value from coin to amount
        for (int j = coin; j <= amount; j++) {
            if (dp[j - coin] != INT_MAX) { // If it's possible to make (j - coin)
                dp[j] = min(dp[j], dp[j - coin] + 1); // Update the dp[j] with minimum coins needed
            }
        }
    }

    // If dp[amount] is still INT_MAX, it means it's not possible to form that amount
    return (dp[amount] == INT_MAX) ? -1 : dp[amount]; // Return the result
}

int main() {
    // Example coin denominations
    vector<int> coins = {1, 2, 5}; // Coin denominations
    int amount = 11; // Target amount

    // Call the coinChange function and print the result
    int result = coinChange(coins, amount);
    if (result != -1) {
        cout << "Minimum number of coins needed: " << result << endl; // Print the result
    } else {
        cout << "Cannot make the target amount with the given coins." << endl; // Not possible case
    }

    return 0; // Indicate that the program ended successfully
}
