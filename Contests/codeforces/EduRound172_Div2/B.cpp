#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		map<int, int> freq;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			freq[v[i]]++;
		}
	
		vector<pair<int, int>> col(freq.begin(), freq.end());
		sort(col.begin(), col.end(), [](pair<int, int> a, pair<int, int> b) {
			return a.second > b.second;
		});
	
		set<int> takenByAlice;
		int Ascore = 0, turn = 0;
	
		for (auto &[color, count] : col) {
			while (count > 0) {
				if (turn == 0) {
					if (takenByAlice.find(color) == takenByAlice.end()) {
						Ascore++;
						takenByAlice.insert(color);
					}
	
					count--;
					if (count == 0) Ascore++;
				} else count--;
				turn = 1 - turn;
			}
		}

		cout << Ascore << el, 0;
	}

	return 0;
}
