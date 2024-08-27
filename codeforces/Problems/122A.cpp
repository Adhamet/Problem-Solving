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
 
    int n = stoi(s);
 
    if (n % 4 == 0 or n % 7 == 0 or n % 47 == 0)
    {
        cout << "YES" << endl;
        return;
    }
 
    for(int i = 0; i < s.size(); i++)
    {
        if (s[i] == '4' or s[i] == '7')
            continue;
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
 
    cout << "YES" << endl;
}

int main()
{
    adhamet
    
    int t = 1;
    //t = 4;
    while(t--) {
        solve();
    }
    return 0;
}
