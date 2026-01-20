#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

struct SegTreeMin {
    std::vector<int> tree, a;

    SegTreeMin(int n): tree((4*n)+1) {};

    void build(int v, int tl, int tr) {
        if (tl == tr) tree[v] = a[tl];
        else {
            int tm = (tl + tr) >> 1;
            build(v<<1, tl, tm);
            build(v<<1|1, tm+1, tr);
            tree[v] = std::min(tree[v<<1], tree[v<<1|1]);
        }
    }

    void update(int v, int tl, int tr, int pos, int x) {
        if (tl == tr) tree[v] = x;
        else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm) update(v<<1, tl, tm, pos, x);
            else update(v<<1|1, tm+1, tr, pos, x);
            tree[v] = std::min(tree[v<<1], tree[v<<1|1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) return INT_MAX;
        if (tl >= l && tr <= r) return tree[v];
        int tm = (tl + tr) >> 1;
        int lft = query(v<<1, tl, tm, l, std::min(r, tm)); // go left
        int rht = query(v<<1|1, tm+1, tr, std::max(l, tm+1), r); // go right
        return std::min(lft, rht);
    }
};

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n, q;   std::cin >> n >> q;
        SegTreeMin st(n);   st.a.resize(n);
        for (int i = 0; i < n; i++) {
            std::cin >> st.a[i];
        }

        st.build(1, 0, n-1);

        while (q--) {
            int type;   std::cin >> type;
            if (type == 1) {
                int i, x;  std::cin >> i >> x;
                st.update(1, 0, n-1, i, x);
            } else {
                int l, r, ans = 0;   std::cin >> l >> r;
                l--,r--;

                while (l <= r) {
                    int md = (l + r) >> 1;
                    int curMn = st.query(1, 0, n-1, l, md);
                    if (curMn == mn) ans = md, r = md - 1;
                    break;
                }

                debug(mn, ans+1);
                if (ans+1 == mn) std::cout << 1 << '\n';
                else std::cout << 0 << '\n';
            }
        }
    }

    return 0;
}
