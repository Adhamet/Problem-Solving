#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define f first
#define s second
const int N = 2e4+5, oo = 1e9;
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
map<pair<int,int>, int> dist;
map<pair<int,int>, int> valid;

void bfs(int x, int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    if(valid[{x,y}])
        dist[{x,y}] = 0;
    while( !(q.empty()) )
    {
        pair<int,int> node = q.front();
        q.pop();
        for(int i = 0; i < 8; i++)
        {
            pair<int,int> newNode;
            newNode.f = node.f + dx[i], newNode.s = node.s + dy[i];
            if(valid[{newNode.f,newNode.s}] && dist[{newNode.f,newNode.s}] > dist[{node.f,node.s}] + 1)
            {
                dist[{newNode.f,newNode.s}] = dist[{node.f,node.s}] + 1;
                q.push(newNode);
            } 
        }
    }
}

int main()
{
    fff;
    int xI,yI,xF,yF;
    cin >> xI >> yI >> xF >> yF;
    dist[{xF,yF}] = oo;
    int k;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int r,a,b;
        cin >> r >> a >> b;
        for(int j = a; j <= b; j++)
        {
            valid[{r,j}] = 1;
            dist[{r,j}] = oo;
        }
    }
    bfs(xI,yI);
    
    if(dist[{xF,yF}] < 1e9)
        cout << dist[{xF,yF}] << endl;
    else cout << -1 << endl;
}