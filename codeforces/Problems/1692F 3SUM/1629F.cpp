#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			mp[x % 10] += 1;
		}

		vector<int> vec;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < min(mp[i], 3); j++) {
				vec.push_back(i);
			}
		}

		int m = vec.size();
		auto check = [&]() -> bool {
			for (int i = 0; i < m; i++) {
				for (int j = i + 1; j < m; j++) {
					for (int k = j + 1; k < m; k++) {
						if ((vec[i] + vec[j] + vec[k]) % 10 == 3) {
							return true;
						}
					}
				}
			}

			return false;
		};
		
		cout << (check() ? "YES" : "NO") << el;
	}

	return 0;
}
