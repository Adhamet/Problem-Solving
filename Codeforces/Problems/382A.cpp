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
    
	string s, r, l, rw;
    cin >> s >> rw;
    int p = s.find('|');
    l = s.substr(0, p);
    r = s.substr(p + 1);
    for (auto c : rw)
        if (l.size() <= r.size()) l += c;
        else r += c;
    cout << (l.size() == r.size() ? l + '|' + r : "Impossible") << endl;

	return 0;
}
