#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i][0] >> a[i][1];
    sort(a.begin(), a.end());
    
    auto can = [&](int x) {
        for (int i = 0; i < n; ++i) {
            if (x >= a[i][0]) {
                x -= a[i][1];
            } else return false;

            if (x < 0) return false;
        }

        return true;
    };

    int l = 0, r = 1e9+5, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;

        if (can(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }

    cout << ans << el;
    return 0;
}