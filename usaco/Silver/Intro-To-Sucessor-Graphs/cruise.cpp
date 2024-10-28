#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'
#define MAXN 1000
#define MOD 1000000007
using i64 = long long;
using pi = pair<int, int>;
void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

i64 k;
string str;
int n, m, l[MAXN], r[MAXN];
pair<i64, i64> get_next(pair<i64, i64> v) {
	return make_pair((str[v.second] == 'L' ? l: r)[v.first], (v.second + 1) % m); 
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	setIO("cruise");

	cin >> n >> m >> k;
	k *= m;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		l[i] -= 1, r[i] -= 1;
	}

	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		str += s;
	}

	pair<i64, i64> s0(0, 0), s1(0, 0);
	while (k > 0) {
		s0 = get_next(s0);
		s1 = get_next(get_next(s1));
		k -= 1;
		if (s0 == s1) break;
	}

	if (k) {
		int rho = 1;
		for (s0 = get_next(s0); s0 != s1; rho++) s0 = get_next(s0);
		k %= rho;
	}

	while (k > 0) s0 = get_next(s0), k -= 1;
	cout << s0.first + 1 << el;
	return 0;
}
