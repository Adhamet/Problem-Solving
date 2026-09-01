#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    // its either all positive values of Blacks, and get 
    // best prefix of As, or
    // we continue beyond the positive values of blacks one by one
    // and check if addition of extra As due to that does the trick

    int n, m;   std::cin >> n >> m;
    std::vector<i64> b(n), w(m);
    for (int i = 0; i < n; i++) std::cin >> b[i];
    for (int i = 0; i < m; i++) std::cin >> w[i];
    std::sort(b.rbegin(), b.rend());
    std::sort(w.rbegin(), w.rend());

    int i = 0;
    i64 bSum = 0;
    while (i < n && b[i] > 0) bSum += b[i++];

    i64 ans = bSum;

    int j = 0;
    i64 wSum = 0;
    while (j < m && j < i && w[j] > 0) wSum += w[j++];
    ans += wSum;

    while (i < n && j < m) {
        bSum += b[i++];
        wSum += w[j++];
        ans = std::max(ans, bSum + wSum);
    }

    return std::cout << ans, 0;
}
