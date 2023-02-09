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
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) 
    {
        char ch = tolower(s[i]);
        if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' )
            continue;
        else cout << '.' << ch;
    }
}

int main()
{
    adhamet
    
    solve();
    return 0;
}