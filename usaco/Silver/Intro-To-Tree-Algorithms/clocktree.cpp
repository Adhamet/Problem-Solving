#include <bits/stdc++.h>
#include <ios>
using namespace std;

const int MAXN = 1e5 + 5;
int vals[MAXN], sum0, sum1, nodes0, nodes1;
vector<int> adjL[MAXN];

void dfs(int node, int par, int col) {
    if (col == 0) nodes0++, sum0 += vals[node];
    else nodes1++, sum1 += vals[node];

    for (auto child: adjL[node]) if (child != par) {
        dfs(child, node, 1 - col);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("clocktree.in", "r", stdin);
	  freopen("clocktree.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> vals[i];
	  for (int i = 1; i < n; i++) {
		  int u, v;
		  cin >> u >> v;
		  --u, --v;
		  adjL[u].push_back(v);
		  adjL[v].push_back(u);
	  }

    dfs(0, -1, 0);
    if ((sum0 % 12) == (sum1 % 12)) cout << n;
	  else if ((sum0 + 1) % 12 == (sum1 % 12)) cout << nodes1;
	  else if ((sum0 % 12) == ((sum1 + 1) % 12)) cout << nodes0;
	  else cout << 0;
}
