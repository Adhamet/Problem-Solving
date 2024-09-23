#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int N = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	
	while (t--) { 
		string s;
		cin >> s;

		map<char, int> freq;

		ll ans = 0;
		for (int i = 0; i < s.size(); i++) {
			freq[s[i]] += 1;
			if (freq.size() > 3) {
				freq.clear();
				ans += 1;
				freq[s[i]] += 1;
			}
		}
		cout << ans + 1 << el;
	}
	
	return 0;
}
