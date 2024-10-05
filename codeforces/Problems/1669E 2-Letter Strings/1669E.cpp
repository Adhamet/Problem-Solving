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

		vector<vector<int>> cnt(12, vector<int>(12, 0));
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;

			for (int j = 0; j < 2; j++) {
				for (char c = 'a'; c <= 'k'; c++) {
					if (c == s[j]) continue;
					string a = s;
					a[j] = c;
					ans += cnt[a[0] - 'a'][a[1] - 'a'];
				}
			}

			cnt[s[0] - 'a'][s[1] - 'a'] += 1;
		}

		cout << ans << el;
	}

	return 0;
}
