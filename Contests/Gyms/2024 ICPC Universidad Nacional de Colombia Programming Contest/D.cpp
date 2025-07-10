#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;	cin >> n >> m;
	vector<i64> mon(n, 0);
	for (int i = 0, u, v; i < m; i++){
		i64 w;	cin >> u >> v >> w;
		--u; --v;
		mon[u] += w, mon[v] -= w;
	}

	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int a, int b){ return mon[a] < mon[b]; });

	vector<i64> pref(n, 0);
	pref[0] = mon[ord[0]];
	for(int i = 1; i < n; i++)
		pref[i] = pref[i-1] + mon[ord[i]];

	vector<tuple<int,int,i64>> ans;
	for(int i = 0; i+1 < n; i++){
		int u = ord[i], v = ord[i+1];
		if(pref[i] < 0) ans.emplace_back(u, v, -pref[i]);
		else if(pref[i] > 0) ans.emplace_back(v, u, pref[i]);
	}

	cout << (int)ans.size() << el;
	for(auto &[x,y,z]: ans)
		cout << x+1 << ' ' << y+1 << ' ' << z << el;
	return 0;
}

