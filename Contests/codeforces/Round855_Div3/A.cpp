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

		for (auto &c: s) c = tolower(c);
		
		string filter;
		filter.push_back(s[0]);
		for (int i = 1; i < n; i++) if (s[i] != s[i - 1]) filter.push_back(s[i]);

		if (filter == "meow") {
			cout << "YES" << el;
		} else cout << "NO" << el;
	}
}

