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

	string pi = "3141592653589793238462643383279";
	while (t--) {
		string s;
		cin >> s;

		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != pi[i]) break;
			cnt += 1;
		}
		cout << cnt << el;
	}

	return 0;
}
