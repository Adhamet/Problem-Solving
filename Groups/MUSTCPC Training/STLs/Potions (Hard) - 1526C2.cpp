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
 
void solve()
{
    int n,x;
    cin >> n;
    ll sum=0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    while(n--)
    {
        cin >> x;
        pq.push(x);
        sum+=x;
        while(sum<0) {
            sum-=pq.top();
            pq.pop();
        }
    }
    cout << pq.size();
}
 
int main()
{
    adhamet
 
    solve();
 
    return 0;
}