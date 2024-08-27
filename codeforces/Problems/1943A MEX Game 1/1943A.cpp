#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		map<int, int> f;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;

			f[x] += 1;
		}

		int mex = 0;
		while (f[mex]) {
			mex += 1;
		}

		set<int> st;
		for (int i = 0; i < mex; i++) {
			if (f[i] == 1) {
				st.insert(i);
			}	
		}

		if (!st.empty()) st.erase(st.begin());
		if (!st.empty()) mex = *st.begin();
		
		cout << mex << el;
	}

	return 0;
}
