#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define el '\n'
#define int long long
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        ll tot = 0;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            tot += a[i];
        }

        sort(a.rbegin(), a.rend());

        if (n == 1) {
            if (tot == k) {
                cout << 0 << el;
            } else {
                cout << k - a[0] << el;
            }
            continue;
        }

        if (tot < k) {
            cout << k - tot << el;
            continue;
        }

        ll cnt = 0;
        tot = 0;
        for (int i = 0; i < n; i++) {
            if (tot + a[i] == k) {
                cnt = 0;
                break;
            }
            if (tot + a[i] > k) {
                cnt = k - tot;
                break;
            }
            tot += a[i];
        }

        cout << cnt << el;
    }

    return 0;
}
