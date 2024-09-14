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
		int n, r, s;
		cin >> n >> s >> r;

		vector<int> ans(n);
		for (int i = 0; i < n - 1; i++) ans[i] = 1;

		ans[n - 1] = s - r;

		if (r >= n) ans[n - 2] += (r - n + 1);
		for (int i = ans.size() - 2; i > 0; i--) {
			if (ans[i] > ans[n - 1]) {
				ans[i - 1] += ans[i] - ans[n - 1]; 
				ans[i] = ans[n - 1];
			}
		}
		
		for (auto &i: ans) cout << i << " ";
		cout << el;
	}

	return 0;
}
