#include <bits/stdc++.h>
using namespace std;
#define adhamet ios_base::sync_with_stdio(false); cin.tie(NULL);

void dfs(int node, int parent, vector<int>& cost, vector<vector<int>>& adj) {
	cost[node] = 0;
	for(int i = 0; i < (int)adj[node].size(); i++) {
		if(adj[node][i] == parent) continue;
		dfs(adj[node][i], node, cost, adj);
		if(cost[adj[node][i]] == 0) cost[node] = 1;
	}
}

int main() {
	adhamet;
	int n,t;	cin >> n >> t;
	vector<vector<int>> adj(n+1);
	vector<int> cost(n+1);
	for(int i = 0; i < n-1; i++) {
		int u,v;	cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int c;	cin >> c;
	dfs(c, -1, cost, adj);
	if(cost[c]) cout << "Ron";
	else cout << "Hermione";

	return 0;
}
