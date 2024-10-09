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

	vector<bool> vis(n + 1, false);
	vector<bool> bad(n + 1, false);
	vector<int> adjL[n + 1];
	for (int i = 0; i < n - 1; i++) {
		int u, v, prob;
		cin >> u >> v >> prob;
		adjL[u].push_back(v);
		adjL[v].push_back(u);

		if (prob == 2) bad[u] = true, bad[v] = true;
	}

	queue<pair<int, int>> q;
    q.push({1, 0});
    vis[1] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        if (bad[node] == 1) {
            bad[parent] = 0;
            parent = node;
        }

        for (int child : adjL[node]) {
            if (!vis[child]) {
                vis[child] = true;
                q.push({child, parent});
            }
        }
    }

	vector<int> ans;
	for (int i = 1; i <= n; i++) if (bad[i]) {
		ans.push_back(i);
	}

	cout << ans.size() << el;
	for (auto a: ans) cout << a << " ";
	return 0;
}	
