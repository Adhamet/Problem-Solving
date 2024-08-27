#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define el '\n'

const int N = 2e5 + 10;
// const int oo = 1e9 + 20;

inline int diff(string a, string b) {
	int cnt = 0;
	for (int i = 0; i < a.size(); i++) cnt += (a[i] != b[i]);
	return cnt;
}

int main() {
  	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<int> divisors[N];

	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j += i) {
			divisors[j].push_back(i);
		}
	}
	
	int t;
	cin >> t;

	while (t--) {
		int n;
		string s;
		cin >> n >> s;

		for (auto dv: divisors[n]) {
			string subs = s.substr(0, dv), t = "";
			for (int i = 0; i < n / dv; i++) t += subs;

			if (diff(s, t) <= 1) {
				cout << dv << el;
				break;
			}

			subs = s.substr(dv, dv), t = "";
			for (int i = 0; i < n / dv; i++) t += subs;

			if (diff(s, t) <= 1) {
				cout << dv << el;
				break;
			}
		}
	}
	
  	return 0;
}
