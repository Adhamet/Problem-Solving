#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, sum, currSum = 0;
		cin >> n >> sum;

		int nn = n;
		while (nn > 0) currSum += (nn%10), nn/=10;

		if (currSum <= sum) {
			cout << 0 << el;
			continue;
		}

		string s = to_string(n), t = "0";
		t += s;

		int ans = 0;
		for (int i=0, m1=(int)s.size(); i < m1; ++i) {
			ans += s[i] - '0';
			if (ans >= sum) {
				for (int j=i+1, m2=(int)t.size(); j < m2; ++j) t[j] = '0';
				for (int j = i; j >= 0; --j) {
					if (t[j] == '9') t[j] = '0';
					else {
						t[j] += 1;
						break;
					}
				}

				break;
			}
		}

		int fst = stoll(s), scd = stoll(t);
		cout << scd - fst << el;
	}

	return 0;
}
