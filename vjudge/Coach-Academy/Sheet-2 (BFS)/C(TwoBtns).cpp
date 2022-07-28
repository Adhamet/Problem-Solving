#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int N = 2e4+10, oo = 1e9;
vector<int> adj[N];
int dist[N];
void bfs(int src)
{
    for(int i = 0; i <= N; i++)
        dist[i] = oo;
    dist[src]=0;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        int child1 = node * 2;
        int child2 = node - 1;
        if ( child1 < N && dist[node] + 1 < dist[child1] )
        {
            dist[child1] = dist[node] + 1;
            q.push(child1);
        }
        if ( child2 > 0 && dist[node] + 1 < dist[child2] )
        {
            dist[child2] = dist[node] + 1;
            q.push(child2);
        }
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    bfs(n);
    cout << dist[m] << endl;
}