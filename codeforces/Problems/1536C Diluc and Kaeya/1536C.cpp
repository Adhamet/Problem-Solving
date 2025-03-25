#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define int int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		string s;
		cin >> n >> s;

		int32_t dcnt = 0, kcnt = 0;
		map<pair<int32_t, int32_t>, int64_t> ratioCnt;
		
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'D') dcnt++;
			else kcnt++;

			int32_t g = __gcd(dcnt, kcnt);
			pair<int32_t, int32_t> ratio = {dcnt / g, kcnt / g};

			ratioCnt[ratio]++;
			cout << ratioCnt[ratio] << " ";
		}
		
		cout << el;
	}

	return 0;
}
