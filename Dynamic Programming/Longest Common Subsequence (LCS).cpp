#include <iostream>
#include <vector>
using namespace std;

// Function to find the length of LCS
int lcs(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // Create a 2D dp array

    // Fill the dp array
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1]; // If characters match
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Take max of previous values
            }
        }
    }

    return dp[m][n]; // Return length of LCS
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    cout << "Length of LCS: " << lcs(X, Y) << endl;
    return 0;
}

