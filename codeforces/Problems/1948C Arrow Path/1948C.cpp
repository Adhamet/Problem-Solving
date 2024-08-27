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
		int n;
		cin >> n;

		string str1, str2;
		cin >> str1 >> str2;

		bool pass = true;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) continue;

			if (str1[i] == '<') {
				if (i - 1 >= 0 && str2[i - 1] == '<') {
					pass = false;
					break;
				} else if (i + 1 < n && str2[i + 1] == '<') {
					pass = false;
					break;
				}
			}
		}

		if (pass) cout << "YES\n";
		else cout << "NO\n";
	}
	
  	return 0;
}
