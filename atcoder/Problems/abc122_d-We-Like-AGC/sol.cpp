#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

constexpr int MXN = 102, MOD = 1e9+7;

// A = 0, C = 1, G = 2, T = 3, dummy = 4
inline i64 addm(i64 a, i64 b) { a += b; if (a >= MOD) a -= MOD; return a; }

int n;
i64 mem[MXN][5][5][5];

i64 go(int idx, int c1, int c2, int c3) {
    if (idx == n) return 1;

    i64 &ret = mem[idx][c1][c2][c3];
    if (~ret) return ret;
    ret = 0;

    for (int c4 = 0; c4 < 4; c4++) {
        if (c2 == 0 && c3 == 2 && c4 == 1) continue; // AGC
        if (c2 == 0 && c3 == 1 && c4 == 2) continue; // ACG
        if (c2 == 2 && c3 == 0 && c4 == 1) continue; // GAC
        if (c1 == 0 && c3 == 2 && c4 == 1) continue; // A*GC
        if (c1 == 0 && c2 == 2 && c4 == 1) continue; // AG*C
        ret = addm(ret, go(idx + 1, c2, c3, c4));
    }

    return ret;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    std::cin >> n;
    memset(mem, -1, sizeof(mem));
    std::cout << go(0, 4, 4, 4) << '\n';
    return 0;
}
