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
const int N = 1005/*, oo = 1e9+7, mod = 1e9+7*/;

vector<vi> adjL(N);
vi vis(N);
int closed[N], cnt;
void dfs(int node) {
	if(vis[node]) {
		return;
	}
	
	vis[node] = true;
	for(auto child: adjL[node]) {
		dfs(child);
	}
}

int main()	{
	freopen("moocast.in","r",stdin);
	freopen("moocast.out","w",stdout);
	adhamet;

	int n;	cin >> n;
	vi x(n),y(n);	
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	ll l = 0, r = 1e10;
	while (l + 1 < r) {
		int mid = l + (r - l) / 2;
		
		for (int i = 0; i < n; i++) {
			adjL[i].clear();
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ll a = abs( (x[i]-x[j]) );
				ll b = abs( (y[i]-y[j]) );
				if(a*a + b*b <= mid) {
					adjL[i].push_back(j);
					adjL[j].push_back(i);
				}
			}
		}

		cnt = 0;
		vis.assign(n,false);
		for(int i = 0; i < n; i++) {
			if (!vis[i]) {
				cnt++;
				dfs(i);
			}
		}

		if (cnt == 1) r = mid;
		else l = mid;
	}
	cout << r << el;
	return 0;
}
