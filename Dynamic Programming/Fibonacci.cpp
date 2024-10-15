#include <iostream>
using namespace std;

// Function to calculate Fibonacci using DP
int fibonacci(int n) {
    int dp[n + 1]; // Create an array to store Fibonacci numbers
    dp[0] = 0; // Base case: F(0) = 0
    dp[1] = 1; // Base case: F(1) = 1

    // Fill the dp array
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2]; // Current value is the sum of previous two
    }

    return dp[n]; // Return the nth Fibonacci number
}

int main() {
    int n = 10; // Example input
    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}

