#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define el '\n'

// const int N = 500 + 10;
// const int oo = 1e9 + 20;

int main() {
  	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;

	while (t--) {
		string x, y;
		cin >> x >> y;

		int sz = (int)x.size();
		
		string larger = x > y? x: y;
		string smaller = x > y? y: x;

		bool findFirst = true;
		for (int i = 0; i < sz; i++) {
			if (findFirst && larger[i] != smaller[i]) {
				findFirst = false;
				continue;
			}
			
			if (larger[i] > smaller[i]) swap(larger[i], smaller[i]);
		}

		cout << larger << el << smaller << el;
	}
	
  	return 0;
}
