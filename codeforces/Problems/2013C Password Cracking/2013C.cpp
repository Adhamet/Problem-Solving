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
		int n;
		cin >> n;

		bool toTheLeft = true;
		string ans = "";
		for (int i = 0; i < n; i++) {
			bool feedback;

			if (toTheLeft) cout << "? 0" + ans << el;
			else cout << "? " + ans + "0" << el;
			cout.flush();

			cin >> feedback;
			if (feedback == 1) {
				if (toTheLeft) ans = "0" + ans;
				else ans = ans + "0";
			} else {
				if (toTheLeft) {
					cout << "? 1" + ans << el;
					cout.flush();

					cin >> feedback;
					if (feedback == 1) ans = "1" + ans;
					else toTheLeft = !toTheLeft, i -= 1;
				} else ans = ans + "1";
			}
		}

		cout << "! " << ans << el;
		cout.flush();
	}

	return 0;
}
