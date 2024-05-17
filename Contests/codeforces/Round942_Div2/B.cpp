#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
	adhamet
	int t;	cin >> t;
	while(t--) {
		int n;	cin >> n;
		string input;	cin >> input;
		int ups=0, downs=0;

		for(char ch: input) {
			if(ch == 'U') ups++;
			else downs++;
		}

		if(ups%2==1) cout << "YES\n";
		else cout << "NO\n";
	}
	
    return 0;
}