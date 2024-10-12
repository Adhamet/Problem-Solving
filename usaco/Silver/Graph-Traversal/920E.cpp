#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 2e5 + 5;
/*const int oo = 1e9 + 20;*/
unordered_set<int> adjL[N];
set<int> unvis;
int sz[N], currComp = 0;

void dfs(int x) {
	sz[currComp] += 1;

	auto itr = unvis.begin();
	while (itr != unvis.end()) {
		if (adjL[x].count(*itr)) itr++;
		else {
			int last = *itr;
			
			unvis.erase(itr);
			dfs(last);
			itr = unvis.upper_bound(last);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u -= 1, v -= 1;

		adjL[u].insert(v);
		adjL[v].insert(u);
	}

	for (int i = 0; i < n; i++) unvis.insert(i);
	for (int i = 0; i < n; i++) {
		auto itr = unvis.find(i);
		if (itr != unvis.end()) {
			unvis.erase(itr);
			dfs(i);
			currComp += 1;
		}
	}

	cout << currComp << el;
	sort(sz, sz + currComp);
	for (int i = 0; i < currComp; i++) cout << sz[i] << " ";
	cout << el;
	return 0;
}
