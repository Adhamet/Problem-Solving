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
    std::vector<int> idx(n+1, -1);
    for (int i = 0; i < n; i++) {
        int x;  std::cin >> x;
        idx[x] = i + 1;
    }

    std::vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;  std::cin >> x;
        if (idx[x] != -1) {
            v.push_back(idx[x]);
        }
    }

    // debug(v);

    std::vector<int> dp;
    for (int i = 0; i < n; i++) {
        auto it = std::upper_bound(dp.begin(), dp.end(), v[i]);
        if (it == dp.end()) dp.push_back(v[i]);
        else *it = v[i];
    }

    return std::cout << (int)dp.size(), 0;
}

