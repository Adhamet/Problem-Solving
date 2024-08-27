// CSES - 1621
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
	// setIO("censor");
    
    int n,x;  cin >> n;
    set<int> distinctVal;
    for(int i = 0; i < n; i++) {
        cin >> x;
        distinctVal.insert(x);
    }
    cout << distinctVal.size();

    return 0;
}
