#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

struct SparseTableMin {
    std::vector<std::vector<int>> st;

    inline int log2_floor(int i) {
        return i? 31 - __builtin_clz(i): -1;
    };

    SparseTableMin(const std::vector<int>& a) {
        int n = (int)a.size();
        st.assign(log2_floor(n) + 1, std::vector<int>(n));
        for (int i = 0; i < n; i++)
            st[0][i] = a[i];
        int k = log2_floor(n);
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j+(1<<i) <= n; j++)
                st[i][j] = std::min(st[i-1][j], st[i-1][j+(1<<(i-1))]);
        }
    }

    inline int query(int l, int r) {
        if (l > r) return INT_MAX;
        int w = log2_floor(r - l + 1);
        return std::min(st[w][l], st[w][r-(1<<w)+1]);
    }
};


int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n, q;   std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    SparseTableMin spt(a);
    
    while (q--) {
        int l, r;   std::cin >> l >> r;
        r--;
        std::cout << spt.query(l, r) << '\n';
    }

    return 0;
}
