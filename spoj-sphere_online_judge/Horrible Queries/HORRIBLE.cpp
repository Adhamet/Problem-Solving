#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 1e5 + 5;
struct Node {
    i64 sum, lazy;
    Node() : sum(0), lazy(0) {}
};

Node t[4 * MAXN];

void build(int v, int tl, int tr) {
    t[v].sum = t[v].lazy = 0;
    if (tl == tr) return;
    int tm = (tl + tr) >> 1;
    build(v*2, tl, tm);
    build(v*2+1, tm+1, tr);
}

void push(int v, int tl, int tr) {
    if (t[v].lazy != 0) {
        int tm = (tl + tr) >> 1;
        t[v*2].sum += t[v].lazy * (tm - tl + 1);
        t[v*2].lazy += t[v].lazy;
        t[v*2+1].sum += t[v].lazy * (tr - tm);
        t[v*2+1].lazy += t[v].lazy;
        t[v].lazy = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, i64 val) {
    if (l > r) return;
    if (tl >= l  && tr <= r) {
        t[v].sum += val * (r - l + 1);
        t[v].lazy += val;
    } else {
        int tm = (tl + tr) >> 1;
        push(v, tl, tr);
        update(v*2, tl, tm, l, min(r, tm), val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, val);
        t[v].sum = t[v*2].sum + t[v*2+1].sum;
    }
}

i64 query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l <= tl && tr <= r) return t[v].sum;
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    return query(v*2, tl, tm, l, min(r, tm)) +
		query(v*2+1, tm+1, tr, max(l, tm+1), r);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        build(1, 1, n);
        while (c--) {
            int op, p, q;
            i64 v;
            cin >> op;
            if (op == 0) {
                cin >> p >> q >> v;
                update(1, 1, n, p, q, v);
            } else {
                cin >> p >> q;
                cout << query(1, 1, n, p, q) << el;
            }
        }
    }
    return 0;
}
