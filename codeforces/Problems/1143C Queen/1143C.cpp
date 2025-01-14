#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int MAXN = 1e5+5;
vector<int> del, respect(MAXN);
vector<vector<int>> graph(MAXN);
void dfs(int node, int parent) {
    bool childrenDisrespect = true;
    for (auto child : graph[node]) {
        if (child == parent) continue;
        dfs(child, node);
        if (respect[child] == 0) childrenDisrespect = false;
    }

    if (respect[node] == 1 && childrenDisrespect) del.push_back(node);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, root;
    cin >> n;

    vector<int> par(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> par[i] >> respect[i];
		if (par[i] == -1) root = i;
		else graph[par[i]].push_back(i);
    }

    dfs(root, -1);
    if (!del.empty()) {
        sort(del.begin(), del.end());
        for (auto x : del) cout << x << ' ';
    } else cout << -1;
    return 0;
}
