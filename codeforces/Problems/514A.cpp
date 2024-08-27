#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
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
    
	string s;
    cin >> s;
    int i = 0;
    if (s[0] == '9') i = 1;
    for(i; i < s.size() ; i++) if ( s[i] > '4' ) 
            s[i] = ( 9 - (s[i] - '0') ) + '0';
    cout << s;

	return 0;
}
