#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    std::vector<std::array<int,2>> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i][0] >> a[i][1];
    
    std::sort(a.begin(), a.end(), [](auto x, auto y) {
        if (x[0] != y[0]) return x[0] < y[0];
        return x[1] > y[1];
    });

    std::vector<int> dp;
    for (int i = 0; i < n; i++) {
        auto it = std::lower_bound(dp.begin(), dp.end(), a[i][1]);
        if (it == dp.end()) dp.push_back(a[i][1]);
        else *it = a[i][1];
    }


    debug(dp);
    return std::cout << (int)dp.size(), 0;
}
