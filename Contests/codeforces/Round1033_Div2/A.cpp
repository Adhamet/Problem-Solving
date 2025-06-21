#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int l[3], w[3];
		cin >> l[0] >> w[0] >> l[1] >> w[1] >> l[2] >> w[2];
		if (l[0]==l[1] && l[0]==l[2] && w[0]+w[1]+w[2] == l[0])
			cout << "YES" << el;
		else if (w[0]==w[1] && w[0]==w[2] && l[0]+l[1]+l[2] == w[0])
			cout << "YES" << el;
		else {
			bool acc = false;
			vector<int> id = {0,1,2};
			do {
				int a = id[0], b = id[1], c = id[2];
				if (l[a] == l[b]+l[c] && w[b]==w[c] && w[a]+w[b]==l[a]) {
					acc = true;
					break;
				}

				if (w[a] == w[b]+w[c] && l[b]==l[c] && l[a]+l[b]==w[a]) {
					acc = true;
					break;
				}
			} while (next_permutation(id.begin(), id.end()));

			cout << (acc ? "YES": "NO") << el;
		}
	}
	return 0;
}

