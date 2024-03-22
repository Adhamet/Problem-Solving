#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

// void setIO(string name = "") {
// 	if (name.size()) {
// 		freopen((name+".in").c_str(), "r", stdin);
// 		freopen((name+".out").c_str(), "w", stdout);	
// 	}
// }

int main()
{
    adhamet;
    // setIO("blist");

    string s;	cin >> s;
    int ans = 0;
    while(s.size() != 1) {
    	ll tmp = 0;
    	for(auto ch: s) tmp += ch - '0';
    	ans++;
    	s = to_string(tmp);
    }
    cout << ans;
	
    return 0;
}