#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define ll long long
#define el '\n'

const ll MOD = 1e9 + 7;
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll l, r;
        cin >> n >> l >> r;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        ll mod = r + 1, f = 1;
        for (int bit = 0; bit < 64; bit++) {
            ll count1 = 0, count0 = 0;

            for (int i = 0; i < n; i++) {
                if (a[i] & (1LL << bit)) count1++;
                else count0++;
            }

            ll pairs = count1 * count0;
            if (pairs > 0) {
                ll contrib = (1LL << bit) % mod;
                for (ll i = 0; i < pairs; i++) {
                    f = (f * contrib) % mod;
                    if (f > r) break;
                }
            }

            if (f > r) break;
        }

        if (f >= l && f <= r) cout << "YES" << el;
        else cout << "NO" << el;
    }

    return 0;
}

