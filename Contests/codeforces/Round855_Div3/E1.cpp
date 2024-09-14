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
		int n, k;
		cin >> n >> k;

		string s, t;
		cin >> s >> t;

		if (s == t) {
			cout << "YES" << el;
			continue;
		} else if (n <= k) {
			cout << "NO" << el;
			continue;
		}
		
		map<int, int> fqS, fqT;
		for (int i = 0; i < n; i++) fqS[s[i] - 'a'] += 1, fqT[t[i] - 'a'] += 1;

		bool acc = true;
		for (int i = 0; i < 26; i++) if (fqS[i] != fqT[i]) {
			acc = false;
			break;
		}

		if (!acc) {
			cout << "NO" << el;
			continue;
		}

		acc = true;
		for (int i = 0; i < n; i++) {
			if (i + k >= n && i - k < 0 && s[i] != t[i]) {
				acc = false;
				break;
			}
		}
		cout << (acc ? "YES" : "NO") << el;
	}
}

