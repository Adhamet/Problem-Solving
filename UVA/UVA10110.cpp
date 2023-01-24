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

void solve(unsigned int t)
{
    unsigned int x = sqrt(t);
    if (x*x == t) { cout << "yes\n"; }
    else cout << "no\n";
}

int main()
{
    adhamet 

    unsigned int T;
    while(cin >> T && T != 0)
        solve(T);
    return 0;
}