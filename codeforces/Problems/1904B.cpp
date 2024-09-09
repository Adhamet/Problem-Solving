#include <bits/stdc++.h>
#include <numeric>
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

		vector<int> a(n);
		for (auto &i: a) cin >> i;

		vector<int> idc(n);
		iota(idc.begin(), idc.end(), 0);
		sort(begin(idc), end(idc), [&](int i, int j) { return a[i] < a[j]; });

		ll sum = accumulate(a.begin(), a.end(), 0ll);
		vector<int> ans(n);
		ans[idc.back()] = n - 1;
		for (int i = n - 2; i >= 0; i--) {
			sum -= a[idc[i + 1]];
			
			if (sum >= a[idc[i + 1]]) ans[idc[i]] = ans[idc[i + 1]];
			else ans[idc[i]] = i;
		}

		for (auto &a: ans) cout << a << " ";
		cout << el;
	}

	return 0;
}
