#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, S;
    cin >> n >> S;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int l = 0, r = n, mx = 0;
    while (l <= r) {
        int m = (l + r) >> 1, cost = 0;
        for (int i = 0; i < n; ++i) b[i] = a[i] + (i + 1) * m;
        sort(b.begin(), b.end());
        for (int i = 0; i < m && i < n; ++i) cost += b[i];

        if (cost <= S) mx = m, l = m + 1;
        else r = m - 1;
    }

    if (mx == 0) return cout << "0 0", 0;

    for (int i = 0; i < n; ++i) b[i] = a[i] + (i + 1) * mx;
    sort(b.begin(), b.end());
    int total = 0;
    for (int i = 0; i < mx; ++i) total += b[i];
    return cout << mx << ' ' << total, 0;
}
