#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;

	vector<int> left;
	int pos = 0;
	for (char ch: t) {
		while (s[pos] != ch) pos += 1;
		left.push_back(pos);
		pos += 1;
	}

	vector<int> right;
	pos = n - 1;
	for (int i = m - 1; i >= 0; --i) {
		char ch = t[i];
		while (s[pos] != ch) pos -= 1;
		right.push_back(pos);
		pos -= 1;
	}

	reverse(right.begin(), right.end());

	int mxWidth = 0;
	for (int i = 0; i < m - 1; ++i) mxWidth = max(mxWidth, right[i+1]-left[i]);
	return cout << mxWidth, 0;
}
