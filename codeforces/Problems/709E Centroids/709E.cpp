#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int MAXN = 4e5 + 10;
int n, cnt[MAXN], bad[MAXN], largest[MAXN];
vector<int> vis(MAXN, 0), ans(MAXN, 0);
vector<vector<int>> graph(MAXN, vector<int>());
void dfs_down(int node) {
    vis[node] = true;
    bad[node] = -1, cnt[node] = 1;
    for (auto child : graph[node]) if (!vis[child]) {
		dfs_down(child);
		cnt[node] += cnt[child];
		largest[node] = max(largest[node], largest[child]);
		if (cnt[child] <= n / 2) largest[node] = max(largest[node], cnt[child]);
		else bad[node] = child;
    }

    if (bad[node] == -1 && n - cnt[node] <= n / 2) {
        ans[node] = true;
    } else if (bad[node] != -1) {
        int child = bad[node], bigboy = largest[child];
        if (cnt[child] - bigboy <= n / 2) ans[node] = true;
    }
}

void dfs_up(int node, int bigboy = 0) {
    vis[node] = true;
    if (!ans[node] && bad[node] == -1) {
        int rest = n - cnt[node];
        if (rest - bigboy <= n / 2) ans[node] = true;
    }

    multiset<int> st;
    for (int child : graph[node]) if (!vis[child]) {
        st.insert(largest[child]);
        if (cnt[child] <= n / 2) st.insert(cnt[child]);
    }
    st.insert(bigboy);
    if (n - cnt[node] <= n / 2) st.insert(n - cnt[node]);

    for (int child : graph[node]) if (!vis[child]) {
		st.erase(st.find(largest[child]));
		if (cnt[child] <= n / 2) st.erase(st.find(cnt[child]));

		int x = st.empty() ? 0 : *st.rbegin();
		dfs_up(child, x);

		st.insert(largest[child]);
		if (cnt[child] <= n / 2) st.insert(cnt[child]);
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        u -= 1, v -= 1;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs_down(0);
	for (int i = 0; i < n; ++i) vis[i] = false;
    dfs_up(0);

    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    return cout << el, 0;
}
