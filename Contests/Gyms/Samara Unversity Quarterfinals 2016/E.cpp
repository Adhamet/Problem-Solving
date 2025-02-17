#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, winner = 0;
    cin >> n;

    vector<array<int, 2>> a(n);
    for (int i = 0, l, r; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
        winner = max(winner, a[i][0]);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (winner >= a[i][0] && winner <= a[i][1]) {
            ans += 1;
        }
    }

    cout << ans << el;
    return 0;
}