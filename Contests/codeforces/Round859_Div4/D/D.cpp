#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n, q; std::cin >> n >> q;
        std::vector<i64> a(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];

        std::vector<i64> pref(n);   pref[0] = a[0];
        for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + a[i];

        while (q--) {
            int l, r;
            i64 k;
            std::cin >> l >> r >> k;
            l--,r--;

            i64 cur = pref[n-1] + (k*(r-l+1)) - (pref[r] - (l>0? pref[l-1]: 0));
            if (cur & 1) std::cout << "YES\n";
            else std::cout << "NO\n";
        }
    }

    return 0;
}
