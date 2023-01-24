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
    string s1,s2;
    cin >> s1 >> s2;

    if( s1.size() != s2.size() )
        cout << max(s1.size(), s2.size()) << endl;
    else if ( s1 == s2 ) 
        cout << -1 << endl;
    else cout << s1.size() << endl;
}

int main()
{
    adhamet

    solve();
    return 0;
}