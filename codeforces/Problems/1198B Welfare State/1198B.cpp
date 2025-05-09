#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 2e5 + 5;
struct Node {
    int mn; int lazy;
    Node() : mn(0), lazy(0) {}
} t[4 * MAXN];

void push(int v) {
    if (t[v].lazy == 0) return;
    int payout = t[v].lazy;
    if (t[v*2].mn < payout) t[v*2].mn = payout;
    if (t[v*2].lazy < payout) t[v*2].lazy = payout;
    if (t[v*2+1].mn < payout) t[v*2+1].mn = payout;
    if (t[v*2+1].lazy < payout) t[v*2+1].lazy = payout;
    t[v].lazy = 0;
}

void update(int v, int tl, int tr, int pos, int x) {
    if (tl == tr) t[v].mn = x;
	else {
		push(v);
		int tm = (tl + tr) >> 1;
		if (pos <= tm) update(v*2, tl, tm, pos, x);
		else update(v*2+1, tm+1, tr, pos, x);
		t[v].mn = min(t[v*2].mn, t[v*2+1].mn);
	}
}

void query(int v, int tl, int tr, vector<int>& ans) {
    if (tl == tr) ans[tl] = t[v].mn;
	else {
		push(v);
		int tm = (tl + tr) / 2;
		query(v*2, tl, tm, ans);
		query(v*2+1, tm+1, tr, ans);
	}
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        update(1, 1, n, i, a);
    }

    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int p, x; cin >> p >> x;
            update(1, 1, n, p, x);
        } else {
            int x; cin >> x;
            if (x > t[1].lazy) {
                t[1].lazy = x;
                if (t[1].mn < x) t[1].mn = x;
            }
        }
    }

    vector<int> ans(n + 1);
    query(1, 1, n, ans);
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    return 0;
}
