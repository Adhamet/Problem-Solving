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
    char x;
    string str = "codeforces";
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> x;
        for(int j = 0; j < str.size(); j++)
        {
            if(str[j] == x) { cout << "YES\n"; break; }
            else if (str.size()-1 == j) cout << "NO\n";
        }
    }
}

int main()
{
    adhamet
    
    solve();
    return 0;
}