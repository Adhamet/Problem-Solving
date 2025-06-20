#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define fst first
#define scd second
#define el '\n'

// vis[8], operations[8]
const int MAXN = 8;
i32 n;
vector<pair<int, bool>> res;
vector<pair<int,int>> d(MAXN);
void solve(int idx, bool flip, int cnt, vector<int> vis, vector<pair<int,bool>> op) {
	if (cnt == n) {
		res = op;
		return;
	}
	
	for (int i = 0; i < n; ++i) if (!vis[i]) {
		bool tk = false;
		if (flip == 0) {
			if (d[idx].scd == d[i].fst) {
				vis[i] = true;
				op.push_back({i+1, 0});
				solve(i, 0, cnt+1, vis, op);
				tk = true;
			} else if (d[idx].scd == d[i].scd) {
				vis[i] = true;
				op.push_back({i+1, 1});
				solve(i, 1, cnt+1, vis, op);
				tk = true;
			}
		}  else {
			if (d[idx].fst == d[i].fst) {
				vis[i] = true;
				op.push_back({i+1, 0});
				solve(i, 0, cnt+1, vis, op);
				tk = true;
			} else if (d[idx].fst == d[i].scd) {
				vis[i] = true;
				op.push_back({i+1, 1});
				solve(i, 1, cnt+1, vis, op);
				tk = true;
			}
		}

		if (tk) op.pop_back(), vis[i] = false;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> d[i].fst >> d[i].scd;

	vector<int> vis(MAXN);
	vector<pair<int, bool>> op(MAXN);
	for (int i = 0; i < n; ++i) {
		if (i > 0) vis[i-1] = false;
		vis[i] = true;
		op.clear();
		op.push_back({i+1, 0});
		solve(i, 0, 1, vis, op);
		if (!res.empty()) break;
		op.clear();
		op.push_back({i+1, 1});
		solve(i, 1, 1, vis, op);
		if (!res.empty()) break;
	}

	for (auto& [i, t]: res) cout << i << ' ' << (t? 'b': 'a') << el;
	return 0;
}
