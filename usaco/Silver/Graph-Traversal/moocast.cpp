#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
const int N = 205/*, oo = 1e9+7, mod = 1e9+7*/;

vector<vi> adjL(N);
vi vis(N);
int closed[N], cnt;
void dfs(int node) {
	if(vis[node]) return;
	vis[node] = true;
	cnt++;
	for(auto child: adjL[node])
		dfs(child);
}

int main()	{
	freopen("moocast.in","r",stdin);
	freopen("moocast.out","w",stdout);
	adhamet;

	int n;	cin >> n;
	map<pair<int,int>,int> idx;
	vi x(n),y(n),power(n);	
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> power[i];
		idx[make_pair(x[i],y[i])] = i;
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int dist= ( (x[i]-x[j]) * (x[i]-x[j])) + ((y[i]-y[j]) * (y[i]-y[j]));
			if(dist <= power[i]*power[i]) adjL[idx[make_pair(x[i],y[i])]].push_back(idx[make_pair(x[j],y[j])]);
		}
	}

	int maxCnt = 0;
	for(int i = 0; i < n; i++) {
		vis.assign(n,false);
		cnt = 0;
		dfs(i);
		maxCnt = max(maxCnt,cnt);
	}
	cout << maxCnt;
	return 0;
}

