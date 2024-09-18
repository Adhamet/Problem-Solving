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
		int n;
		cin >> n;

		string s;
		cin >> s;

		bool acc = true;
		map<int, int> freq;
		for (int i = 0; i < n; i++) {
			if (freq[s[i]] == 0) {
				char tmp = s[i];
				freq[s[i]] += 1;
				while (i + 1 < n && s[i + 1] == tmp) freq[s[i]] += 1, i++;
			} else {
				acc = false;
				break;
			}
		}

		if (acc) cout << "YES" << el;
		else cout << "NO" << el;
	}
	
	return 0;
}
