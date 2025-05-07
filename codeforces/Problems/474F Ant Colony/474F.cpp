#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 1e5+5;
struct Node {
    int cnt = 0, g;
};

Node t[4*MAXN];

Node combine(Node left, Node right) {
    Node res;
    res.g = __gcd(left.g, right.g);
    if (res.g == left.g) res.cnt += left.cnt;
    if (res.g == right.g) res.cnt += right.cnt;
    return res;
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) t[v].g = a[tl], t[v].cnt = 1;
    else {
        int tm = (tl + tr) >> 1;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

Node query(int v, int tl, int tr, int l, int r) {
    if (l > r || tr < l || tl > r) return {0, 0};
    if (tl >= l && tr <= r) return t[v];
    int tm = (tl + tr) >> 1;
    return combine(query(v*2, tl, tm, l, r),
            query(v*2+1, tm+1, tr, l, r));
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    build(a, 1, 0, n - 1);

    int m; cin >> m;
    while (m--) {
        int l, r; cin >> l >> r;
        Node res = query(1, 0, n - 1, l - 1, r - 1);
        cout << (r - l + 1 - res.cnt) << el;
    }

    return 0;
}

