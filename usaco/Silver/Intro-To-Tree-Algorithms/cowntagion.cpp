#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define fst first
#define scd second
#define el '\n'
#define MOD 1000000007

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int MAXN = 1e5 + 5;
vector<int> adjL[MAXN];
int dfs(int s, int e) {
	int ans = 0;
	int cows = adjL[s].size();
	if (e == -1) cows += 1;

	int currCows = 1, days = 0;
	while (currCows < cows) days += 1, currCows *= 2;
	ans += days;

	for (auto u: adjL[s]) if (u != e) {
		ans += dfs(u, s) + 1;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}
	cout << dfs(0, -1) << el;
	return 0;
}
