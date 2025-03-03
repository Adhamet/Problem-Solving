#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'
const int mod = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> dp(4, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (x == 2) dp[x] = add(dp[x], dp[x]);
            dp[x] = add(dp[x], dp[x - 1]);
        }

        cout << dp[3] << el;
    }
    
    return 0;
}