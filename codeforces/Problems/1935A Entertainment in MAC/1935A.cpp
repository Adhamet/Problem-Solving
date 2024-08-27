#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define el '\n'
#define F first
#define S second

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;

		cin >> n >> s;

		string revS = s;
		reverse(revS.begin(), revS.end());
		
		if (revS < s) {
			revS += s;
			s = revS;
		}

		cout << s << el;
	}

	return 0;
}
