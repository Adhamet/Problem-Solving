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

		vector<int> a(n);
		for (auto &i: a) cin >> i;
	
		if (n == 1) {
			cout << a[0] + 1<< el;
			continue;
		}

		vector<int> evens, odds;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) evens.push_back(a[i]);
			else odds.push_back(a[i]);
		}

		int mxEven = *max_element(evens.begin(), evens.end());
		int mxOdd = *max_element(odds.begin(), odds.end());

		cout << max(mxEven + evens.size(), mxOdd + odds.size()) << el;
	}

	return 0;
}
