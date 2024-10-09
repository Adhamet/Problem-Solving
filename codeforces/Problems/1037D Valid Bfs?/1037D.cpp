#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int N = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	set<int> adjL[n + 1];
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adjL[u].insert(v);
		adjL[v].insert(u);
	}

	vector<int> a(n);
	for (auto &i: a) cin >> i;
	if (a[0] != 1) {
		cout << "NO" << el;
		return 0;
	}

	vector<bool> vis(n + 1, false);
	queue<int> q;
	q.push(1);
	vis[1] = true;

	int i = 1;
	while (q.size() && i < n) {
		int node = q.front();
		q.pop();

		while (adjL[node].size()) {
			if (i >= n || !adjL[node].count(a[i])) break;
			adjL[node].erase(a[i]);
			vis[a[i]] = true;

			q.push(a[i++]);
		}

		for (auto child: adjL[node]) if (!vis[child]) {
			cout << "NO" << el;
			return 0;
		}
	}

	cout << "YES" << el;
	return 0;
}
