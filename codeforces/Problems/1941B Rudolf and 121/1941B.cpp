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
		int n;
		cin >> n;

		ll arr[n];
		for (auto &i: arr) cin >> i;

		for (int i = 0; i < n - 2; i++) {
			if (arr[i] < 0) {
				cout << "NO\n";
				goto done;
			}

			arr[i + 1] -= arr[i] * 2;
			arr[i + 2] -= arr[i];
			arr[i] = 0;
		}

		for (auto ele: arr) if (ele != 0) {
			cout << "NO\n";
			goto done;
		}

		cout << "YES\n";
		
		done: {};
	}

	return 0;
}
