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
    int n,temp;
    vector<int> v1,v2,v3;
    cin >> n;
    for(int i = 1; i<=n; i++)
    {
        cin >> temp;
        if( temp==1 ) { v1.push_back(i); }
        else if ( temp==2 ) { v2.push_back(i); }
        else { v3.push_back(i); }
    }
    int mn = min(min(v1.size(), v2.size()), v3.size());
    cout << mn << el;
    for(int i = 0; i < mn; i++)
        cout << v1[i] << " " << v2[i] << " " << v3[i] << endl;
}

int main()
{
    adhamet

    solve();
    return 0;
}