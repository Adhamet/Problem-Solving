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
		int p;
		string s;
		cin >> s >> p;

		int price = 0;
		map<int, int> freq;
		for (int i = 0; i < s.size(); i++) {
			price += (s[i] - 'a' + 1);
			freq[s[i] - 'a'] += 1;
		}

		if (price <= p) {
			cout << s << el;
		} else {
			for (int i = 25; i >= 0; i--) {
				if (price <= p) break;

				while (freq[i]) {
					price -= (i + 1), freq[i] -= 1;
					if (price <= p) break;
				}
			}

			for (int i = 0; i < s.size(); i++) {
				if (freq[s[i] - 'a']) {
					cout << s[i];
					freq[s[i] - 'a'] -= 1;
				}
			}

			cout << el;
		}
	}
	
	return 0;
}
