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
// 	setIO("blist");

    int n,x;  cin >> n;
    
    int chest=0,bi=0,back=0;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        if (i % 3 == 0) back += x;
        else if (i % 3 == 1) chest += x;
        else bi += x;
    }
    int mx = max(chest, max(bi,back));
    if (mx == back) cout << "back";
    else if (mx == bi) cout << "biceps";
    else cout << "chest";
    
    return 0;
}
