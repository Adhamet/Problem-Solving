#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>

 
int main() 
{
    /*
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
    #endif
    */
    
    adhamet;
    
    int n,min=1e9;
    int a,p;
    ll tm=0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> p;
        if (min > p) // 1
        {
            min = p;
        }
        tm += (min * a);
    }

    cout << tm;
 
	return 0;
}
