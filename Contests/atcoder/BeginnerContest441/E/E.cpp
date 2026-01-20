#include <bits/stdc++.h>

using i64 = long long;

struct SegTree {
    std::vector<int> tree;
    int size;

    SegTree(int n) {
        size = n;
        tree.assign(4*n, 0);
    }

    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            tree[v] += val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(v*2, tl, tm, pos, val);
            else update(v*2+1, tm+1, tr, pos, val);
            tree[v] = tree[v*2] + tree[v*2+1];
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (tl == l && tr == r) return tree[v];
        int tm = (tl + tr) / 2;
        return query(v*2, tl, tm, l, std::min(r, tm))
             + query(v*2+1, tm+1, tr, std::max(l, tm+1), r);
    }
};


int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<int> pref(n+1, 0);
    for (int i = 0; i < n; i++) {
        int val = 0;
        if (s[i] == 'A') val = 1;
        else if (s[i] == 'B') val = -1;
        pref[i+1] = pref[i] + val;
    }

    int OFFSET = n, m = 2*n+2;
    SegTree st(m);

    i64 ans = 0;
    st.update(1, 0, m-1, 0 + OFFSET, 1);

    for (int i = 1; i <= n; i++) {
        int idx = pref[i] + OFFSET;
        if (idx > 0) ans += st.query(1, 0, m-1, 0, idx-1);
        st.update(1, 0, m-1, idx, 1);
    }

    return std::cout << ans, 0;
}
