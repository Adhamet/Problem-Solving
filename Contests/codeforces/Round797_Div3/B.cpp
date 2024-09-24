#include <bits/stdc++.h>
using namespace std;

#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n), b(n);
		for (auto &i: a) cin >> i;
		for (auto &i: b) cin >> i;
		
		int diff = -1, mxDiff = -1;
		bool acc = true;
		for (int i = 0; i < n; i++) {
			if (b[i] > a[i]) {
				acc = false;
				break;
			}

			if (b[i] != 0) {
				int currDiff = a[i] - b[i];
				
				if (diff == -1) diff = currDiff;
				else if (currDiff != diff) {
					acc = false; 
					break;
				}
			} else mxDiff = (mxDiff > a[i] - b[i]) ? mxDiff: a[i] - b[i];
		}

		if (!acc) {
			cout << "NO" << el;
		} else {
			if (diff == -1 || mxDiff <= diff) cout << "YES" << el;
			else cout << "NO" << el;
		}
	}

	return 0;
}
