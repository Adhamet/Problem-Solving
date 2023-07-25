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
    
	int n,s;
    cin >> n >> s;
    vector<intPair> v(n);

    for(int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    v.push_back({0,0});
    sort(v.rbegin(),v.rend());
    int a = s, cnt = 0, dly = 0;
    for(int i = 0; i < n; i++)
    {
        dly += a - v[i].first;
        a = v[i].first;
        if ( v[i].second > dly )
            dly = v[i].second;
    }
    cout << dly;

	return 0;
}
