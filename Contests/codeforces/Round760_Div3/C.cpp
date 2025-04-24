#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int __gcd1 = a[1], __gcd2 = a[0];
        for (int i = 1; i < n; i += 2) __gcd1 = gcd(__gcd1, a[i]);
        for (int i = 2; i < n; i += 2) __gcd2 = gcd(__gcd2, a[i]);

        bool acc = true;
        for (int i = 0; i < n; i += 2) {
            if (a[i] % __gcd1 == 0) {
                acc = false;
                break;
            }
        }

        if (acc) {
            cout << __gcd1 << el;
            continue;
        }

        acc = true;
        for (int i = 1; i < n; i += 2) {
            if (a[i] % __gcd2 == 0) {
                acc = false;
                break;
            }
        }

        if (acc) cout << __gcd2 << el;
        else cout << 0 << el;
    }

    return 0;
}