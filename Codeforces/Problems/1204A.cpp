#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define ull unsigned long long
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define el '\n'

int main() 
{
/* #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
#endif */
    adhamet
    
    int cnt = 0;
	string s;
    cin >> s;

    if (s.size() % 2 == 0) cnt = s.size() / 2;
    else
    {
        bool one = false;
        for(int i = 1; i < s.size(); i++) if (s[i] == '1')
            one = true;
        
        if (one) cnt = s.size()/2 + 1;
        else cnt = s.size()/2;
    }
    cout << cnt << el;

	return 0;
}
