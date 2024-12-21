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
        int n, x;
        cin >> n;
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            cin >> x;
            freq[x] += 1;
        }

		priority_queue<pair<int, int>> pq;
		for (auto [x, y]: freq) pq.push({y, x});

		int op = n;
		while (pq.size() >= 2) {
			auto [cnt1, v1] = pq.top();
			pq.pop();
			auto [cnt2, v2] = pq.top();
			pq.pop();
			op -= 2;
			if (--cnt1) pq.push({cnt1, v1});
			if (--cnt2) pq.push({cnt2, v2});
		}

		cout << op << el;
	}

    return 0;
}
