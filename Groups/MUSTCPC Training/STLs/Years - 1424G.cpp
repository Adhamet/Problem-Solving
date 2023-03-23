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
    int n;
    cin >> n;
    map<int,int> mp;
    while(n--)
    {
        int b,d;
        cin >> b >> d;
        mp[b]++; mp[d]--;
    }
    
    vector<intPair> v(mp.begin(),mp.end());
    for(int i = 1; i < v.size(); i++)
        v[i].second += v[i-1].second;
    
    intPair ans = {-1,-1};
    for(intPair p: v) {
        if(p.second > ans.second) {
            ans.first = p.first;
            ans.second = p.second;
        }
    }
    cout << ans.first << " " << ans.second;
}
 
int main()
{
    adhamet
 
    solve();
 
    return 0;
}