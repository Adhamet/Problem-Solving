#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string fres = "0";
	for (int i = 100; i <= 999; ++i) {
		for (int j = i; j <= 999; ++j) {
			int mlt = i * j;
			string cres = to_string(mlt);
			string rcres = cres;
			reverse(rcres.begin(), rcres.end());
			if (cres == rcres && mlt > stoi(fres)) {
				fres = cres;
			}
		}
	}
	cout << fres << el;
	return 0;
}

