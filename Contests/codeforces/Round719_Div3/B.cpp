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

	vector<int> ord;
	for (int dig = 1; dig <= 9; dig++) {
		ll num = 0;
		for (int len = 1; len <= 10; len++) {
			num = num * 10 + dig;
			if (num > 1e9) break;
			ord.push_back(num);
		}
	}

	sort(ord.begin(), ord.end());
	
	int t;
	cin >> t;

	while (t--) {
		int n, ans = 0;
		cin >> n;
		for (auto num: ord) {
				if (num <= n) ans += 1;
				else break;
		}
		
		cout << ans << el;
	}
	
	return 0;
}
