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

		vector<int> a(n);
		for (auto &i: a) cin >> i;
		sort(a.begin(), a.end());

		map<int, int> freq;
		int l = 0, mx = 0, distinct = 0;
		for (int r = 0; r < n; ++r) {
			if (freq[a[r]] == 0) distinct++;
			freq[a[r]]++;

			while (distinct > k || (r > l && a[r] > a[r - 1] + 1)) {
			    freq[a[l]]--;
			    if (freq[a[l]] == 0) distinct--;
			    l++;
			}

            mx = max(mx, r - l + 1);
        }

		cout << mx << el;
	}

	return 0;
}
