#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
		map<int, int> freq;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i], freq[a[i]]++;

		bool acc = true;
		for (int i = 1; i <= n; ++i) {
			if (freq[i] == 1) {
				acc = false;
				break;
			}

			if (freq[i] == 0) continue;
			freq[i + 1] += freq[i] - 2;
			freq[i] = 2;
		}

		cout << (acc? "Yes": "No") << el;
	}

    return 0;
}
