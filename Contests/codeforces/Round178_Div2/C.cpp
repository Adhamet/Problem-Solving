#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;

		vector<int> A, B;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'A') A.push_back(i + 1);
			else B.push_back(i + 1);
		}

		bool aliceWins = false;
		for (int i = 0; i < (int)A.size(); ++i) {
			bool acc = true;
			for (int j = 0; j < (int)B.size(); ++j) {
				if (A[i] == 1 && B[j] == n) continue;
				if (B[j] == 1 && A[i] == n) {
					acc = false;
					break;
				}

				if (A[i] <= B[j]) {
					acc = false;
					break;
				}
			}

			if (acc) {
				aliceWins = true;
				break;
			}
		}

		cout << (aliceWins ? "Alice" : "Bob") << el;
	}

	return 0;
}

