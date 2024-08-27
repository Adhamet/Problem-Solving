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

int main()
{
    adhamet
    
    ll n, s1=0, s2=0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        ll q;
        cin >> q;
        s1 |= q;
    }
    for (int i = 0; i < n; i++)
    {
        ll q;
        cin >> q;
        s2 |= q;
    }

    cout << s1 + s2;
    return 0;
}
