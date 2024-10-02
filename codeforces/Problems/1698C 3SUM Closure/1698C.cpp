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

		vector<int> pos, neg, a;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;

			if (x > 0) pos.push_back(x);
			else if (x < 0) neg.push_back(x);
			else if (a.size() < 2) a.push_back(x);
		}

		if (pos.size() > 2 || neg.size() > 2) {
			cout << "NO" << el;
			continue;
		}

		for (int i: pos) a.push_back(i);
		for (int i: neg) a.push_back(i);

		auto find_print_ans = [&]() {
			for (int i = 0; i < a.size(); i++) {
				for (int j = i + 1; j < a.size(); j++) {
					for (int k = j + 1; k < a.size(); k++) {
						bool ok = false;
						for (int l = 0; l < a.size(); l++) {
							if (a[i] + a[j] + a[k] == a[l]) ok = true;
						}

						if (!ok) {
							cout << "NO" << el;
							return;
						}
					}
				}
			}

			cout << "YES\n";
		};

		find_print_ans();
	}

	return 0;
}
