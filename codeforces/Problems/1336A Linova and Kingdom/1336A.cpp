#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 2e5 + 5;

vector<int> graph[MAXN];
vector<bool> isLeaf;

void dfsLeaf(int u, int p) {
    bool leaf = true;
    for (int v: graph[u]) {
        if (v != p) {
            leaf = false;
            dfsLeaf(v, u);
        }
    }
    if (leaf) isLeaf[u] = true;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;

    isLeaf.resize(n, false);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
		u -= 1, v -= 1;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfsLeaf(0, -1);

	vector<int> depth(n, 0);
	vector<bool> vis(n, false);
	queue<int> q;
    q.push(0);
    vis[0] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : graph[u]) {
            if (!vis[v]) {
                vis[v] = true;
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
    }

    i64 ans = 0;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; ++i)
        if (isLeaf[i]) pq.push({depth[i], i});

	while (!pq.empty()) {
		auto [d, node] = pq.top(); pq.pop();

		if (k == 0 || node == 0) {
			if (!isLeaf[node]) ans += (node + 1);
			continue;
		}

		k -= 1;
	 	for (int v: graph[node]) {
 			if (depth[v] < depth[node]) {
				pq.push({depth[v], v});
			}
		}
    }

    return cout << ans, 0;
}

