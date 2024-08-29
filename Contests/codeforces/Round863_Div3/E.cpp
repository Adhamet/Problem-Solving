#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int N = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;

		vector<int> a;

		while (n) {
			int digit = n % 9;
			if (digit >= 4) digit += 1;
			a.push_back(digit);
			n /= 9;
		}

		for (int i = a.size() - 1; i >= 0; i--) cout << a[i];
		cout << el;
	}

	return 0;
}
