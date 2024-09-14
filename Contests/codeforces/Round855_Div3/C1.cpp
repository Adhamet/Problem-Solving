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

		ll armyPower = 0;
		priority_queue<ll> bonus;
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;

			if (x == 0) {
				if (!bonus.empty()) armyPower += bonus.top(), bonus.pop();
			} else bonus.push(x);
		}
		cout << armyPower << el;
	}
}

