#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define f first
#define s second
const int N = 1e5+5, oo = 1e9;
vector<int>adj[N];
bool vis[N];
int bad[N];
void dfs(int node, int parent)
{
    vis[node]=1;
    if(bad[node] == 1)
    {
        bad[parent]=0;
        parent = node;
    }
    for(auto child: adj[node])
    {
        if(!vis[child]){
            vis[child]=1;
            dfs(child,parent);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int a,b,road;
        cin >> a >> b >> road;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if(road==2)
        {
            bad[a]=1;
            bad[b]=1;
        }
    }
    dfs(1,0);
    vector<int> results;
    for(int i = 1; i <= n; i++)
        if(bad[i] == 1)
            results.push_back(i);
    cout << results.size() << endl;
    for(auto result: results)
        cout << result << " ";
}