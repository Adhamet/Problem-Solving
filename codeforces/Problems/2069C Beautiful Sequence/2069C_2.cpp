#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'
const int mod = 998244353;
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;

        int tot = 0, ans = 0, ones = 0;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            if (x == 1) tot += 1, ones += 1;
            else if (x == 2) tot = (tot * 2) % mod;
            else ans = (ans + tot - ones + mod) % mod;
        }

        cout << ans << el;
    }

    return 0;
}