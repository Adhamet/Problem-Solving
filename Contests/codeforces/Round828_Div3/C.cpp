#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		char c;
		string s;
		cin >> n >> c >> s;
		
		s += s;
		vector<int> green(2 * n, 2 * n);
		int lastGreen = 2*n;

		for (int i = 2 * n - 1; i >= 0; i--) {
			if (s[i] == 'g') lastGreen = i;
			green[i] = lastGreen - i;
		}

		int mxDist = 0;
		for (int i = 0; i < s.size(); i++) if (s[i] == c) {
			mxDist = max(mxDist, green[i]);
		}

		cout << mxDist << el;
	}

	return 0;
}
