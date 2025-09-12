#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

i64 go(int idx, int &n, std::string& s) {
	if (idx == n) {
		int sm1 = 0, sm2 = 0;
		for (int i = 0; i < n/2; ++i) sm1 += (s[i] - '0');
		for (int i = n/2; i < n; ++i) sm2 += (s[i] - '0');
		return sm1 == sm2;
	}

	i64 cnt = 0;
	for (char c = '0'; c <= '9'; c++) {
		s[idx] = c;
		cnt += go(idx + 1, n, s);
	}

	return cnt;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n;	std::cin >> n;
	std::string s;
	for (int i = 0; i < n; ++i) s.push_back('0');
	std::cout << go(0, n, s);	
	
	return 0;
}
