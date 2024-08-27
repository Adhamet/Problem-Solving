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

void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);	
	}
}

int main()
{
    adhamet;
    setIO("pails");

    long long x,y,m;	cin >> x >> y >> m;

    long long mx=0;
    for(int i = 0; x*i+y <= m; i++) { // 25
    	long long curr=0;
    	for(int j = 0; x*j+y*i<=m; j++) { // 17*3
    		curr = x*j+y*i;
    	}
    	mx = max(mx,curr);
    }
	cout << mx;

    return 0;
}