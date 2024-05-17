#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

const int N = 2e5+5;
vector<int> adjL[N];
bool vis[N];
long long cnt = 0;

void dfs(int node, ll& nodes) {
	if(vis[node]) return;

	vis[node] = true;
	nodes++;
	for(int child: adjL[node])
		dfs(node,nodes);
}

int main()
{
	adhamet;
	int n,m;	cin >> n >> m;
	if(n==1) return printf("0"), 0;
	
	for(int i = 0; i < m; i++) {
		int u,v;	cin >> u >> v;
		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	for(int i = 1; i <= n; i++) if(!vis[i]) {
		ll ndCnt = 0;
		dfs(i, ndCnt);
		cnt += (ndCnt*(ndCnt-1)/2);
	}
		
	printf("%lld", cnt);

    return 0;
}