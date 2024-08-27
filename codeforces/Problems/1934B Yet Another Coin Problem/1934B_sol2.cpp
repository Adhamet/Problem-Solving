#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define el '\n'
#define F first
#define S second

int calcAns(int n) {
	int ans = 0;

	ans += n / 15;	n %= 15;
	ans += n / 6;	n %= 6;
	ans += n / 3;	n %= 3;
	ans += n;

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		if (n < 10) cout << calcAns(n) << el;
		else if (n < 20) cout << min(calcAns(n), calcAns(n - 10) + 1) << el;
		else cout << min({calcAns(n), calcAns(n - 10) + 1, calcAns(n - 20) + 2}) << el;
	}

	return 0;
}
