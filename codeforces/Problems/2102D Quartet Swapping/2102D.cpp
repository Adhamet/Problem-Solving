#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 2e5+5;
int n, t[4*MAXN];

void update(int pos, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) t[v] = 1;
	else {
		int tm = (tl + tr) >> 1;
		if (pos <= tm) update(pos, v*2, tl, tm);
		else update(pos, v*2+1, tm+1, tr);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int query(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tr < l || tl > r) return 0;
	if (tl >= l && tr <= r) return t[v];
	int tm = (tl + tr) >> 1;
	return query(l, r, v*2, tl, tm) + query(l, r, v*2+1, tm+1, tr);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		vector<int> a(n+1), o, e;
		for (int i = 1, x; i <= n; ++i) {
			cin >> a[i];
			if (i % 2 == 1) o.push_back(a[i]);
			else e.push_back(a[i]);
		}

		sort(o.begin(), o.end());
		sort(e.begin(), e.end());

		map<int, int> compress;
		for (int i = 0; i < o.size(); ++i)
			compress[o[i]] = i + 1;
		for (int i = 0; i < e.size(); ++i)
			compress[e[i]] = i + 1;

		int sumO = 0, sumE = 0;
		for (int i = 1; i <= n; i += 2) {
			int val = compress[a[i]];
			update(val);
			sumO += val - query(1, val);
		}

		for (int i = 0; i < 4 * n; ++i) t[i] = 0;

		for (int i = 2; i <= n; i += 2) {
			int val = compress[a[i]];
			update(val);
			sumE += val - query(1, val);
		}

		if (abs(sumO - sumE) % 2 == 1) {
			if (n % 2 == 1) swap(o[(int)o.size()-1], o[(int)o.size()-2]);
			else swap(e[(int)e.size()-1], e[(int)e.size()-2]);
		}

		for (int i = 1; i <= n; ++i) {
			if (i % 2 == 1) cout << o[i/2] << ' ';
			else cout << e[(i-1)/2] << ' ';
		}

		cout << el;
		for (int v = 0; v <= (4*n) + 50; ++v) t[v] = 0;
	}
}

