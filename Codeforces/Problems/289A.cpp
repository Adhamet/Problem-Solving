#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define el '\n'
int main() 
{
/* #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
#endif */
    adhamet
    
	int n,k,cnt=0;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int u,v;
        cin >> u >> v;
        cnt += (v - u + 1);
    }

    ll c=0;
    if (cnt % k != 0)
        while(true)
        {
            c++;
            cnt++;
            if (cnt % k == 0) break;
        }
    cout << c << endl;

	return 0;
}
