#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define el '\n'

bool can(int v, int n, int k)
{
    bool check = true;
    ll sum = 0;
    int i = 0;
    while ( true )
    {
        if ( v / pow(k,i) == 0 )
        {
            check = false;
            break;
        }
        sum += v / pow(k,i);
        if ( sum >= n )
            break;
        i++;
    }

    return check;
}

int main() 
{
/* #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
#endif */
    adhamet
    int n,k;
    cin >> n >> k;

    int l = 1, r = 1e9, ans;
    while ( l <= r )
    {
        int mid = l + (r - l)/2;

        if ( can(mid,n,k) ) ans = mid, r = mid - 1;
        else l = mid + 1;
    }

    cout << ans;
	return 0;
}
