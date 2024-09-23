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
		string text;
		cin >> text;

		int n;
		cin >> n;
		vector<string> strs(n);
		for (int i = 0; i < n; i++) cin >> strs[i];

		int ptr = 0;
		vector<pi> ans;
		while (ptr < text.length()) {
			bool found = false;
			int mxLen = 0, idx = -1, pos = -1;

			for (int i = 0; i <= ptr; i++) {
				for (int j = 0; j < n; j++) {
					int len = strs[j].length();
					if (i + len <= text.length() && text.substr(i, len) == strs[j] && i + len - ptr > mxLen) {
						found = true, mxLen = i + len - ptr;
						idx = j + 1, pos = i + 1;
					}
				}
			}

			if (found) ans.emplace_back(idx, pos), ptr += mxLen;
			else break;
		}

		if (ptr == text.length()) {
			cout << ans.size() << el;
			for (auto &pr : ans) cout << pr.first << " " << pr.second << el;
		} else cout << -1 << el;
	}

	return 0;
}
