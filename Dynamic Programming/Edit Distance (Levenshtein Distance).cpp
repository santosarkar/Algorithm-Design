
#include <iostream>
#include <vector>
using namespace std;

// Function to find the minimum edit distance
int editDistance(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Fill the dp array
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j; // If first string is empty
            } else if (j == 0) {
                dp[i][j] = i; // If second string is empty
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }
    }

    return dp[m][n]; // Return minimum edit distance
}

int main() {
    string str1 = "sunday";
    string str2 = "saturday";
    cout << "Edit Distance: " << editDistance(str1, str2) << endl;
    return 0;
}
