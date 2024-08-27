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
 
const int N = 2010;
vector<vector<int>> adjL(N);
bool vis[N];
int maxLevel;

void dfs(int node, int level) {
    maxLevel = max(maxLevel,level);
    for(auto child: adjL[node]) if (!vis[child]) {
        vis[child]=1;
        dfs(child,level+1);
    }
}
int main()
{
    adhamet;

    int n;
    cin >> n;

    vector<int> lds;
    for(int i = 1; i <= n; i++) {
        int lead;
        cin >> lead;
        if (lead == -1) lds.push_back(i);
        else adjL[lead].push_back(i);
    }    

    for(int lead: lds) dfs(lead,1);
    
    cout << maxLevel << el;

    return 0;
}
