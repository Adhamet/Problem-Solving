#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define el '\n'
#define F first
#define S second

// const int N = 36;
// const int oo = 1e9 + 7;

int main() { 
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		map<int, int> mp;

		for (int i = 0; i < s.size(); i++) mp[s[i]]++;

		if (mp['A'] > mp['B']) cout << "A" << el;
		else cout << "B" << el;
	}

	return 0;
}
