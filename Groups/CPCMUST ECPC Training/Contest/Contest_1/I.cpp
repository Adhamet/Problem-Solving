#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>

 
int main() 
{
    /*
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
    #endif
    */
    
    adhamet;
    
    int n,k;
    string s;
    cin >> n >> k >> s;

    if (k == 0)
        return cout << s, 0;

    if (s.size() == 1) 
        return cout << 0, 0;

    if (k >= 1 && s[0] != '1')
    {
        s[0] = '1';
        k--;
    }

    int i = 1;
    while (k > 0 && i < n)
    {
        if ( s[i] != '0' ) {
            k--;
            s[i] = '0';
        }
        i++;
    }

    cout << s;
 
	return 0;
}
