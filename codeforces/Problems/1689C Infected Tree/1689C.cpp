#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int MAXN = 3e5+5;
int32_t childrenCnt[MAXN], memo[MAXN];
vector<vector<int32_t>> g(MAXN);

int32_t solve(int32_t node, int32_t par) {
	int32_t &ret = memo[node];
	if (~ret) return ret;
	ret = 0;

	int32_t a = 0, b = 0, ans;
	for (auto& child: g[node]) if (child != par) {
		if (a) b = child;
		else a = child;
	}

	if (!a && !b) return ret;
	if (a && !b) return ret = childrenCnt[a] - 1;
	if (!b && a) return ret = childrenCnt[b] - 1;
	if (a && b) {
		ret = max(ret, childrenCnt[a] - 1 + solve(b, node));
		ret = max(ret, childrenCnt[b] - 1 + solve(a, node));
	}

	return ret;
}

void findSubtreeSZ(int32_t node, int32_t par) {
	childrenCnt[node] = 1;
	for (auto& child: g[node]) if (child != par) {
		findSubtreeSZ(child, node);
		childrenCnt[node] += childrenCnt[child];
	}
}

int32_t main() {
	int32_t tc;
	scanf("%d", &tc);

	while (tc--) {
		int32_t n;
		scanf("%d", &n);

		memset(childrenCnt, 0, sizeof childrenCnt);
		memset(memo, -1, sizeof memo);
		for (int i = 0; i < n; ++i) g[i].clear();
		
		for (int i = 0, u, v; i < n - 1; ++i) {
			scanf("%d %d", &u, &v);
			g[--u].push_back(--v);
			g[v].push_back(u);
		}

		findSubtreeSZ(0, -1);
		printf("%d\n", solve(0, -1));
	}

	return 0;
}
