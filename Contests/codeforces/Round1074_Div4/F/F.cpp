#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

struct SegTreeXOR {
    std::vector<i64> tree, a;

    SegTreeXOR(int n): tree(4*n + 5), a(n) {}

    void build(int v, int tl, int tr) {
        if (tl == tr) tree[v] = a[tl];
        else {
            int tm = (tl + tr) >> 1;
            build(v<<1, tl, tm);
            build(v<<1|1, tm+1, tr);
            tree[v] = tree[v<<1] ^ tree[v<<1|1];
        }
    }

    void update(int v, int tl, int tr, int pos, i64 val) {
        if (tl == tr) {
            tree[v] = val;
            a[pos] = val;
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm) update(v<<1, tl, tm, pos, val);
            else update(v<<1|1, tm+1, tr, pos, val);
            tree[v] = tree[v<<1] ^ tree[v<<1|1];
        }
    }

    int query(int v, int tl, int tr, int pos) {
        if (tl == tr) return 0;
        int tm = (tl + tr) >> 1;

        int add = 0;
        if (pos <= tm) {
            add = (tree[v<<1|1] > tree[v<<1]? tr-tm: 0);
            return add + query(v<<1, tl, tm, pos);
        } else {
            int add = 0;
            add = (tree[v<<1] >= tree[v<<1|1]? tm-tl+1: 0);
            return add + query(v<<1|1, tm+1, tr, pos);
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n,q;    std::cin >> n >> q;
        
        const int SZ = (1<<n);
        SegTreeXOR seg(SZ);
        for (int i = 0; i < SZ; ++i) {
            int x;  std::cin >> x;
            seg.a[i] = x;
        }

        seg.build(1, 0, SZ-1);

        for (int i = 0; i < q; ++i) {
            int idx;
            i64 val;
            std::cin >> idx >> val;

            i64 tmp = seg.a[idx-1];
            seg.update(1, 0, SZ-1, idx-1, val);
            std::cout << seg.query(1, 0, SZ-1, idx-1) << '\n';
            seg.update(1, 0, SZ-1, idx-1, tmp);
        }
    }

    return 0;
}

