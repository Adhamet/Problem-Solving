#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

struct SegTreeMax {
    std::vector<int> tree, a;

    SegTreeMax(int n): tree((4*n)+1) {};

    void build(int v, int tl, int tr) {
        if (tl == tr) tree[v] = a[tl];
        else {
            int tm = (tl + tr) >> 1;
            build(v<<1, tl, tm);
            build(v<<1|1, tm+1, tr);
            tree[v] = std::max(tree[v<<1], tree[v<<1|1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) return INT_MAX;
        if (tl >= l && tr <= r) return tree[v];
        int tm = (tl + tr) >> 1;
        int lft = query(v<<1, tl, tm, l, std::min(r, tm)); // go left
        int rht = query(v<<1|1, tm+1, tr, std::max(l, tm+1), r); // go right
        return std::max(lft, rht);
    }
};

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    const int INF = INT_MAX;

    int n;  std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) std::cin >> a[i];

    std::vector<int> dp(n+2, INF);
    std::vector<int> idx(n+2, INF);
    std::vector<int> par(n, -1);
    dp[0] = idx[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = std::upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if (dp[j-1] < a[i] && a[i] < dp[j])
            dp[j] = a[i], idx[j] = i, par[i] = idx[j-1];
    }

    // for (auto x: dp) debug(x);

    int node = 0;
    for (int i = 0; i <= n; i++) {
        if (dp[i+1] == INF) {
            node = idx[i];
            break;
        }
    }

    std::vector<int> ans;
    while (node != -INF) {
        ans.push_back(a[node]);
        node = par[node];
    }
    std::reverse(ans.begin(), ans.end());

    std::cout << (int)ans.size() << '\n';
    for (auto x: ans) std::cout << x << ' ';

    return 0;
}
