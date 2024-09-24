#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 4e5 + 10;
/*const int oo = 1e9 + 20;*/

int par[N], sz[N];

void init(int n) {
	for (int i = 1; i <= n; i++) par[i] = i, sz[i] = i;
}
int find(int u) {
	return (par[u] == u ? u: par[u] = find(par[u]));
}
bool check(int u, int v) {
	return find(u) == find(v);
}
void connect(int u, int v) {
	if (check(u, v)) return;

	int a = find(u), b = find(v);
	if (sz[a] < sz[b]) swap(a, b);

	par[b] = a;
	sz[a] += sz[b];
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;

		init(2 * n + 1);
		vector<int> freq(n + 1);

		bool flag = true;
		for (int i = 0; i < n; i++) {
			int u, v;
			cin >> u >> v;
			
			connect(u, v + n);
			connect(u + n, v);
			freq[u] += 1, freq[v] += 1;

			if (u == v || freq[u] > 2 || freq[v] > 2) flag = false;
		}

		for (int i = 1; i <= n; i++) if (check(i, i + n)) {
			flag = false;
		}

		cout << (flag ? "YES": "NO") << el;
	}
	
	return 0;
}
