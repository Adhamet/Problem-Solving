#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n, q;   std::cin >> n >> q;
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];
        for (int i = 0; i < n; i++) std::cin >> b[i];
        
        std::vector<int> suffMx(n); suffMx[n-1] = std::max(a[n-1],b[n-1]);
        for (int i = n-2; i >= 0; i--) {
            suffMx[i] = std::max({a[i], b[i], suffMx[i+1]});
        }

        std::vector<int> pref(n);   pref[0] = suffMx[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i-1] + suffMx[i];
        }

        while (q--) {
            int l, r;   std::cin >> l >> r;
            l--,r--;
            std::cout << pref[r] - (l==0? 0: pref[l-1]) << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
