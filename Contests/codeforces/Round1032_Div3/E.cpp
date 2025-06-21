#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int f(const string &a, const string &b) {
	int cnt = 0;
	for (int i = 0; i < a.size(); i++) {
		cnt += (a[i] == b[i]);
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string l, r;
		cin >> l >> r;
		int n = l.size();
		int firstDiff = n;
		for (int i = 0; i < n; i++) {
			if (l[i] != r[i]) {
				firstDiff = i;
				break;
			}
		}

		int minScore = 1e9;

		// Try x = l and x = r explicitly
		minScore = min(minScore, f(l, l) + f(l, r));
		minScore = min(minScore, f(r, r) + f(r, l));

		// Try all digits in the firstDiff position from l[firstDiff] to r[firstDiff]
		for (char mid = l[firstDiff]; mid <= r[firstDiff]; mid++) {
			string x = l.substr(0, firstDiff) + mid;
			while (x.size() < n) x += '0'; // fill rest with 0s
			if (x >= l && x <= r) {
				minScore = min(minScore, f(l, x) + f(x, r));
			}
		}

		cout << minScore << el;
	}
	return 0;
}

