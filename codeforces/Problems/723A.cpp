// Meeting New Friends
#include <bits/stdc++.h>
 
using namespace std;
#define adhamett ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define F first
#define S second
#define el '\n'

int main()
{
    adhamett
    
    vector<int> r(3);
    for (int i = 0; i < 3; i++) cin >> r[i];
    sort(r.begin(), r.end(), greater<int>());
    cout << ( r[0] - r[1] ) + ( r[1] - r[2] );

    return 0;
}