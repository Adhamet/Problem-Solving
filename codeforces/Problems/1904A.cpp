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
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		
		set<pi> st;
		st.insert({a,b}), st.insert({a, -b}), st.insert({-a, b}), st.insert({-a, -b});
		swap(a, b);
		st.insert({a,b}), st.insert({a, -b}), st.insert({-a, b}), st.insert({-a, -b});

		map<pi, int> mp1, mp2;
		for (auto [i, j]: st) {
			mp1[{i + c, d + j}] = 1;
			mp2[{i + e, f + j}] = 1;
		}

		int ans = 0;
		for (auto [p, w]: mp1) if (mp2.count(p)) ans += 1;
		cout << ans << el;
	}

	return 0;
}
