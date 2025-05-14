#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int count(int x, int y) {
    if (x < y) return -1;
    int ops = 0;
    while (x > y) x /= 2, ops++;
    return x == y? ops: -1;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int curr = a[i];

        vector<int> candidates;
        while (true) {
            candidates.push_back(curr);
            if (curr == 0) break;
            curr /= 2;
        }

		for (auto& c: candidates) {
			vector<int> opList;
			for (int i = 0; i < n; ++i) {
				int ops = count(a[i], c);
				if (ops != -1) opList.push_back(ops);
			}

			if ((int)opList.size() >= k) {
				sort(opList.begin(), opList.end());
				int tot = accumulate(opList.begin(), opList.begin()+k, 0);
				ans = min(ans, tot);
			}
		}
	}

    return cout << ans, 0;
}
