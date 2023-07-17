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
    
    ll n;
    bool k = true;
    string s;
    cin >> s >> n;

    string ans = s;
    while (n--) {
        string t;
        cin >> t;
        if (t.find(s) == 0)
        {
            if (k || t < ans)
                ans = t;
            k = false;
        }
    }
    cout << ans;
    
    return 0;
}   
