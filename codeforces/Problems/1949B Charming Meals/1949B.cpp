#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define el '\n'

// const int N = 2e5 + 10;
// const int oo = 1e9 + 20;

int main() {
  	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n), b(n);
		for (auto& i: a) cin >> i;
		for (auto& i: b) cin >> i;

		sort(begin(a), end(a));
		sort(begin(b), end(b));

		int ans = -1;
		for (int len = 0; len < n; len++) {
			int currAns = INT_MAX;
			
			for (int i = 0; i < n; i++) {
				currAns = min(currAns, abs(a[i] - b[(len + i) % n]));
			}

			ans = max(ans, currAns);		
		}

		cout << ans << el;
	}
	
  	return 0;
}
