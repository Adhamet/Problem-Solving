#include <bits/stdc++.h>
 
using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define F first
#define S second
#define el '\n'

const int N = 1e5+5;
vector<vector<int>> adjL(N);
bool vis[N];

void dfs(int node) {
    vis[node]=1;
    for(auto child: adjL[node]) if (!vis[child])
        dfs(child);
}
int main()
{
    adhamet;

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        adjL[p].push_back(i);
        adjL[i].push_back(p);
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) if (!vis[i]) {
        dfs(i);
        cnt++;
    }

    cout << cnt << el;

    return 0;
}
