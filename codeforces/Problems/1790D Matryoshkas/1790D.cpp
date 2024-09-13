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

		set<int> st;
		map<int, int> freq;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;

			st.insert(x), st.insert(x + 1);
			freq[x] += 1;
		}

		int last = 0, ans = 0;
		for (auto x: st) {
			ans += max(0, freq[x] - last);
			last = freq[x];
		}
		cout << ans << el;
	} 
}
