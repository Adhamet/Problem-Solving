#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int k, sum = 1, freq[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	cin >> k;
	while (sum < k) {
		for (int i = 0; i < 10; ++i) {
			sum /= freq[i];
			freq[i] += 1;
			sum *= freq[i];
			if (sum >= k) break;
		}
	}

	string s = "codeforces";
	for (int i = 0; i < 10; ++i) cout << string(freq[i], s[i]);
	return 0;
}
