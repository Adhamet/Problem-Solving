#include <bits/stdc++.h>
using namespace std;
#define el '\n'
int main() {
	ios_base::sync_with_stdio(0), cin.tie(nullptr);
	unordered_map<char, string> mp = {
		{'0', ""}, {'1', ""}, {'2', "2"}, {'3', "3"}, {'4', "322"},
		{'5', "5"}, {'6', "53"}, {'7', "7"}, {'8', "7222"}, {'9', "7332"}
	};

	int n;
	string s, t;
	cin >> n >> s;
	for (char c: s) t += mp[c];
	sort(t.begin(), t.end(), greater<char>());
	cout << t;
	return 0;
}
