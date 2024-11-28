#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	string s;
	cin >> s;
	int n = s.length();

	string ones = "", rest = "";
	for (char c: s) {
		if (c == '1') ones += c;
		else rest += c;
	}

	int pos = n;
	for (int i = 0; i < rest.length(); i++) {
		if (rest[i] == '2') {
			pos = i;
			break;
		}
	}

	string ans;
	if (pos == n) ans = rest + ones;
	else if (pos == 0) ans = ones + rest;
	else ans = rest.substr(0, pos) + ones + rest.substr(pos);
	cout << ans << el;
	return 0;
}
