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
    ll int n,t;
    while(cin >> n >> t)
    {
        // number has one digit and is divisible by 10 (IMPOSSIBLE)
        if(n==1 && t==10) cout << "-1\n";
        // number has two digits or more and is divisble by 10 (10/10, 100/10, 1000/10 ...etc..)
        else if(n>=2 && t==10)
        {
            for(int i = 1; i < n; i++) cout << '1';
            cout << "0\n";
        }
        // any other case (3/3, 33/3, 5555/5, 999999/9, 666666666666/6, 777777777777777777/7 ...etc..)
        else
        {
            for(int i = 1; i <= n; i++) cout << t;
            el;
        }
    }
}
 
int main()
{
    adhamet;
 
    solve();
    return 0;
}