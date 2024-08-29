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
		char num;
		cin >> n >> num;

		string s;
		cin >> s;

		bool acc = false;
		for (auto itr = s.begin(); itr != s.end(); itr++) {
			if (num > *itr) {
				acc = true;
				s.insert(itr, num);
				break;
			}
		}

		if (!acc) s.push_back(num);
		cout << s << el;
	}

	return 0;
}
