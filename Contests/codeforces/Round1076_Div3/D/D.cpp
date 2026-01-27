#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<i64> a(n), b(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];
        for (int i = 0; i < n; i++) std::cin >> b[i];
        std::sort(a.begin(), a.end());

        std::vector<i64> pref(n);   pref[0] = b[0];
        for (int i = 1; i < n; i++) pref[i] = pref[i-1] + b[i];

        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && a[i] == a[i-1]) continue;
            int j = std::upper_bound(pref.begin(), pref.end(), n-i) - pref.begin();
            if (j >= 1) {
                ans = std::max(ans, a[i] * j);
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}
