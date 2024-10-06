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
		int n, m, q;
		cin >> n >> m >> q;
		vector<int> a(n), b(m), c;
		for (auto &i: a) cin >> i;

		set<int> st;
		for (int i = 0; i < m; i++) {
			cin >> b[i];
			if (!st.count(b[i])) st.insert(b[i]), c.push_back(b[i]);
		}

		bool acc = true;
		for (int i = 0; i < c.size() && acc; i++) if (a[i] != c[i]) acc = false;
		cout << (acc ? "YA": "TIDAK") << el;
	}
	
	return 0;
}
