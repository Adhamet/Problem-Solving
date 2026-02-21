#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    u64 m, a, b;    std::cin >> m >> a >> b;
    std::vector<u64> seq;
    seq.reserve(400);
    seq.push_back(3);
    seq.push_back(3);
    for (int i = 3; i <= 400; i++) {
        int bf = i-2, bfbf = i-3;
        seq.push_back(a*seq[bf] + b*seq[bfbf]);
    }

    debug(seq);

    return 0;
}
