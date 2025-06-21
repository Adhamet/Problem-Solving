#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		map<int,int> freq;

		bool acc = false;
		freq[s[0]]++, freq[s[n-1]]++;
		for (int i = 1; i < n - 1; ++i) {
			freq[s[i]]++;
			if (freq[s[i]] > 1) {
				acc = true;
				break;
			}
		}

		cout << (acc? "Yes": "No") << el;
	}

	return 0;
}
