#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, max_x = 0;
    cin >> n;

    map<int, int> freq;
    vector<int> seq(n);

    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
        ++freq[seq[i]];
        if (seq[i] > max_x) max_x = seq[i];
    }

    vector<int> dp(max_x + 1, 0);
    dp[0] = 0;
    if (max_x >= 1) dp[1] = freq[1] * 1;

    for (int x = 2; x <= max_x; ++x) dp[x] = max(dp[x - 1], dp[x - 2] + freq[x] * x);
    return cout << dp[max_x], 0;
}
