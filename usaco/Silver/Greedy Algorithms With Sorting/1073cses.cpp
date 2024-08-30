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

	int n;
	cin >> n;

	multiset<int> tops;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		auto itr = tops.upper_bound(x);
		if (itr != tops.end()) tops.erase(itr);
		tops.insert(x);
	}
	cout << tops.size();
	
	return 0;
}
