#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define el '\n'
#define dbg(v)                                                                 \
 cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

const int N = 2e5;
vector<int> adjL[N];
map<int, vector<int>> validPaths;

void dfs(int node) {
    if(vis[node]) return;

    for(auto child: adjL[node]) {
        
        dfs(child);
    }
}

int main()
{
    adhamet;



    return 0;
}
