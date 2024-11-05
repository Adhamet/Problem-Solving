#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vector<int> activities(n);
    for (auto &i: activities) cin >> i;
    
    vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
    dp[0][0] = 1;
    if (activities[0] == 1 || activities[0] == 3) dp[0][1] = 0;
    if (activities[0] == 2 || activities[0] == 3) dp[0][2] = 0;

    for (int i = 1; i < n ; i++) {
        dp[i][0] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;
        if (activities[i] == 1 || activities[i] == 3) dp[i][1] = min({dp[i - 1][0], dp[i - 1][2]});
        if (activities[i] == 2 || activities[i] == 3) dp[i][2] = min({dp[i - 1][0], dp[i - 1][1]});
    }

    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    return 0;
}
