#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m;   std::cin >> n >> m;
    std::vector<std::array<i64, 3>> vec(m);
    for (int i = 0; i < m; i++) {
        std::cin >> vec[i][0] >> vec[i][1];
        vec[i][2] = i+1;
    }

    std::sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
        return a[1] < b[1]; 
    });

    i64 ans = 0;
    for (int i = 0; i < 2 * n; i++) ans += vec[i][1];
    std::cout << ans << '\n';

    std::sort(vec.begin(), vec.begin() + 2 * n, [](const auto &a, const auto &b) {
        return a[0] < b[0];
    });

    for (int i = 0; i < n; i++)
        std::cout << vec[i][2] << ' ' << vec[2*n-1-i][2] << '\n';
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t;  
    std::cin >> t;
    while (t--) solve();
    return 0;
}
