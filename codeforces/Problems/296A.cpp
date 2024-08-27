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
    
	int n;
    cin >> n;
    vector<int> v;

    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    int c=1,mx=1;
    sort(v.begin(),v.end());

    for(int i = 0; i < n; i++) 
    {
        if ( v[i] == v[i+1] ) {
            c++;
            if (mx < c)
                mx = c;
        }
        else c = 1;
    }

    if ( mx <= ( (n+1) / 2 ) )
        cout << "YES" << el;
    else cout << "NO" << el;

	return 0;
}
