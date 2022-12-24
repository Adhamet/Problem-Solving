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
    string s1 = "abcdefghijklmnopqrstuvwxyz", s2 = "";
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) { s2 += s1[i%k]; }
    cout << s2;
}

int main()
{
    adhamet
    
    solve();
    return 0;
}