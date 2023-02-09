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
    int n,m;
    char x;
    cin >> n >> m;
    map<char,int> colours;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> x;
            colours[x]++;
        }
    
    if( colours['Y'] == 0 && colours['C'] == 0 && colours['M'] == 0) cout << "#Black&White";
    else cout << "#Color";
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