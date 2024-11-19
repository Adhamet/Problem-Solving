#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define fst first
#define scd second
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(nullptr);

	string cs, xs;
	while (getline(cin, cs) && getline(cin, xs)) {
		ll value;

		stringstream sc(cs), sx(xs);
		vector<ll> c, x;
		while (sc >> value) c.push_back(value);
		while (sx >> value) x.push_back(value);

		for (int i = 0; i < x.size(); i++) {
			ll res = 0, pawa = 1;
			for (int j = c.size() - 1; j >= 0; j -= 1) res += c[j] * pawa, pawa *= x[i];
			cout << res << (i + 1 < x.size() ? ' ': el);
		}
	}
	
	return 0;
}
