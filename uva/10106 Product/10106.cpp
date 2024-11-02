#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'
#define MOD 1000000007
using i64 = long long;
using pi = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string x, y;
	while (cin >> x >> y) {
		reverse(x.begin(), x.end());
		reverse(y.begin(), y.end());

		size_t n = x.size(), m = y.size();
		vector<int> answer(n + m, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int a = x[i] - '0';
				int b = y[j] - '0';
				answer[i + j] += a * b;

				if (answer[i + j] >= 10) {
					answer[i + j + 1] += (answer[i + j] / 10);
					answer[i + j] %= 10;
				}
			}
		}
		
		while (answer.size() > 1 && answer.back() == 0) answer.pop_back();
		for (int i = answer.size() - 1; i >= 0; i--) cout << answer[i];
		cout << el;
	}

	return 0;
}
