#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::string s;	std::cin >> s;
	int freq[26] = {0};
	for (char ch: s) freq[ch - 'a'] += 1;

	char bestChar = 'a';
	int bestCnt = 0;
	for (int i = 0; i < 26; ++i) {
		if (freq[i] > bestCnt) {
			bestCnt = freq[i];
			bestChar = 'a' + i;
		}
	}
	
	return std::cout << bestChar, 0;
}
