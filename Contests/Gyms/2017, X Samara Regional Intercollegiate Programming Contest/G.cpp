#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;	cin >> n;
	vector<string> name(n);
	vector<int> lvCnt(n, 0), whom(n);
	for(int i = 0; i < n; i++) cin >> name[i], whom[i] = i;

	int m;	cin >> m;
	for(int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		--u; --v;
		whom[u] = whom[v];
		lvCnt[u] = lvCnt[v] + 1;
	}

	for(int i = 0; i < lvCnt[0]; i++)
		cout << "I_love_";
	return cout << name[whom[0]], 0;
}

