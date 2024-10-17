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

const int MAXN = 2e5;
vector<int> adjL[MAXN], children(MAXN);
void dfs(int node) {
	children[node] = 1;
	for (auto child: adjL[node]) {
		dfs(child);
		children[node] += children[child];
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int child = 1; child < n; child++) {
		int par;
		cin >> par;
		adjL[--par].push_back(child);
	}
	
	dfs(0);
	for (int i = 0; i < n; i++) cout << children[i] - 1 << " ";
	return 0;
}
