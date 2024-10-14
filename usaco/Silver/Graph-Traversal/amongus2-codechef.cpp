#include <bits/stdc++.h>
using namespace std;

#define el '\n'
const int MAXN = 500005;
vector<pair<int, int>> adj[MAXN];
int color[MAXN], count0, count1;
bool visited[MAXN];

bool dfs(int node, int col) {
    color[node] = col;
    if (col == 0) count0++;
    else count1++;

    for (auto &[child, type] : adj[node]) {
        int expCol = (type == 1 ? 1 - col : col);
        if (color[child] == -1) {
            if (!dfs(child, expCol)) return false;
        } else if (color[child] != expCol) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;

        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
            color[i] = -1;
        }

        for (int i = 0; i < q; ++i) {
            int w, u, v;
            cin >> w >> u >> v;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

		int ans = 0;
        bool consistent = true;
        for (int i = 1; i <= n; ++i) if (color[i] == -1) {
			count0 = 0, count1 = 0;
			if (!dfs(i, 0)) {
				consistent = false;
				break;
			}

		 	ans += max(count0, count1);
        }

		cout << (consistent? ans: -1) << el;
    }

    return 0;
}

