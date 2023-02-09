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
    int n, a[5000], b[5000], rated = 0;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        if(a[i] != b[i]) rated = 1;
    }

    if(rated == 1) { cout << "rated"; return; }

    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++) if(a[i] < a[j])
                rated = -1;
    
    if(rated == -1) cout << "unrated";
    else cout << "maybe";
}

int main()
{
    adhamet;
 
    solve();
    return 0;
}