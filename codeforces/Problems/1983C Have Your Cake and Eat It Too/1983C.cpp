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
		ll n;
		cin >> n;

		ll val[3][n], tot = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < n; j++) {
				cin >> val[i][j];
				if (i == 0) tot += val[i][j];
			}
		}

		
		ll ord[3], ans[6];
		iota(ord, ord+3, 0);

		
		bool found = false;
		do {
			ll currEater = 0, piece = 0, sum = 0;
			vector<ll> vec;
			
			while (piece < n) {
				sum += val[ord[currEater]][piece];
				
				if (3 * sum >= tot) {
					vec.push_back(piece);
					currEater += 1;	
					sum = 0;
				}

				if (currEater == 3) break;
				
				piece += 1;
			}

			
			if (currEater == 3) {
				vec[2] = n - 1;

				ll lastPiece = 0;
				for (int i = 0; i < 3; i++) {
					ans[2 * ord[i]] = lastPiece;
					ans[2 * ord[i] + 1] = vec[i];

					lastPiece = vec[i] + 1;
				}

				for (int i = 0; i < 6; i++) cout << ans[i] + 1 << " ";
				cout << el;

				found = true;
				break;
			}
		} while (next_permutation(ord, ord+3));

		
		if (!found) cout << -1 << el;
	}
	
  	return 0;
}
