#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define int i64
#define el '\n'

const int MAXN = 3e5 + 5;
const int MXD = 1e6 + 5;
vector<int> D(MXD);
struct Node {
    int sum = 0, cnt = 0;
};

Node t[4 * MAXN];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v].sum = a[tl];
        t[v].cnt = (a[tl] > 2);
    } else {
        int tm = (tl + tr) / 2;
        build(a, 2*v, tl, tm);
        build(a, 2*v+1, tm+1, tr);
        t[v].sum = t[2*v].sum + t[2*v+1].sum;
        t[v].cnt = t[2*v].cnt + t[2*v+1].cnt;
    }
}

void update(int v, int tl, int tr, int l, int r) {
    if (l > r || tr < l || tl > r || t[v].cnt == 0) return;
    if (tl == tr) {
        t[v].sum = D[t[v].sum];
        t[v].cnt = (t[v].sum > 2);
    } else {
        int tm = (tl + tr) / 2;
        update(2*v, tl, tm, l, r);
        update(2*v+1, tm+1, tr, l, r);
        t[v].sum = t[2*v].sum + t[2*v+1].sum;
        t[v].cnt = t[2*v].cnt + t[2*v+1].cnt;
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r || tr < l || tl > r) return 0;
    if (tl >= l && tr <= r) return t[v].sum;
    int tm = (tl + tr) / 2;
    return query(2*v, tl, tm, l, r) + query(2*v+1, tm+1, tr, l, r);
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    for (int i = 1; i < MXD; ++i)
        for (int j = i; j < MXD; j += i)
            ++D[j];

    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    build(a, 1, 0, n - 1);

    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) update(1, 0, n - 1, l - 1, r - 1);
        else cout << query(1, 0, n - 1, l - 1, r - 1) << el;
    }

    return 0;
}

