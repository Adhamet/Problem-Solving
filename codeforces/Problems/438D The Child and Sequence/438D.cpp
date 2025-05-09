#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 1e5 + 5;
struct Node {
    i64 sum, mx, lazy;
    Node() : sum(0), mx(0), lazy(-1) {}
    Node(i64 val) : sum(val), mx(val), lazy(-1) {}
};

vector<Node> t(4*MAXN);

void push(int v) {
    if (t[v].lazy != -1) {
		t[v*2].sum = t[v].lazy;
		t[v*2].mx = t[v].lazy;
		t[v*2].lazy = t[v].lazy;
		t[v*2+1].sum = t[v].lazy;
		t[v*2+1].mx = t[v].lazy;
		t[v*2+1].lazy = t[v].lazy;
        t[v].lazy = -1;
    }
}

void build(vector<i64>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = Node(a[tl]);
    } else {
        int tm = (tl + tr) >> 1;
        build(a, v << 1, tl, tm);
        build(a, v << 1 | 1, tm + 1, tr);
        t[v].sum = t[v << 1].sum + t[v << 1 | 1].sum;
        t[v].mx = max(t[v << 1].mx, t[v << 1 | 1].mx);
    }
}

void update(int v, int tl, int tr, int pos, i64 x) {
    if (tl == tr) {
        t[v] = Node(x);
    } else {
        int tm = (tl + tr) >> 1;
        push(v);
        if (pos <= tm) update(v << 1, tl, tm, pos, x);
        else update(v << 1 | 1, tm + 1, tr, pos, x);
        t[v].sum = t[v << 1].sum + t[v << 1 | 1].sum;
        t[v].mx = max(t[v << 1].mx, t[v << 1 | 1].mx);
    }
}

void queryMOD(int v, int tl, int tr, int l, int r, i64 x) {
    if (l > r || tr < l || tl > r || t[v].mx < x) return;
    if (tl == tr) {
        t[v].sum %= x;
        t[v].mx = t[v].sum;
        return;
    }
    int tm = (tl + tr) >> 1;
    push(v);
    queryMOD(v << 1, tl, tm, l, r, x);
    queryMOD(v << 1 | 1, tm + 1, tr, l, r, x);
    t[v].sum = t[v << 1].sum + t[v << 1 | 1].sum;
    t[v].mx = max(t[v << 1].mx, t[v << 1 | 1].mx);
}

i64 querySUM(int v, int tl, int tr, int l, int r) {
    if (l > r || tr < l || tl > r) return 0;
    if (l <= tl && tr <= r) return t[v].sum;
    int tm = (tl + tr) >> 1;
    push(v);
    return querySUM(v << 1, tl, tm, l, r) + querySUM(v << 1 | 1, tm + 1, tr, l, r);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    build(a, 1, 1, n);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            cout << querySUM(1, 1, n, l, r) << el;
        } else if (op == 2) {
            int l, r; i64 x;
            cin >> l >> r >> x;
            queryMOD(1, 1, n, l, r, x);
        } else if (op == 3) {
            int pos;
            i64 x;
            cin >> pos >> x;
            update(1, 1, n, pos, x);
        }
    }

    return 0;
}

