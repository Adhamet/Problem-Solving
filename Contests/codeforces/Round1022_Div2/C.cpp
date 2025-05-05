#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define pi pair<int, int>
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<pair<int, int>> nTbP(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			nTbP[i].first = a[i];
			nTbP[i].second = i + 1;
		}

		sort(nTbP.begin(), nTbP.end(), [](pi a, pi b) {
				if (a.first == b.first) return a.second < b.second;
				return a.first > b.first;
		});

		queue<int> q;
		int mx = nTbP[0].first;	
		q.push(nTbP[0].second);

		vector<bool> mark(n, false);
		int j = 1, taken, clones = 0;
		while (!q.empty()) {
			auto idx = q.front();
			q.pop();

			taken += 1;

			int k = 1;
			while (idx - k >= 0 || idx + k <= 0) {
				if (nTbP[idx + 1].first == a[nTbP[idx + 1].second - k] && !mark[idx-k]) mark[idx-k]=true, taken+=1;
				if (nTbP[idx + 1].first == a[nTbP[idx + 1].second + k] && !mark[idx+k]) mark[idx+k]=true, taken+=1;
				if (mark[idx-k] || mark[idx+k]) j+=1, k+=1;
			}

			j += 1;
			if (taken != n) q.push(nTbP[j].second), clones += 1;
		}

		cout << clones << el;
	}

	return 0;
}
