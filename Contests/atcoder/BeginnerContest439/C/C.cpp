#include <bits/stdc++.h>
using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int N; std::cin >> N;

    std::vector<int> cnt(N + 1, 0);

    int limit = (int)std::sqrt(N) + 1;
    for (int x = 1; x < limit; x++) {
        int x2 = x * x;
        for (int y = x + 1; y < limit; y++) {
            int y2 = y * y;
            int sum = x2 + y2;
            if (sum > N) break;
            cnt[sum]++;
        }
    }

    std::vector<int> output;
    output.reserve(N);

    for (int i = 1; i <= N; i++) {
        if (cnt[i] == 1) output.push_back(i);
    }

    if (output.empty()) std::cout << 0 << '\n';
    else {
        std::cout << (int)output.size() << '\n';
        for (auto o: output) std::cout << o << ' ';
    }

    return 0;
}

