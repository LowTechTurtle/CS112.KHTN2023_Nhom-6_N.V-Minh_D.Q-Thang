#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    cin >> n >> k;

    vector<vector<int>> grap(n + 1, vector<int>(k + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> grap[i][j];
        }
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -1e18));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        long long max_so_far = -1e18;
        for (int j = 1; j <= k; j++) {
            if (j >= i) {
                max_so_far = max(max_so_far, dp[i - 1][j - 1]);
                dp[i][j] = max_so_far + grap[i][j];
            }
        }
    }

    long long result = -1e18;
    for (int i = n; i <= k; i++) {
        result = max(result, dp[n][i]);
    }

    cout << result;
    return 0;
}
