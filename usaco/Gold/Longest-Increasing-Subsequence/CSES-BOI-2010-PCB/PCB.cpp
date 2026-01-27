#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    // freopen("pcb.in", "r", stdin);
    // freopen("pcb.out", "w", stdout);
   
    int n;  std::cin >> n;
    std::vector<std::array<int,2>> conn(n);
    for (int i = 0; i < n; i++) std::cin >> conn[i][0] >> conn[i][1];
    std::sort(conn.begin(), conn.end(), [](auto x, auto y) {
        return x[0] < y[0];
    });


    std::vector<int> dp;
    for (int i = 0; i < n; i++) {
        auto it = std::upper_bound(dp.begin(), dp.end(), -conn[i][1]);
        if (it == dp.end()) dp.push_back(-conn[i][1]);
        else *it = -conn[i][1];
    }

    return std::cout << (int)dp.size(), 0;
}
