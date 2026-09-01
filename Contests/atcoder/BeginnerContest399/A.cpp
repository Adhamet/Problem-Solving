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
    std::string s, t;
    std::cin >> s >> t;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) cnt++;
    }

    return std::cout << cnt, 0;
}
