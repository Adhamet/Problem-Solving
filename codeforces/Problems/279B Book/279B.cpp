#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> books(n);
	for (auto &i: books) cin >> i;

	int l = 0, r = 0, sum = 0, ans = 0;
	while (l < n && r < n) {
		while (r < n) {
			sum += books[r++];

			if (sum > k) {
				sum -= books[--r];
				break;
			}
		}

		ans = max(ans, r - l);
		sum -= books[l++];
	}
	cout << ans << el;
	
	return 0;
}
