#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, x, y;
		cin >> n >> x >> y;

		vector<int> vec(x);
		for (auto &i: vec) cin >> i;
		sort(begin(vec), end(vec));
		
		vec.push_back(n + vec[0]);

		
		int vertices = n;
		
		for (int i = 0; i < x; i++) {
			if (vec[i + 1] - vec[i] >= 3) {
				vertices -= vec[i + 1] - vec[i] - 1;
			}
		}

		cout << vertices - 2 << el;
	}

	return 0;
}

