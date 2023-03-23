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
 
bool vis[500005];
void solve()
{
    int queries,x;
    cin >> queries;
    priority_queue<intPair> pq;
    queue<intPair> q;

    int op, idx = 1;
    while(queries--) 
    {
        cin >> op;
        if(op == 1) 
        {
            cin >> x;
            q.push( {x,idx} );
            pq.push( {x,-idx++} );
        }
        else if(op == 2) 
        {
            while(vis[q.front().S])
                q.pop();
            vis[q.front().S] = 1;
            cout << q.front().S << " ";
        }
        else
        {
            while(vis[-pq.top().S])
                pq.pop();
            vis[-pq.top().S] = 1;
            cout << -pq.top().S << " ";
        }
    }
}
int main()
{
    adhamet
 
    solve();
 
    return 0;
}