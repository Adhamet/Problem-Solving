#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int64_t n, c, d;
        cin >> n >> c >> d;

        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.rbegin(), a.rend());

        vector<int64_t> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];

        int64_t s = min(d, n);
        if (pref[s] >= c) {
            cout << "Infinity" << el;
            continue;
        } else if (a[0] * d < c) {
            cout << "Impossible" << el;
            continue;
        }

        auto can = [&](int64_t k) -> bool {
            int64_t cycDays = k + 1;
            int64_t cycles = d / cycDays;
            int64_t remDays = d % cycDays;
            int64_t cycSum = 0;
            int64_t take = min(k + 1, n);
            cycSum = pref[take];
            cycSum *= cycles;
            int64_t remSum = pref[min(remDays, n)];
            return cycSum + remSum >= c;
        };

        int64_t l = 0, r = 2e5 + 5, ans = 0;
        while (l <= r) {
            int64_t mid = (l + r) >> 1;
            if (can(mid)) ans = mid, l = mid + 1;
            else r = mid - 1;
        }

        cout << ans << el;
    }

    return 0;
}
