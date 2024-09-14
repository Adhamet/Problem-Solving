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

		string s;
		cin >> s;

		map<int, int> freq;
		for (auto &c: s) freq[c] += 1;

		int ans = 0, more = 0;
		for (int i = 0; i < 26; i++) {
			char lower_ch = 'a' + i;
			char upper_ch = 'A' + i;

			int pairs = min(freq[lower_ch], freq[upper_ch]);
			ans += pairs;

			freq[lower_ch] -= pairs;
			freq[upper_ch] -= pairs;
			
			more += (freq[upper_ch] / 2) + (freq[lower_ch] / 2);
		}
		cout << ans + min(k, more) << el;
	}
}

