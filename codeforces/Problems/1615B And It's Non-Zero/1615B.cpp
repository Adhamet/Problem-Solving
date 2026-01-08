#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
#define MSB(x) (1LL << (63 - __builtin_clzll(x)))
#define MSB_IDX(x) (63 - __builtin_clzll(x))
#define LSB(x) ((x) & -(x))
#define LSB_IDX(x) (__builtin_ctzll(x))
#define DROP_LSB(x) ((x) & ((x) - 1))
#define IS_POW2(x) ((x) && !((x) & ((x) - 1)))
#define CLZ(x) (__builtin_clzll(x))   // undefined if x == 0
#define CTZ(x) (__builtin_ctzll(x))   // undefined if x == 0

void solve() {
    int l, r;   std::cin >> l >> r;

    int n = MSB_IDX(r);
    int mxOnes = 0;

    auto count_ones = [&](int x, int i) {
        int block = 1 << (i+1);
        int half  = 1 << i;
        return (x / block) * half + std::max(0, x % block - half + 1);
    };

    for (int i = 0; i <= n; i++) {
        int cnt = count_ones(r, i) - count_ones(l-1, i);
        mxOnes = std::max(mxOnes, cnt);
    }

    std::cout << (r - l + 1) - mxOnes << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
