#include <bits/stdc++.h>

// -- Don't use with doubles -----------
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
// -------------------------------------
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

    int n;  std::cin >> n;
    std::vector<std::pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    std::sort(a.rbegin(), a.rend());

    int r = 1;
    std::vector<int> rank(n, 0);
    for (int i = 0; i < n; i++) {
        rank[a[i].second] = r;
        int k = 1;
        while (i+1 < n && a[i].first == a[i+1].first) {
            i++;
            k++;
            rank[a[i].second] = r;
        }
        r += k;
    }

    for (auto x: rank) std::cout << x << '\n';
    return 0;
}
