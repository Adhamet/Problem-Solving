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
		string s, t;
		cin >> s >> t;

		int ptr = 0, ans = 0;
		while (ptr < s.size() && ptr < t.size() && s[ptr] == t[ptr]) {
			ptr += 1, ans += 1;
		}

		if (ptr > 0) ans += 1;
		int ptr1 = ptr, ptr2 = ptr;
		while (ptr1 < s.size()) ptr1 += 1, ans += 1;
		while (ptr2 < t.size()) ptr2 += 1, ans += 1;
		cout << ans << el;
	}

	return 0;
}
