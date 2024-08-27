#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define el '\n'

// const int N = 2e5 + 10;
// const int oo = 1e9 + 20;

int main() {
  	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;

	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;

		int result = a, left = (b + c) % 3;

		if (left > c) {
			cout << "-1\n";
			continue;
		}

		result += (b + c) / 3;

		if (left) result += 1;

		cout << result << el;
	}
	
  	return 0;
}
