#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define el '\n'

void solve()
{
    int l,r,a,min,max,diff;
    cin >> l >> r >> a;
    
    min = l < r ? l : r;
    max = l > r ? l : r;

    diff = max - min;

    if(diff == 0)
    {
        min += a/2;
        max += a/2;
    }
    else
    {
        if(a >= diff)
        {
            min += diff;
            a -= diff;
            min += a/2;
            max += a/2;
        }
        else { min += a; }
    }

    cout << 2*min << el;
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