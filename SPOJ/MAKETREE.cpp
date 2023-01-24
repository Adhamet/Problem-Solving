//SPOJ
#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
 
int n, s, wishes, pos, a;
vector<vector<int> > adj;
bool vis[100074];
vector<int> result;
int parent[100074];
 
void dfs(int student) {
	vis[student] = true;
	for (int i = 0; i < (int) adj[student].size(); i++) {
		int child = adj[student][i];
		if (!vis[child])
			dfs(child);
	}
	result.push_back(student);
}
 
int main() {
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
    
    adhamet;
    
	scanf("%d%d", &n, &s);
 
	adj.resize(n + 1);
 
	for (int i = 1; i <= s; i++) {
		scanf("%d", &wishes);
		for (int j = 0; j < wishes; j++) {
			scanf("%d", &a);
			adj[i].push_back(a);
		}
	}
 
	for (int i = 1; i <= n; i++) {
		if (!vis[i])
			dfs(i);
	}
 
	pos = 0;
	for (int i = n - 1; i >= 0; i--) {
		int Student = result[i];
		parent[Student] = pos;
		pos = Student;
	}
 
	for (int i = 1; i <= n; i++) {
		printf("%d\n", parent[i]);
	}
 
	return 0;
}