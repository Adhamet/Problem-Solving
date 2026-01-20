#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n, k;   std::cin >> n >> k;
    i64 x;      std::cin >> x;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::sort(a.begin(), a.end());

    i64 wc = 0;
    for (int i = 0; i < k; i++) wc += a[i]; // this is sake (k)
    if (wc < x) return std::cout << -1, 0;
    
    std::sort(a.rbegin(), a.rend());

    int idx = 0;
    i64 cur = 0;
    for (int i = n-k; i < n; i++) { // after water, take sake
        cur += a[i];
        idx = i;
        if (cur >= x) break;
    }
    if (cur < x) return std::cout << -1, 0;

    return std::cout << idx + 1, 0;
}
