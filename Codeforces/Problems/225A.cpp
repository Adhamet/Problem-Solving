#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
 
void solve()
{
    int n, x;
    cin >> n >> x;
    bool t=1;
    
    while(n--)
    {
        int a,b;
        cin >> a >> b;
        if( a==x || a==7-x || b==x || b==7-x ) t=0;
    }
    t? cout << "YES": cout << "NO";
}
 
int main() 
{
    /*
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
    #endif
    */
    
    adhamet;
    
    solve();
 
	return 0;
}